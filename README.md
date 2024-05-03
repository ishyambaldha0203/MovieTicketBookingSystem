# Movie Ticket Booking System

## Overview

This project provides a backend service in the form of a **C++ library** for booking online movie tickets. The service can be integrated with various user interfaces, such as a Command Line Interface (CLI), to facilitate ticket booking for end-users. Booking a ticket involves reserving specific seats in a theater for a particular movie.

## Features
- View all playing movies
- Select a movie
- See all theaters showing the selected movie
- Select a theater
- See available seats for the selected theater & movie
- Book one or more available seats

## Installation and Usage

### Prerequisites
- CMake (version 3.16 or later)
- C++ compiler with support for C++17 (Tested on C++17, but may work with C++11/14)

### Building the Library
1. Clone the repository: `git clone https://github.com/ishyambaldha0203/MovieTicketBookingSystem.git`.
2. Navigate to the project directory: `cd MovieTicketBookingSystem`.
3. Create a build directory: `mkdir build && cd build`.
4. Run CMake to generate build files: `cmake ..`.
5. Build the application: `make`.
6. After building the application, navigate to the build directory `bin/lib/` to find the library as **moviebookigsystem.so**.

## Directory Structure
```
MovieTicketBookingSystem/
├── Build
│   ├── CmakeModules
│   └── DefaultCmakeSettings.cmake
├── CMakeLists.txt
├── Include
│   ├── CommonConfig.hpp
│   ├── Enums
│   ├── Exceptions
│   ├── Interfaces
│   ├── Internal
│   └── MovieTicketBookingSystem.hpp
├── LICENSE
├── MovieTicketBookingSystem.TestApp
│   ├── build
│   ├── CMakeLists.txt
│   └── Src
├── MovieTicketBookingSystem.Tests
│   ├── CMakeLists.txt
│   └── Src
├── README.md
└── Src
    ├── CMakeLists.txt
    ├── Internal
    └── MovieTicketBookingSystem.cpp
```
## Library APIs
- The public APIs are documented in the header file `MovieTicketBookingSystem.hpp`.
- Refer to this file for information on how to interact with the backend service.

### Functional testing using the Test Application
**Note: The dependecy of the library is already added to the CMake file of the app in the form of a find module (Check `FindMovieBookingSystem.cmake`).**
1. Navigate to the TestApp directory `MovieTicketBookingSystem.TestApp`. 
2. Create a build directory: `mkdir build && cd build`.
3. Run CMake to generate build files: `cmake ..`.
4. Build the application: `make`.
5. After building the application, navigate to the build directory `bin/exe/`.
6. Run the executable generated (e.g., `./MovieTicketBookingSystemTestApp`).

### Usage
1. Upon running the application, you will be presented with a menu to perform various actions.
2. Follow the on-screen prompts to select movies, theaters, view available seats, and book tickets.
   
## Unit Testing
- Unit tests are provided to ensure the correctness of the backend service.
- Run the tests by navigating to the `Tests` directory and executing the test executable.

## Known Limitations
- The application does not use any database management system. Data is stored in memory.
- Only basic functionality is implemented. Additional features can be added in future iterations.

## Future scope
1. Implement a logging module to store logs in a log file for easier debugging and analysis.
2. There is still scope for more comprehensive error handling.
3. A CLI application for functional testing can be better.
4. Implement an Operating-System-Dependent (OSD) common configuration layer for enhanced cross-platform (xplat) support.
  - Define global cross-platform primitive types for consistent data representation.
  - Implement macros for accurate platform detection
  - Ensure multiple compiler support

# Known Issue/Bug
Not any at the moment.
