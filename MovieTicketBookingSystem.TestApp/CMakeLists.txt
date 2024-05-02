#
# This is a CMake project file for testing app of movie ticket booking system.
#
cmake_minimum_required(VERSION 3.16.0)

project(MovieTicketBookingSystemTestApp VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/../Build/DefaultCmakeSettings.cmake)

################################################################################
# VARIABLES
################################################################################
set(MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME ${PROJECT_NAME})
set(MOVIE_TICKET_BOOKING_TESTAPP_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")

set(MOVIE_TICKET_BOOKING_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(MOVIE_TICKET_BOOKING_INCLUDE_DIR "${MOVIE_TICKET_BOOKING_BASE_DIR}/Include")
set(MOVIE_TICKET_BOOKING_SOURCE_DIR "${MOVIE_TICKET_BOOKING_BASE_DIR}/Src")
set(MOVIE_TICKET_BOOKING_LIB_PATH "${MOVIE_TICKET_BOOKING_BASE_DIR}/build/bin/lib/libbookmovie.so")

message(${MOVIE_TICKET_BOOKING_LIB_PATH})
message(${MOVIE_TICKET_BOOKING_INCLUDE_DIR})
message(${MOVIE_TICKET_BOOKING_SOURCE_DIR})
################################################################################
# Targets
################################################################################
add_executable(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME})
add_subdirectory("${MOVIE_TICKET_BOOKING_TESTAPP_SOURCE_DIR}")

target_include_directories(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME}
    PRIVATE
        "${MOVIE_TICKET_BOOKING_INCLUDE_DIR}"
        "${MOVIE_TICKET_BOOKING_SOURCE_DIR}"
)

target_link_libraries(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME}
    PRIVATE 
        "${MOVIE_TICKET_BOOKING_LIB_PATH}"
)