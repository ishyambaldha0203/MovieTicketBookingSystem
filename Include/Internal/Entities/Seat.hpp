/*************************************************************************************************
 * @file Seat.hpp
 *
 * @brief Concrete data entity class implementing the @ref ISeat.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_SEAT_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_SEAT_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ISeatMutable.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Entities
{
    /**
     * @class Seat
     *
     * @brief Represents all Seat related data.
     *
     * @note This entity allows to grow in elements as per the requirement.
     */
    class Seat : public EntityInterfaces::ISeatMutable
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new theater entity object.
         */
        Seat(const std::string &id, Enums::SeatStatus status)
            : _id(id),
              _status(status)
        {
            // Nothing to do for now.
        }

        /**
         * @brief Destroy the theater entity object.
         */
        virtual ~Seat() override = default;

        // #endregion

        // #region ISeat Implementation
        const std::string &GetId() const noexcept override
        {
            return _id;
        }

        Enums::SeatStatus GetStatus() const noexcept override
        {
            return _status;
        }

        // #endregion

        // #region ISeatMutable Implementation

        void SetStatus(Enums::SeatStatus status) noexcept override
        {
            _status = status;
        }

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Seat)

        // #region Internal Data Members

        /**
         * @brief Name of the Seat.
         */
        std::string _id;

        /**
         * @brief Current status of seat.
         */
        Enums::SeatStatus _status;

        // #endregion
    };
} // namespace Entities
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_SEAT_HPP