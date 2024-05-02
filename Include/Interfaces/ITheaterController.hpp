/*************************************************************************************************
 * @file ITheaterController.hpp
 *
 * @brief Interface to define member contracts to manage all the operations of a theater.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ITHEATERCONTROLLER_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ITHEATERCONTROLLER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IMovie.hpp"
#include "Interfaces/Entities/ISeat.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Interfaces
{
    /**
     * @interface ITheaterController
     *
     * @brief Interface to define member contracts and operations to manage a theater.
     */
    interface ITheaterController
    {
        DECLARE_INTERFACE_DEFAULTS(ITheaterController)

        using SeatList = std::vector<std::shared_ptr<EntityInterfaces::ISeat>>;
        using MovieList = std::vector<std::shared_ptr<EntityInterfaces::IMovie>>;

        /**
         * @brief Add movie to theater.
         *
         * @param movie Movie to be added in a theater.
         */
        virtual void AddMovie(std::shared_ptr<EntityInterfaces::IMovie> movie) = 0;

        /**
         * @brief Book the seat in provided theater for the provided movie.
         *
         * @param movie Movie to book for.
         * @param seats Number of seats to do the booking.
         */
        virtual void DoBookSeats(std::shared_ptr<EntityInterfaces::IMovie> movie,
                                 const std::vector<std::string> &seatIds) = 0;

        /**
         * @brief Get the Movie Entity associated with unique movie ID.
         *
         * @param movieId Unique movie ID.
         *
         * @return Existing Movie Entity that associated with provided movie ID.
         */
        virtual std::shared_ptr<EntityInterfaces::IMovie> GetMovieEntity(const std::string &movieId) const = 0;

        /**
         * @brief Find all the available seats in a theater for the provided movie.
         *
         * @param movie Movie running in a theater to search seat for.
         *
         * @return List of all available seat.
         */
        virtual SeatList FetchAvailableSeats(std::shared_ptr<EntityInterfaces::IMovie> movie) const = 0;

        /**
         * @brief Get list of all the movies running in a theater.
         *
         * @return List of currently running movies.
         */
        virtual MovieList FetchMovies() const = 0;

        /**
         * @brief Set the theater seat capacity for controller to operate on.
         *
         * @param seatCapacity Total number of seats in a theater.
         */
        virtual void SetTheaterSeatCapacity(uint32_t seatCapacity) = 0;
    };
} // namespace Interfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ITHEATERCONTROLLER_HPP