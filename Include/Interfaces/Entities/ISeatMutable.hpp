/*************************************************************************************************
 * @file ISeatMutable.hpp
 *
 * @brief Interface to define member contracts to access and update theater related data.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATERMUTABLE_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATERMUTABLE_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISeat.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace EntityInterfaces
{
    /**
     * @interface ISeatMutable
     *
     * @brief Allows modification of theater data through set methods.
     */
    interface ISeatMutable : public ISeat
    {
        DECLARE_INTERFACE_DEFAULTS(ISeatMutable)

        virtual void SetStatus(Enums::SeatStatus status) noexcept = 0;
    };
} // namespace EntityInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATERMUTABLE_HPP