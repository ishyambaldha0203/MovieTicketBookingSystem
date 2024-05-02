/*************************************************************************************************
 * @file MovieTicketBookingSystem.cpp
 *
 * @brief Concrete implementation of @ref MovieTicketBookingSystem class.
 *
 * It handles Ticket Booking System's start-up rituals.
 *************************************************************************************************/

#include "MovieTicketBookingSystem.hpp"

#include "Internal/ObjectFactory.hpp"
#include "Enums/SeatStatus.hpp"
#include "Interfaces/Entities/IMovie.hpp"
#include "Interfaces/Entities/ITheater.hpp"
#include "Exceptions/XArgumentNull.hpp"

// #region Namespace Symbols

using namespace MOVIE_TICKET_BOOKING_NS::Internal;
using namespace MOVIE_TICKET_BOOKING_NS::Interfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Enums;
using namespace MOVIE_TICKET_BOOKING_NS::EntityInterfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Exceptions;
using namespace MOVIE_TICKET_BOOKING_NS::FactoryInterfaces;

// #endregion

namespace Defaults
{
    constexpr uint32_t TheaterSeatingCapacity = 20;
    constexpr SeatStatus TheaterSeatStatus = SeatStatus::Available;
}

// #region Construction/Destruction

MovieTicketBookingSystem::MovieTicketBookingSystem()
{
    // Creat the common object factory that own all the objects created for the application.
    _commonObjectFactory = std::make_shared<ObjectFactory>();

    // Create the BookingManager.
    _commonObjectFactory->Create(_bookingManager);
}

MovieTicketBookingSystem::~MovieTicketBookingSystem() = default;

// #endregion

// #region Public Methods

bool MovieTicketBookingSystem::AddMovie(const std::string &theaterId, const std::string &movieId)
{
    std::shared_ptr<IMovie> movieEntity;

    try
    {
        // Movie already exist not need to create new.
        movieEntity = _bookingManager->GetMovieEntity(movieId);
    }
    catch (const std::exception &)
    {
        // Create new movie entity for new movie in system.
        movieEntity = std::move(_commonObjectFactory->Create(movieId));
    }

    try
    {
        std::shared_ptr<ITheater> theaterEntity = _bookingManager->GetTheaterEntity(theaterId);
        _bookingManager->RegisterNewMovie(theaterEntity, movieEntity);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';

        return false;
    }

    return true;
}

bool MovieTicketBookingSystem::AddTheater(const std::string &theaterName, uint32_t seatingCapacity)
{
    try
    {
        // Create entity from raw data.
        std::shared_ptr<ITheater> theaterEntity =
            std::move(_commonObjectFactory->Create(theaterName, seatingCapacity));

        _bookingManager->RegisterNewTheater(theaterEntity);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';

        return false;
    }

    return true;
}

bool MovieTicketBookingSystem::DoReserveSeats(const std::string &theaterId,
                                              const std::string &movieId,
                                              const std::vector<std::string> &seatIds)
{
    try
    {
        std::shared_ptr<ITheater> theaterEntity = _bookingManager->GetTheaterEntity(theaterId);
        std::shared_ptr<IMovie> movieEntity = _bookingManager->GetMovieEntity(movieId);

        std::vector<std::shared_ptr<ISeat>> availableSeatList =
            _bookingManager->FindAvailableSeats(theaterEntity, movieEntity);

        _bookingManager->DoBookSeats(theaterEntity, movieEntity, seatIds);
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';

        return false;
    }

    return true;
}

std::vector<std::string> MovieTicketBookingSystem::GetAvailableSeats(const std::string &theaterId,
                                                                     const std::string &movieId)
{
    std::vector<std::string> seatList;

    try
    {
        std::shared_ptr<ITheater> theaterEntity = _bookingManager->GetTheaterEntity(theaterId);
        std::shared_ptr<IMovie> movieEntity = _bookingManager->GetMovieEntity(movieId);

        std::vector<std::shared_ptr<ISeat>> availableSeatList =
            _bookingManager->FindAvailableSeats(theaterEntity, movieEntity);

        for (std::shared_ptr<ISeat> seat : availableSeatList)
        {
            seatList.push_back(seat->GetId());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return seatList;
}

std::vector<std::string> MovieTicketBookingSystem::GetRunningMovies()
{
    std::vector<std::string> movieList;

    std::vector<std::shared_ptr<IMovie>> internalMovieList = _bookingManager->GetRunningMovies();

    for (std::shared_ptr<IMovie> movie : internalMovieList)
    {
        movieList.push_back(movie->GetName());
    }

    return movieList;
}

std::vector<std::string> MovieTicketBookingSystem::GetTheaters(const std::string &movieId)
{
    std::vector<std::string> theaterList;

    try
    {
        std::shared_ptr<IMovie> movieEntity = _bookingManager->GetMovieEntity(movieId);

        std::vector<std::shared_ptr<ITheater>> internalTheaterList =
            _bookingManager->FindTheaters(movieEntity);

        for (std::shared_ptr<ITheater> theater : internalTheaterList)
        {
            theaterList.push_back(theater->GetName());
        }
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
    }

    return theaterList;
}

// #endregion
