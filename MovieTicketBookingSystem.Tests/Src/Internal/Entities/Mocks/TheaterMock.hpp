/**********************************************************************
 * @file TheaterMock.hpp
 *
 * @brief Declaration of mocked methods for class @ref Theater.
 *
 * It is required for unit testing.
 *********************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_TESTS_INTERNAL_ENTITIES_MOCKS_THEATERMOCK_HPP
#define _MOVIE_TICKET_BOOKING_TESTS_INTERNAL_ENTITIES_MOCKS_THEATERMOCK_HPP

#include "CommonTestsConfig.hpp"

#include "Interfaces/Entities/ITheater.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Entities
{
    namespace Test
    {
        /**
         * @class TheaterMock
         *
         * @brief A mock class for @ref Theater data entity.
         */
        class TheaterMock : public EntityInterfaces::ITheater
        {
        public:
            MOCK_METHOD(const std::string&, GetName, (), (const, override, noexcept));
            MOCK_METHOD(const std::vector<EntityInterfaces::IMovie>&, GetMovies, (), (const, override, noexcept));
        };
    }
}
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_TESTS_INTERNAL_ENTITIES_MOCKS_THEATERMOCK_HPP
