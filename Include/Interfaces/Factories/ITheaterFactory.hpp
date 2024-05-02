/*************************************************************************************************
 * @file ITheaterFactory.hpp
 *
 * @brief Provides factory to create concrete class instances all the @ref Theater data entity.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ITHEATERFACTORY_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ITHEATERFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ITheater.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace FactoryInterfaces
{
    /**
     * @interface ITheaterFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITheaterFactory.
     */
    interface ITheaterFactory
    {
        DECLARE_INTERFACE_DEFAULTS(ITheaterFactory)

        /**
         * @brief Pointer to the interface that is the output of the factory.
         */
        using InterfaceSharedPointer = std::shared_ptr<EntityInterfaces::ITheater>;

        /**
         * @brief Create a concrete instance surfaced as pointer to its interfaces.
         *
         * @param[out] name Name of the theater.
         */
        virtual InterfaceSharedPointer Create(const std::string& name, uint32_t seatingCapacity) = 0;
    };
} // namespace FactoryInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_ITHEATERFACTORY_HPP
