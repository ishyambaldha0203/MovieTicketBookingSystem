/*************************************************************************************************
 * @file SeatStatus.hpp
 *
 * @brief Enum to represent different types of seat status.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_ENUM_SEATSTATUS_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_ENUM_SEATSTATUS_HPP

#include "CommonConfig.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Enums
{
    /**
     * @enum SeatStatus
     * 
     * @brief Represent all possible seat status.
     */
    enum class SeatStatus
    {
        Available,  ///< Seat is available for booking.
        Reserved    ///< Seat is booked and is not available for booking.
    };
} // namespace Entities
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_ENUM_SEATSTATUS_HPP