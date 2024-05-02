/*************************************************************************************************
 * @file IBookingManager.hpp
 *
 * @brief Interface to define member contracts to manage a movie ticket booking system.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_IBOOKINGMANAGER_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_IBOOKINGMANAGER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IMovie.hpp"
#include "Interfaces/Entities/ITheater.hpp"
#include "Interfaces/Entities/ISeat.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Interfaces
{
    /**
     * @interface IBookingManager
     *
     * @brief Interface to define member contracts and operations to manage a movie ticket booking system.
     */
    interface IBookingManager
    {
        DECLARE_INTERFACE_DEFAULTS(IBookingManager)

        using MovieList = std::vector<std::shared_ptr<EntityInterfaces::IMovie>>;
        using TheaterList = std::vector<std::shared_ptr<EntityInterfaces::ITheater>>;
        using SeatList = std::vector<std::shared_ptr<EntityInterfaces::ISeat>>;

        /**
         * @brief Book the seat in provided theater for the provided movie.
         *
         * @param theater Theater to book the ticket.
         * @param movie Movie to book for.
         * @param seats Number of seats to do the booking.
         */
        virtual void DoBookSeats(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                 std::shared_ptr<EntityInterfaces::IMovie> movie,
                                 const std::vector<std::string> &seatIds) = 0;

        /**
         * @brief Find all the available seats in a theater for the provided movie.
         *
         * @param theater Theater to find for.
         * @param movie Movie running in a theater to search seat for.
         * @return List of all available seat.
         */
        virtual SeatList FindAvailableSeats(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                            std::shared_ptr<EntityInterfaces::IMovie> movie) const = 0;

        /**
         * @brief Find all the theater at which the provided movie is running.
         *
         * @param movie A movie to search for theaters.
         *
         * @return List of all resultant theaters.
         */
        virtual TheaterList FindTheaters(std::shared_ptr<EntityInterfaces::IMovie> movie) const = 0;

        /**
         * @brief Get the Theater Entity object from its id.
         *
         * @param movieId An unique movie ID.
         *
         * @return A @ref Movie entity associated with theater ID.
         */
        virtual std::shared_ptr<EntityInterfaces::IMovie> GetMovieEntity(const std::string &movieId) const = 0;

        /**
         * @brief Get the list of all the currently running movies.
         *
         * @return List of @ref Movie.
         */
        virtual MovieList GetRunningMovies() const = 0;

        /**
         * @brief Get the Theater Entity object from its id.
         *
         * @param theaterId An unique theater ID.
         *
         * @return A @ref Theater entity associated with theater ID.
         */
        virtual std::shared_ptr<EntityInterfaces::ITheater> GetTheaterEntity(const std::string &theaterId) const = 0;

        /**
         * @brief Register new movie with requested theater in booking system.
         *
         * @param theater Theater to register with.
         * @param movie New movie.
         */
        virtual void RegisterNewMovie(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                      std::shared_ptr<EntityInterfaces::IMovie> movie) = 0;

        /**
         * @brief Register new theater into booking system.
         *
         * @param theater Theater to register.
         */
        virtual void RegisterNewTheater(std::shared_ptr<EntityInterfaces::ITheater> theater) = 0;
    };
} // namespace Interfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_IBOOKINGMANAGER_HPP