/*************************************************************************************************
 * @file IEntity.hpp
 *
 * @brief Interface to define member contracts to access movie related data at runtime.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_IMOVIE_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_IMOVIE_HPP

#include "CommonConfig.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace EntityInterfaces
{
    /**
     * @interface IMovie
     *
     * @brief Represents a read-only entity that fully contains a movie data.
     */
    interface IMovie
    {
        DECLARE_INTERFACE_DEFAULTS(IMovie)

        /**
         * @brief Get the read-only list of movies owned by this entity.
         *
         * @return Name of the movie.
         */
        virtual const std::string& GetName() const noexcept = 0;
    };
} // namespace EntityInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_ENTITIES_IMOVIE_HPP