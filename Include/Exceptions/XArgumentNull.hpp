/*************************************************************************************************
 * @file XArgumentNullException.hpp
 * 
 * @brief Contains definition for the XArgumentNullException exception type.
 *************************************************************************************************/

#ifndef _MOVIE_TICKET_BOOKING_EXCEPTIONS_XARGUMENTNULL_HPP
#define _MOVIE_TICKET_BOOKING_EXCEPTIONS_XARGUMENTNULL_HPP

#include "CommonConfig.hpp"

#include "Exceptions/XInvalidArgument.hpp"

BEGIN_MOVIE_TICKET_BOOKING_NS
namespace Exceptions
{
    /**
     * @class XArgumentNull
     *
     * @brief Exception to throw for null arguments
     */
    class XArgumentNull : public XInvalidArgument
    {
        // Internal Aliases
        using Base = XInvalidArgument;
        using Self = XArgumentNull;

    public:
        /**
         * @brief Construct a new XArgumentNull object
         *
         * @param paramName
         */
        XArgumentNull(const std::string &paramName)
            : Base(u8"A null argument was supplied: " + paramName)
        {
            // Do nothing.
        }

        /**
         * @brief Construct a new XArgumentNull object
         *
         * @param other
         */
        XArgumentNull(const Self &other) noexcept : Base(other)
        {
            // Do nothing.
        }

        /**
         * @brief Overloaded assignment operator.
         *
         * @param other
         * @return Self&
         */
        Self &operator=(const Self &other) noexcept
        {
            Base::operator=(other);

            return *this;
        }
    };
} // namespace Exceptions
END_MOVIE_TICKET_BOOKING_NS

#endif // !_MOVIE_TICKET_BOOKING_EXCEPTIONS_XARGUMENTNULL_HPP
