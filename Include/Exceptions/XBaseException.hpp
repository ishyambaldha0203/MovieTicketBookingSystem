/*************************************************************************************************
 * @file XBaseException.hpp
 *
 * @brief A file contains concrete definition of XBaseException.
 *
 * @ref XBaseException is a runtime base exception for all the exceptions being implemented for the application.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_EXCEPTIONS_XBASEEXCEPTION_HPP
#define _MOVIE_TICKET_BOOKING_EXCEPTIONS_XBASEEXCEPTION_HPP

#include "CommonConfig.hpp"

#include <stdexcept>

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Exceptions
{
    /**
     * @class XBaseException
     *
     * @brief A general runtime base exception for the Booking System.
     */
    class XBaseException : public std::runtime_error
    {
    public:
        /**
         * @brief Use the std::runtime_error c'tor
         */
        using runtime_error::runtime_error;
    };
} // namespace Exceptions
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_EXCEPTIONS_XBASEEXCEPTION_HPP