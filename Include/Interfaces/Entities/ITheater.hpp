/*************************************************************************************************
 * @file ITheater.hpp
 *
 * @brief Interface to define member contracts to access theater data at runtime.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATER_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATER_HPP

#include "CommonConfig.hpp"

#include <vector>

#include "Interfaces/Entities/IMovie.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace EntityInterfaces
{
    /**
     * @interface ITheater
     *
     * @brief Represents a read-only entity that fully contains a theater data.
     */
    interface ITheater
    {
        DECLARE_INTERFACE_DEFAULTS(ITheater)

        virtual const std::string& GetName() const noexcept = 0;

        virtual uint32_t GetSeatingCapacity() const noexcept = 0;
    };
} // namespace EntityInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_ITHEATER_HPP