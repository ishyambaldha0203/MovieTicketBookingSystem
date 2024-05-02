################################################################
# SOURCE
################################################################
### NOTE: This file should list all source files regardless of where in the directory tree they reside.
### The main CMake file does not know nor care where the sources are.
target_sources(${MOVIE_TICKET_BOOKING_TARGET_NAME}
    PRIVATE
        # Src
        ${CMAKE_CURRENT_LIST_DIR}/MovieTicketBookingSystem.cpp

        # Src/Internal
        ${CMAKE_CURRENT_LIST_DIR}/Internal/ObjectFactory.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/BookingManager.cpp
        ${CMAKE_CURRENT_LIST_DIR}/Internal/TheaterController.cpp
)
