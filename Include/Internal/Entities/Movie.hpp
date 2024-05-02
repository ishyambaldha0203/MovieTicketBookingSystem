/*************************************************************************************************
 * @file Movie.hpp
 *
 * @brief Concrete data entity class implementing the @ref IMovie.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_MOVIE_HPP
#define _MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_MOVIE_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IMovie.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Entities
{
    /**
     * @class Movie
     *
     * @brief Represents all Movie related data.
     *
     * @note This entity allows to grow in elements as per the requirement.
     */
    class Movie : public EntityInterfaces::IMovie
    {
    public:
        // #region Construction/Destruction

        /**
         * @brief Construct a new Movie entity object.
         */
        Movie(const std::string &name)
            : _name(name)
        {
            // Nothing to do for now.
        }

        /**
         * @brief Destroy the Movie entity object.
         */
        virtual ~Movie() override = default;

        // #endregion

        // #region IMovie Implementation

        const std::string &GetName() const noexcept override
        {
            return _name;
        }

        // #endregion

    private:
        DECLARE_NON_COPYABLE_CLASS(Movie)

        // #region Internal Data Members

        /**
         * @brief Movie name.
         */
        std::string _name;

        // #endregion
    };
} // namespace Entities
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_INTERNAL_ENTITIES_MOVIE_HPP