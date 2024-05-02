/*************************************************************************************************
 * @file IObjectFactories.hpp
 *
 * @brief Provides abstract factory for all the classes to create a concrete class instance.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IGenericObjectFactoryT.hpp"

#include "Interfaces/IProgram.hpp"
#include "Interfaces/IBookingManager.hpp"
#include "Interfaces/ITheaterController.hpp"

#include "Interfaces/Entities/IMovie.hpp"
#include "Interfaces/Entities/ITheater.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace FactoryInterfaces
{
    // #region Functional Classes Factories

    /**
     * @interface IBookingManagerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IBookingManager.
     */
    using IBookingManagerFactory = IGenericObjectFactoryT<Interfaces::IBookingManager>;

    /**
     * @interface ITheaterControllerFactory
     *
     * @brief Factory interface for concrete classes that implements @ref ITheaterController.
     */
    using ITheaterControllerFactory = IGenericObjectFactoryT<Interfaces::ITheaterController>;

    // #endregion

} // namespace FactoryInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IOBJECTFACTORIES_HPP
