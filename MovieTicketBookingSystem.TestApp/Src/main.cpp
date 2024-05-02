#include <iostream>
#include <string>
#include <vector>

#include "MovieTicketBookingSystem.hpp"

/**
 * @brief Function to display menu options
 */
void displayMenu()
{
    std::cout << "Welcome to Movie Ticket Booking System\n";
    std::cout << "1. View running movies\n";
    std::cout << "2. View theaters for a movie\n";
    std::cout << "3. View available seats for a movie and theater\n";
    std::cout << "4. Reserve seats\n";
    std::cout << "5. Add a theater\n";
    std::cout << "6. Add a movie\n";
    std::cout << "7. Exit\n";
}

/**
 * @brief Entry-point function for the booking system test applications CLI.
 *
 * @return 0 if the service application exited normally. Otherwise, a non-zero error code will
 * be returned.
 */
int main()
{
    // Initialize MovieTicketBookingSystem object
    MovieTicketBookingSystem bookingSystem;

    // Main menu loop
    int choice;
    do
    {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
        {
            // View running movies
            std::vector<std::string> movies = bookingSystem.GetRunningMovies();
            std::cout << "Running Movies:\n";
            for (const auto &movie : movies)
            {
                std::cout << movie << std::endl;
            }
            break;
        }
        case 2:
        {
            // View theaters for a movie
            std::string movieName;
            std::cout << "Enter movie name: ";
            std::cin >> movieName;
            std::vector<std::string> theaters = bookingSystem.GetTheaters(movieName);
            std::cout << "Theaters showing " << movieName << ":\n";
            for (const auto &theater : theaters)
            {
                std::cout << theater << std::endl;
            }
            break;
        }
        case 3:
        {
            // View available seats for a movie and theater
            std::string theaterName, movieName;
            std::cout << "Enter theater name: ";
            std::cin >> theaterName;
            std::cout << "Enter movie name: ";
            std::cin >> movieName;
            std::vector<std::string> availableSeats = bookingSystem.GetAvailableSeats(theaterName, movieName);
            std::cout << "Available seats for " << movieName << " at " << theaterName << ":\n";
            for (const auto &seat : availableSeats)
            {
                std::cout << seat << std::endl;
            }
            break;
        }
        case 4:
        {
            // Reserve seats
            std::string theaterName, movieName;
            int numSeats;
            std::cout << "Enter theater name: ";
            std::cin >> theaterName;
            std::cout << "Enter movie name: ";
            std::cin >> movieName;
            std::cout << "Enter number of seats to reserve: ";
            std::cin >> numSeats;
            std::vector<std::string> seatsToBook;
            for (int i = 0; i < numSeats; ++i)
            {
                std::string seat;
                std::cout << "Enter seat " << i + 1 << ": ";
                std::cin >> seat;
                seatsToBook.push_back(seat);
            }
            bookingSystem.DoReserveSeats(theaterName, movieName, seatsToBook);
            break;
        }
        case 5:
        {
            // Add a theater
            std::string theaterName;
            uint32_t seatingCapacity;
            std::cout << "Enter theater name: ";
            std::cin >> theaterName;
            std::cout << "Enter seating capacity: ";
            std::cin >> seatingCapacity;
            bookingSystem.AddTheater(theaterName, seatingCapacity);
            break;
        }
        case 6:
        {
            // Add a movie
            std::string theaterName, movieName;
            std::cout << "Enter theater name: ";
            std::cin >> theaterName;
            std::cout << "Enter movie name: ";
            std::cin >> movieName;
            bookingSystem.AddMovie(theaterName, movieName);
            break;
        }
        case 7:
        {
            // Exit the program
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}