#
# This is a CMake project file for Movie Ticket Booking System library.
#
cmake_minimum_required(VERSION 3.16.0)

project(MovieTicketBookingSystem VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/Build/DefaultCmakeSettings.cmake)

set(CMAKE_BUILD_TYPE Debug)

################################################################
# VARIABLES
################################################################
set(MOVIE_TICKET_BOOKING_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Include")
set(MOVIE_TICKET_BOOKING_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")
set(MOVIE_TICKET_BOOKING_TARGET_NAME bookmovie)

################################################################
# DEPENDENCIES
################################################################
find_package(Threads REQUIRED)

################################################################
# TARGETS
################################################################

# Add source to this project's executable.
#add_executable(${MOVIE_TICKET_BOOKING_TARGET_NAME})

add_library(${MOVIE_TICKET_BOOKING_TARGET_NAME} SHARED) # Use SHARED if you want a shared library.
add_subdirectory(${MOVIE_TICKET_BOOKING_SOURCE_DIR})

################################################################
# INCLUDES
################################################################

target_include_directories(${MOVIE_TICKET_BOOKING_TARGET_NAME} PRIVATE
    ${MOVIE_TICKET_BOOKING_INCLUDE_DIR}
)

target_link_libraries(${MOVIE_TICKET_BOOKING_TARGET_NAME} PUBLIC
    Threads::Threads
)
