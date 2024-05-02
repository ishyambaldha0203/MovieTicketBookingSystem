/*************************************************************************************************
 * @file MovieTicketBookingSystem.hpp
 *
 * @brief Declarations for the concrete class @ref MovieTicketBookingSystem.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_PROGRAM_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_PROGRAM_HPP

#include <vector>

#include "Interfaces/IBookingManager.hpp"
#include "Internal/ObjectFactory.hpp"

/**
 * @class MovieTicketBookingSystem
 *
 * @brief Concrete implementation of MovieTicketBookingSystem.
 */
class MovieTicketBookingSystem
{
    using IBookingManager = MOVIE_TICKET_BOOKING_NS::Interfaces::IBookingManager;
    using ObjectFactory = MOVIE_TICKET_BOOKING_NS::Internal::ObjectFactory;

public:
    // #region Construction/Destruction

    /**
     * @brief Construct a new MovieTicketBookingSystem object.
     */
    MovieTicketBookingSystem();

    /**
     * @brief Destroy the MovieTicketBookingSystem object.
     */
    ~MovieTicketBookingSystem();

    // #endregion

    // #region Public Methods

    /**
     * @brief Add a new movie to the system.
     *
     * @param theaterName The name of the theater where the movie is being added.
     * @param movieId The ID of the new movie.
     * @return True if the movie was successfully added, false otherwise.
     */
    bool AddMovie(const std::string &theaterName, const std::string &movieId);

    /**
     * @brief Add a new theater to the system.
     *
     * @param theaterName The name of the new theater.
     * @param seatingCapacity The seating capacity of the new theater.
     * @return True if the theater was successfully added, false otherwise.
     */
    bool AddTheater(const std::string &theaterName, uint32_t seatingCapacity);

    /**
     * @brief Reserve seats for a specific movie at a specific theater.
     *
     * @param theater The name of the theater.
     * @param movie The name of the movie.
     * @param seats A vector of strings containing the seat numbers to reserve.
     * @return True if the seats were successfully reserved, false otherwise.
     */
    bool DoReserveSeats(const std::string &theater, const std::string &movie, const std::vector<std::string> &seats);

    /**
     * @brief Get the list of available seats for a specific movie at a specific theater.
     *
     * @param theater The name of the theater.
     * @param movie The name of the movie.
     * @return A vector of strings containing the available seat numbers.
     */
    std::vector<std::string> GetAvailableSeats(const std::string &theater, const std::string &movie);

    /**
     * @brief Get the list of running movies.
     *
     * @return A vector of strings containing the names of running movies.
     */
    std::vector<std::string> GetRunningMovies();

    /**
     * @brief Get the list of theaters showing a specific movie.
     *
     * @param movie The name of the movie.
     * @return A vector of strings containing the names of theaters showing the movie.
     */
    std::vector<std::string> GetTheaters(const std::string &movie);

    // #endregion

private:
    // #region Private Members

    /**
     * @brief A manager object to manage end-to-end booking system.
     */
    std::shared_ptr<IBookingManager> _bookingManager;

    /**
     * @brief A global factory to create all the objects required for the booking system.
     */
    std::shared_ptr<ObjectFactory> _commonObjectFactory;

    // #endregion
};
#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_PROGRAM_HPP
