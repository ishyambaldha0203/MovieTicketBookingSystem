/*************************************************************************************************
 * @file ISeat.hpp
 *
 * @brief Interface to define member contracts to access Seat related data at runtime.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ISEAT_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ISEAT_HPP

#include "CommonConfig.hpp"

#include <vector>

#include "Enums/SeatStatus.hpp"
#include "Interfaces/Entities/IMovie.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace EntityInterfaces
{
    /**
     * @interface ISeat
     *
     * @brief Represents a read-only entity that fully contains a seat related data.
     */
    interface ISeat
    {
        DECLARE_INTERFACE_DEFAULTS(ISeat)

        virtual const std::string& GetId() const noexcept = 0;

        virtual Enums::SeatStatus GetStatus() const noexcept = 0;
    };
} // namespace EntityInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ISEAT_HPP