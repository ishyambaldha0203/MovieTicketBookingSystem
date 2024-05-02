/*************************************************************************************************
 * @file ISeatFactory.hpp
 *
 * @brief Provides factory to create concrete class instances all the @ref Seat data entity.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ISEATFACTORY_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ISEATFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ITheater.hpp"
#include "Enums/SeatStatus.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace FactoryInterfaces
{
    /**
     * @interface ISeatFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ISeatFactory.
     */
    interface ISeatFactory
    {
        DECLARE_INTERFACE_DEFAULTS(ISeatFactory)

        /**
         * @brief Pointer to the interface that is the output of the factory.
         */
        using InterfaceSharedPointer = std::shared_ptr<EntityInterfaces::ISeat>;

        /**
         * @brief Create a concrete instance surfaced as pointer to its interfaces.
         *
         * @param[out] name Name of the theater.
         */
        virtual InterfaceSharedPointer Create(const std::string& id, Enums::SeatStatus status) = 0;
    };
} // namespace FactoryInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ISEATFACTORY_HPP
