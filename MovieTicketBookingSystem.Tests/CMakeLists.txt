#
# This is a CMake project file for unit tests of movie ticket booking system.
#
cmake_minimum_required(VERSION 3.16.0)

project(MovieTicketBookingSystemTest VERSION 0.0.0.1 LANGUAGES CXX)

################################################################
# Configurations
################################################################
include(${CMAKE_CURRENT_SOURCE_DIR}/../Build/DefaultCmakeSettings.cmake)

################################################################################
# VARIABLES
################################################################################
set(MOVIE_TICKET_BOOKING_TEST_TARGET_NAME ${PROJECT_NAME})

set(MOVIE_TICKET_BOOKING_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Src")
set(MOVIE_TICKET_BOOKING_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/../Include")
set(MOVIE_TICKET_BOOKING_TEST_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")

################################################################################
# Dependencies
################################################################################
find_package(FrameworkGtest)

################################################################################
# Targets
################################################################################
add_executable(${MOVIE_TICKET_BOOKING_TEST_TARGET_NAME})
add_subdirectory("${MOVIE_TICKET_BOOKING_TEST_SOURCE_DIR}")

target_include_directories(${MOVIE_TICKET_BOOKING_TEST_TARGET_NAME}
    PRIVATE
        "${MOVIE_TICKET_BOOKING_TEST_SOURCE_DIR}"
        "${MOVIE_TICKET_BOOKING_INCLUDE_DIR}"
)

target_link_libraries(${MOVIE_TICKET_BOOKING_TEST_TARGET_NAME}
    PRIVATE
        framework::gtest_suite
)

enable_testing()

gtest_discover_tests(${MOVIE_TICKET_BOOKING_TEST_TARGET_NAME})