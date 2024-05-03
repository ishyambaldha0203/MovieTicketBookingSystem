#
# Include this module to use MovieBookingSystem_FOUND in the application source tree.
#

include_guard(GLOBAL)

# If the package is already found, stop
if(MovieBookingSystem_FOUND)
    return()
endif()

############################################################################
# Variables
############################################################################
# Define the build directory
set(MOVIE_BOOKING_SYSTEM_BASE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(MOVIE_BOOKING_SYSTEM_BUILD_DIR "${MOVIE_BOOKING_SYSTEM_BASE_DIR}/build")
set(MOVIE_BOOKING_SYSTEM_INCLUDE_PATH "${MOVIE_BOOKING_SYSTEM_BASE_DIR}/Include")

############################################################################
# Build MovieBookingSystem
############################################################################
message(STATUS "Configuring and building MovieBookingSystem.")

# Check if the build directory exists, if not, create it
if(NOT EXISTS ${MOVIE_BOOKING_SYSTEM_BUILD_DIR})
    file(MAKE_DIRECTORY ${MOVIE_BOOKING_SYSTEM_BUILD_DIR})
endif()

# Configure the project to generate the cache file
execute_process(
    COMMAND ${CMAKE_COMMAND} ${MOVIE_BOOKING_SYSTEM_BASE_DIR}
    WORKING_DIRECTORY ${MOVIE_BOOKING_SYSTEM_BUILD_DIR}
)

# Build the library
execute_process(
    COMMAND ${CMAKE_COMMAND} --build .
    WORKING_DIRECTORY ${MOVIE_BOOKING_SYSTEM_BUILD_DIR}
)

############################################################################
# Find the Artifacts
############################################################################
# After building, try finding the library again
find_library(MOVIE_BOOKING_SYSTEM_LIBRARY
    NAMES moviebookigsystem
    PATHS ${MOVIE_BOOKING_SYSTEM_BUILD_DIR}/bin/lib
)
if(MOVIE_BOOKING_SYSTEM_LIBRARY)
    set(MovieBookingSystem_FOUND TRUE)
    set(MovieBookingSystem_LIBRARIES ${MOVIE_BOOKING_SYSTEM_LIBRARY})
endif()

# Provide information about where the include directory is located
if(MovieBookingSystem_FOUND)
    get_filename_component(MOVIE_BOOKING_SYSTEM_INCLUDE_DIR ${MOVIE_BOOKING_SYSTEM_INCLUDE_PATH} ABSOLUTE)
    set(MovieBookingSystem_INCLUDE_DIRS ${MOVIE_BOOKING_SYSTEM_INCLUDE_DIR})
endif()

# Report the results
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(MovieBookingSystem
    REQUIRED_VARS
        MovieBookingSystem_LIBRARIES
        MovieBookingSystem_INCLUDE_DIRS
)

add_library(moviebookigsystem INTERFACE)
target_link_libraries(moviebookigsystem INTERFACE ${MovieBookingSystem_LIBRARIES})
