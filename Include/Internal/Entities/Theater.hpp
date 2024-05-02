/*************************************************************************************************
 * @file Theater.hpp
 *
 * @brief Concrete data entity class implementing the @ref ITheater.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_THEATER_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_THEATER_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/ITheater.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Entities
{
    /**
     * @class Theater
     *
     * @brief Represents all Theater related data.
     *
     * @note This entity allows to grow in elements as per the requirement.
     */
    class Theater : public EntityInterfaces::ITheater
    {
        using IMovie = EntityInterfaces::IMovie;

    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new theater entity object.
         */
        Theater(const std::string &name, uint32_t seatingCapacity)
            : _name(name),
              _seatingCapacity(seatingCapacity)
        {
            // Nothing to do for now.
        }

        /**
         * @brief Destroy the theater entity object.
         */
        virtual ~Theater() override = default;

        // #endregion

        // #region ITheater Implementation

        const std::string &GetName() const noexcept override
        {
            return _name;
        }

        uint32_t GetSeatingCapacity() const noexcept override
        {
            return _seatingCapacity;
        }

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Theater)

        // #region Internal Data Members

        /**
         * @brief Name of the theater.
         */
        std::string _name;

        /**
         * @brief Total seats in theater.
         */
        uint32_t _seatingCapacity;

        // #endregion
    };
} // namespace Entities
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_THEATER_HPP