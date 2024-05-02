/*************************************************************************************************
 * @file ObjectFactory.hpp
 *
 * @brief Declarations for the concrete class @ref ObjectFactory.
 *
 *************************************************************************************************/
#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_OBJECTFACTORY_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_OBJECTFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Factories/IObjectFactories.hpp"
#include "Interfaces/Factories/ITheaterFactory.hpp"
#include "Interfaces/Factories/IMovieFactory.hpp"
#include "Interfaces/Factories/ISeatFactory.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    /**
     * @class ObjectFactory
     *
     * @brief Concrete implementation of main object factory.
     */
    class ObjectFactory : public FactoryInterfaces::IBookingManagerFactory,
                          public FactoryInterfaces::ITheaterControllerFactory,
                          public FactoryInterfaces::IMovieFactory,
                          public FactoryInterfaces::ISeatFactory,
                          public FactoryInterfaces::ITheaterFactory,
                          public std::enable_shared_from_this<ObjectFactory>
    {
        // #region Type Aliases

        using BookingManagerFactoryInterfacePtr = FactoryInterfaces::IBookingManagerFactory::InterfaceSharedPointer;
        using TheaterControllerFactoryInterfacePtr = FactoryInterfaces::ITheaterControllerFactory::InterfaceSharedPointer;
        using MovieFactoryInterfacePtr = FactoryInterfaces::IMovieFactory::InterfaceSharedPointer;
        using SeatFactoryInterfacePtr = FactoryInterfaces::ISeatFactory::InterfaceSharedPointer;
        using TheaterFactoryInterfacePtr = FactoryInterfaces::ITheaterFactory::InterfaceSharedPointer;

        // #endregion

    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Factory object
         */
        ObjectFactory();

        /**
         * @brief Destroy the Object Factory object
         */
        virtual ~ObjectFactory() override;

        // #endregion

        // #region Implementation of Factories

        virtual void Create(BookingManagerFactoryInterfacePtr &objectPtr) override;
        virtual void Create(TheaterControllerFactoryInterfacePtr &objectPtr) override;
        virtual MovieFactoryInterfacePtr Create(const std::string& name) override;
        virtual SeatFactoryInterfacePtr Create(const std::string& id, Enums::SeatStatus status) override;
        virtual TheaterFactoryInterfacePtr Create(const std::string& name, uint32_t seatingCapacity) override;


        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(ObjectFactory)

        // #region Private Members

        /**
         * @brief To create singleton instance of booking manager.
         */
        std::shared_ptr<Interfaces::IBookingManager> _bookingManager;

        /**
         * @brief This is to inject the common factory through constructor of all the other required classes.
         *
         * @return The shared pointer of ObjectFactory itself.
         */
        std::shared_ptr<ObjectFactory> Self();

        // #endregion
    };
} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_OBJECTFACTORY_HPP
