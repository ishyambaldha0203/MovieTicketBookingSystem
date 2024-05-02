/*************************************************************************************************
 * @file BookingManager.cpp
 *
 * @brief Concrete implementation of @ref BookingManager class.
 *************************************************************************************************/

#include "Internal/BookingManager.hpp"

#include <algorithm>
#include <future>
#include <thread>

#include "Exceptions/XArgumentNull.hpp"
#include "Exceptions/XBaseException.hpp"

// #region Namespace Symbols

using namespace MOVIE_TICKET_BOOKING_NS::Exceptions;
using namespace MOVIE_TICKET_BOOKING_NS::EntityInterfaces;
using namespace MOVIE_TICKET_BOOKING_NS::FactoryInterfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Interfaces;

// #endregion

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    // #region Construction/Destruction

    BookingManager::BookingManager(std::shared_ptr<ITheaterControllerFactory> theaterControllerFactory)
        : _theaterControllerFactory(theaterControllerFactory)
    {
        // Nothing to do for now.
    }

    BookingManager::~BookingManager() = default;

    // #endregion

    // #region Public Methods

    BookingManager::SeatList BookingManager::FindAvailableSeats(std::shared_ptr<ITheater> theater,
                                                                std::shared_ptr<IMovie> movie) const
    {
        // Get the theater controller
        std::shared_ptr<ITheaterController> theaterController = GetTheaterController(theater);

        return theaterController->FetchAvailableSeats(movie);
    }

    std::shared_ptr<EntityInterfaces::IMovie> BookingManager::GetMovieEntity(const std::string &movieId) const
    {
        // Find the movie in the theater.
        decltype(_runningMovies)::const_iterator movieIt = std::find_if(_runningMovies.begin(), _runningMovies.end(),
                                                                        [&movieId](const auto &movie)
                                                                        {
                                                                            return movie->GetName() == movieId;
                                                                        });

        if (movieIt == _runningMovies.end())
        {
            throw std::runtime_error("Movie entity not found with movie ID: " + movieId);
        }

        return *movieIt;
    }

    void BookingManager::DoBookSeats(std::shared_ptr<ITheater> theater,
                                     std::shared_ptr<IMovie> movie,
                                     const std::vector<std::string> &seatIds)
    {
        // Check for the theater and get its controller.
        std::shared_ptr<ITheaterController> theaterController = GetTheaterController(theater);

        theaterController->DoBookSeats(movie, seatIds);
    }

    BookingManager::TheaterList BookingManager::FindTheaters(const std::shared_ptr<IMovie> movie) const
    {
        TheaterList theaterList;

        for (const auto &theater : _registeredTheaters)
        {
            std::shared_ptr<ITheaterController> theaterController = theater.second;

            const std::vector<std::shared_ptr<IMovie>> &moviesAtTheater = theaterController->FetchMovies();

            std::vector<std::shared_ptr<IMovie>>::const_iterator movieItr =
                std::find(moviesAtTheater.begin(), moviesAtTheater.end(), movie);

            if (movieItr != moviesAtTheater.end())
            {
                theaterList.push_back(theater.first);
            }
        }

        return theaterList;
    }

    BookingManager::MovieList BookingManager::GetRunningMovies() const
    {
        return std::vector<std::shared_ptr<EntityInterfaces::IMovie>>(_runningMovies.begin(), _runningMovies.end());
    }

    std::shared_ptr<ITheater> BookingManager::GetTheaterEntity(const std::string &theaterId) const
    {
        // Find the theater using in the theater id from the list of registered theaters.
        decltype(_registeredTheaters)::const_iterator theaterIt = std::find_if(_registeredTheaters.begin(), _registeredTheaters.end(),
                                                                               [&theaterId](const auto &theaterPair)
                                                                               {
                                                                                   return theaterPair.first->GetName() == theaterId;
                                                                               });

        if (theaterIt == _registeredTheaters.end())
        {
            throw std::runtime_error("Theater not found with theater ID: " + theaterId);
        }

        return theaterIt->first;
    }

    void BookingManager::RegisterNewMovie(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                          std::shared_ptr<EntityInterfaces::IMovie> movie)
    {
        // Booking manager is keeping the reference of all the movies in system.
        _runningMovies.insert(movie);

        // Check for the theater and get its controller.
        std::shared_ptr<ITheaterController> theaterController = GetTheaterController(theater);
        theaterController->AddMovie(movie);
    }

    void BookingManager::RegisterNewTheater(std::shared_ptr<ITheater> theater)
    {
        if (nullptr == theater)
        {
            throw std::runtime_error("Theater entity is null");
        }

        // Create a theater controller for newly added theater.
        std::shared_ptr<ITheaterController> controller;
        _theaterControllerFactory->Create(controller);

        _registeredTheaters[theater] = controller;

        _registeredTheaters[theater]->SetTheaterSeatCapacity(theater->GetSeatingCapacity());
    }

    // #endregion

    // #region Private Methods

    std::shared_ptr<ITheaterController> BookingManager::GetTheaterController(std::shared_ptr<ITheater> theater) const
    {
        // Find the theater controller associated with the theater.
        decltype(_registeredTheaters)::const_iterator theaterControllerIt = _registeredTheaters.find(theater);
        if (theaterControllerIt == _registeredTheaters.end())
        {
            throw std::runtime_error("Theater not registered: " + theater->GetName());
        }

        // Get the theater controller
        return theaterControllerIt->second;
    }

    // #endregion

} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS