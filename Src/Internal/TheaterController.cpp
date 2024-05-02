/*************************************************************************************************
 * @file TheaterController.cpp
 *
 * @brief Concrete implementation of @ref TheaterController class.
 *************************************************************************************************/

#include "Internal/TheaterController.hpp"

#include <algorithm>
#include <future>
#include <thread>

#include "Interfaces/Entities/ISeatMutable.hpp"
#include "Enums/SeatStatus.hpp"

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace MOVIE_TICKET_BOOKING_NS::Exceptions;
using namespace MOVIE_TICKET_BOOKING_NS::Enums;
using namespace MOVIE_TICKET_BOOKING_NS::EntityInterfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Interfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Enums;

// #endregion

namespace Defaults
{
    constexpr uint32_t SeatingCapacity = 20;
    constexpr SeatStatus SeatStatusByDefault = SeatStatus::Available;
}

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    // #region Construction/Destruction

    TheaterController::TheaterController(std::shared_ptr<FactoryInterfaces::ISeatFactory> seatFactory)
        : _seatFactory(seatFactory)
    {
        _seatCapacity = Defaults::SeatingCapacity;
    }

    TheaterController::~TheaterController() = default;

    // #endregion

    // #region Public Methods

    void TheaterController::AddMovie(std::shared_ptr<IMovie> movie)
    {
        // Add movie to this theater.
        _movieSeatMapping[movie] = this->InitializeSeats(_seatCapacity);
    }

    void TheaterController::DoBookSeats(std::shared_ptr<IMovie> movie,
                                        const std::vector<std::string> &seatIds)
    {
        std::lock_guard<std::mutex> lock(_mutex);

        // Check if Movie the movie in the theater.
        if (!IsMovieRunning(movie))
        {
            // Movie not found in the theater.
            throw std::runtime_error("Movie not found in the theater: " + movie->GetName());
        }

        // Get the list of available seats.
        TheaterController::SeatList availableSeats = this->FetchAvailableSeats(movie);

        // Check each requested seats against available and boot it if available.
        for (const std::string &requestedSeatId : seatIds)
        {
            // Find the seat in the available seats for the movie
            decltype(availableSeats)::iterator seatIt = std::find_if(availableSeats.begin(), availableSeats.end(),
                                                                     [&requestedSeatId](const std::shared_ptr<ISeat> seat)
                                                                     {
                                                                         return requestedSeatId == seat->GetId() && seat->GetStatus() == SeatStatus::Available;
                                                                     });

            if (seatIt == availableSeats.end())
            {
                throw std::runtime_error("Requested seat is not available: " + requestedSeatId);
            }

            // Seat is available for booking; Book it.
            std::shared_ptr<ISeatMutable> seatMutable =
                std::static_pointer_cast<ISeatMutable>(*seatIt);

            seatMutable->SetStatus(SeatStatus::Reserved);
        }
    }

    TheaterController::SeatList TheaterController::FetchAvailableSeats(std::shared_ptr<IMovie> movie) const
    {
        TheaterController::SeatList availableSeats;

        // Check if movie is running.
        if (!IsMovieRunning(movie))
        {
            throw std::runtime_error("Movie not found in the theater: " + movie->GetName());
        }

        // Get available seats for the movie.
        for (const std::shared_ptr<ISeat> &seat : _movieSeatMapping.at(movie))
        {
            if (seat->GetStatus() == SeatStatus::Available)
            {
                availableSeats.push_back(seat);
            }
        }

        return availableSeats;
    }

    TheaterController::MovieList TheaterController::FetchMovies() const
    {
        TheaterController::MovieList movieList;

        for (const auto &pair : _movieSeatMapping)
        {
            movieList.push_back(pair.first);
        }

        return movieList;
    }

    std::shared_ptr<IMovie> TheaterController::GetMovieEntity(const std::string &movieId) const
    {
        // Find the movie entity using movie id from all the running movie in a theater.
        decltype(_movieSeatMapping)::const_iterator theaterIt = std::find_if(_movieSeatMapping.begin(), _movieSeatMapping.end(),
                                                                             [&movieId](const auto &moviePair)
                                                                             {
                                                                                 return moviePair.first->GetName() == movieId;
                                                                             });

        if (theaterIt == _movieSeatMapping.end())
        {
            throw std::runtime_error("Movie not found with movie ID: " + movieId);
        }

        return theaterIt->first;
    }

    void TheaterController::SetTheaterSeatCapacity(uint32_t seatCapacity)
    {
        _seatCapacity = seatCapacity;
    }

    // #endregion

    // #region Private Methods

    std::vector<std::shared_ptr<ISeat>> TheaterController::InitializeSeats(uint32_t numberOfSeats)
    {
        std::vector<std::shared_ptr<ISeat>> seats;

        for (uint32_t itr = 0; itr < numberOfSeats; itr++)
        {
            std::shared_ptr<ISeat> seat =
                _seatFactory->Create(std::to_string(itr + 1), Defaults::SeatStatusByDefault);

            std::shared_ptr<ISeatMutable> seatMutable = std::static_pointer_cast<ISeatMutable>(seat);
            seatMutable->SetStatus(SeatStatus::Available);

            seats.push_back(std::move(seat));
        }

        return seats;
    }

    bool TheaterController::IsMovieRunning(std::shared_ptr<IMovie> movie) const
    {
        decltype(_movieSeatMapping)::const_iterator it = _movieSeatMapping.find(movie);
        if (it == _movieSeatMapping.end())
        {
            return false; // Movie not found.
        }

        return true;
    }

} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS