################################################################
# SOURCE
################################################################
### NOTE: This file should list all source files regardless of where in the directory tree they reside.
### The main CMake file does not know nor care where the sources are.
target_sources(${MOVIE_TICKET_BOOKING_TEST_TARGET_NAME}
    PRIVATE
        # Src/Internal

        "${CMAKE_CURRENT_LIST_DIR}/Internal/BookingManagerTests.cpp"
        "${CMAKE_CURRENT_LIST_DIR}/../../Src/Internal/BookingManager.cpp"
)