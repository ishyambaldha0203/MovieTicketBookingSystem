/*************************************************************************************************
 * @file TheaterController.hpp
 *
 * @brief Declarations for the concrete class @ref TheaterController.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_THEATERCONTROLLER_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_THEATERCONTROLLER_HPP

#include "CommonConfig.hpp"

#include <mutex>
#include <vector>
#include <unordered_map>

#include "Interfaces/ITheaterController.hpp"
#include "Interfaces/Factories/ISeatFactory.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    /**
     * @class TheaterController
     *
     * @brief Concrete implementation of theater controller.
     */
    class TheaterController : public Interfaces::ITheaterController
    {
        using IMovie = EntityInterfaces::IMovie;
        using ISeat = EntityInterfaces::ISeat;
        using SeatList = Interfaces::ITheaterController::SeatList;

    public:
        // #region Construction/Destruction

        /**
         * @brief  Construct a new booking manager object.
         *
         * @param seatFactory Factory to create seats of theater.
         */
        TheaterController(std::shared_ptr<FactoryInterfaces::ISeatFactory> seatFactory);

        /**
         * @brief Destroy the booking manager object.
         */
        virtual ~TheaterController() override;

        // #endregion

        // #region TheaterController Implementation

        virtual void AddMovie(std::shared_ptr<IMovie> movie) override;

        virtual void DoBookSeats(std::shared_ptr<IMovie> movie,
                                 const std::vector<std::string> &seatIds) override;

        virtual std::shared_ptr<IMovie> GetMovieEntity(const std::string &movieId) const override;

        virtual SeatList FetchAvailableSeats(std::shared_ptr<IMovie> movie) const override;

        virtual MovieList FetchMovies() const override;

        virtual void SetTheaterSeatCapacity(uint32_t seatCapacity) override;
        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(TheaterController)

        // #region Private Members

        /**
         * @brief List of movies mapped with all the seats.
         */
        std::unordered_map<std::shared_ptr<IMovie>, SeatList> _movieSeatMapping;

        /**
         * @brief Lock for synchronization.
         */
        std::mutex _mutex;

        /**
         * @brief Factory to create seats of theater.
         */
        std::shared_ptr<FactoryInterfaces::ISeatFactory> _seatFactory;

        /**
         * @brief Total number of seats in a theater.
         */
        uint32_t _seatCapacity;

        // #endregion

        std::vector<std::shared_ptr<ISeat>> InitializeSeats(uint32_t numberOfSeats);

        bool IsMovieRunning(std::shared_ptr<IMovie> movie) const;
    };
} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_THEATERCONTROLLER_HPP
