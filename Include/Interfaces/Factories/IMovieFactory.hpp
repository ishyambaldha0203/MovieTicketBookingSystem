/*************************************************************************************************
 * @file IMovieFactory.hpp
 *
 * @brief Provides factory to create concrete class instances all the @ref Movie data entity.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IMOVIEFACTORY_HPP
#define _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IMOVIEFACTORY_HPP

#include "CommonConfig.hpp"

#include "Interfaces/Entities/IMovie.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace FactoryInterfaces
{
    /**
     * @interface IMovieFactory
     *
     * @brief Factory interface for concrete classes that implements @ref IMovieFactory.
     */
    interface IMovieFactory
    {
        DECLARE_INTERFACE_DEFAULTS(IMovieFactory)

        /**
         * @brief Pointer to the interface that is the output of the factory.
         */
        using InterfaceSharedPointer = std::shared_ptr<EntityInterfaces::IMovie>;

        /**
         * @brief Create a concrete instance surfaced as pointer to its interfaces.
         *
         * @param[out] name Name of the movie.
         */
        virtual InterfaceSharedPointer Create(const std::string& name) = 0;
    };
} // namespace FactoryInterfaces
END_MOVIE_TICKET_BOOKING_NS

#endif // _MOVIE_TICKET_BOOKING_SYSTEM_INTERFACES_FACTORIES_IMOVIEFACTORY_HPP
