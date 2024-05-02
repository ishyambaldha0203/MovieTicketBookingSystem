/*************************************************************************************************
 * @brief Concrete implementation of a common object factory.
 *
 * It manages creation and lifespan of all the higher level object of the Ticket Booking System.
 *************************************************************************************************/

#include "Internal/ObjectFactory.hpp"

#include "Internal/BookingManager.hpp"
#include "Internal/TheaterController.hpp"
#include "Internal/Entities/Movie.hpp"
#include "Internal/Entities/Seat.hpp"
#include "Internal/Entities/Theater.hpp"

// #region Namespace Symbols

using namespace MOVIE_TICKET_BOOKING_NS::FactoryInterfaces;
using namespace MOVIE_TICKET_BOOKING_NS::Entities;

// #endregion

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Internal
{
    // #region Construction/Destruction

    ObjectFactory::ObjectFactory() = default;

    ObjectFactory::~ObjectFactory() = default;

    // #endregion

    // #region Public Methods

    void ObjectFactory::Create(IBookingManagerFactory::InterfaceSharedPointer &objectPtr)
    {
        if (nullptr == _bookingManager)
        {
            _bookingManager = std::make_shared<BookingManager>(this->Self());
        }

        objectPtr = _bookingManager;
    }
    void ObjectFactory::Create(ITheaterControllerFactory::InterfaceSharedPointer &objectPtr)
    {
        objectPtr = std::make_shared<TheaterController>(this->Self());
    }

    IMovieFactory::InterfaceSharedPointer ObjectFactory::Create(const std::string &name)
    {
        return std::make_shared<Movie>(name);
    }

    ISeatFactory::InterfaceSharedPointer ObjectFactory::Create(const std::string &id, Enums::SeatStatus status)
    {
        return std::make_shared<Seat>(id, status);
    }

    ITheaterFactory::InterfaceSharedPointer ObjectFactory::Create(const std::string &name, uint32_t seatingCapacity)
    {
        return std::make_shared<Theater>(name, seatingCapacity);
    }

    // #endregion

    // #region Private Methods

    std::shared_ptr<ObjectFactory> ObjectFactory::Self()
    {
        return std::enable_shared_from_this<ObjectFactory>::shared_from_this();
    }

    // #endregion
} // namespace Internal
END_MOVIE_TICKET_BOOKING_NS