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
# Variables
################################################################################
set(MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME ${PROJECT_NAME})
set(MOVIE_TICKET_BOOKING_TESTAPP_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Src")

################################################################################
# Dependencies
################################################################################
# Use the find_package command to locate MovieBookingSystem
find_package(MovieBookingSystem REQUIRED)

################################################################################
# Targets
################################################################################
add_executable(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME})
add_subdirectory("${MOVIE_TICKET_BOOKING_TESTAPP_SOURCE_DIR}")

target_include_directories(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME}
    PRIVATE
        ${MovieBookingSystem_INCLUDE_DIRS}
)

target_link_libraries(${MOVIE_TICKET_BOOKING_TESTAPP_TARGET_NAME}
    PRIVATE 
        ${MovieBookingSystem_LIBRARIES}
)