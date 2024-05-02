/*************************************************************************************************
 * @file BookingManager.hpp
 *
 * @brief Declarations for the concrete class @ref BookingManager.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_BOOKINGMANAGER_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_BOOKINGMANAGER_HPP

#include "CommonConfig.hpp"

#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Interfaces/IBookingManager.hpp"
#include "Interfaces/ITheaterController.hpp"
#include "Interfaces/Factories/IObjectFactories.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    /**
     * @class BookingManager
     *
     * @brief Concrete implementation of booking manager.
     */
    class BookingManager : public Interfaces::IBookingManager
    {
        using ITheaterController = Interfaces::ITheaterController;
        using IMovie = EntityInterfaces::IMovie;
        using ITheater = EntityInterfaces::ITheater;
        using MovieList = Interfaces::IBookingManager::MovieList;
        using TheaterList = Interfaces::IBookingManager::TheaterList;
        using SeatList = Interfaces::IBookingManager::SeatList;

    public:
        // #region Construction/Destruction

        /**
         * @brief  Construct a new booking manager object.
         *
         * It is the main manager class for ticket booking system.
         */
        BookingManager(std::shared_ptr<FactoryInterfaces::ITheaterControllerFactory> theaterControllerFactory);

        /**
         * @brief Destroy the booking manager object.
         */
        virtual ~BookingManager() override;

        // #endregion

        // #region IBookingManager Implementation

        virtual void DoBookSeats(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                 std::shared_ptr<EntityInterfaces::IMovie> movie,
                                 const std::vector<std::string> &seatIds) override;

        virtual SeatList FindAvailableSeats(std::shared_ptr<ITheater> theater,
                                            std::shared_ptr<IMovie> movie) const override;

        virtual TheaterList FindTheaters(std::shared_ptr<IMovie> movie) const override;

        virtual std::shared_ptr<EntityInterfaces::IMovie> GetMovieEntity(const std::string &movieId) const override;

        virtual MovieList GetRunningMovies() const override;

        virtual std::shared_ptr<EntityInterfaces::ITheater> GetTheaterEntity(const std::string &theaterId) const override;

        virtual void RegisterNewMovie(std::shared_ptr<EntityInterfaces::ITheater> theater,
                                      std::shared_ptr<EntityInterfaces::IMovie> movie) override;

        virtual void RegisterNewTheater(std::shared_ptr<EntityInterfaces::ITheater> theater) override;
        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(BookingManager)

        // #region Private Members

        /**
         * @brief Factory to create controller for each theater.
         */
        std::shared_ptr<FactoryInterfaces::ITheaterControllerFactory> _theaterControllerFactory;

        /**
         * @brief Set of all movies running across theaters.
         */
        std::unordered_set<std::shared_ptr<IMovie>> _runningMovies;

        /**
         * @brief All the theater registered with the booking system,
         */
        std::unordered_map<std::shared_ptr<ITheater>, std::shared_ptr<ITheaterController>> _registeredTheaters;

        // #endregion

        // #region Private Members

        std::shared_ptr<ITheaterController> GetTheaterController(std::shared_ptr<ITheater> theater) const;

        // #endregion
    };
} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_BOOKINGMANAGER_HPP
