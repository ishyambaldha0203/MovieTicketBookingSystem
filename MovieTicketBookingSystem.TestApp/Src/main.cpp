#include <iostream>
#include <string>
#include <vector>
#include <limits> // For std::numeric_limits
#include "MovieTicketBookingSystem.hpp"

void displayMenu()
{
    std::cout << "Welcome to Movie Ticket Booking System\n"
              << "1. View running movies\n"
              << "2. View theaters for a movie\n"
              << "3. View available seats for a movie and theater\n"
              << "4. Reserve seats\n"
              << "5. Add a theater\n"
              << "6. Add a movie\n"
              << "7. Exit\n";
}

int getIntegerInput(const std::string &prompt)
{
    int input;
    while (true)
    {
        std::cout << prompt;
        if (std::cin >> input)
        {
            break;
        }
        else
        {
            std::cout << "Invalid input. Please enter an integer.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    return input;
}

std::string getStringInput(const std::string &prompt)
{
    std::string input;
    std::cout << prompt;
    std::cin >> input;
    return input;
}

int main()
{
    MovieTicketBookingSystem bookingSystem;
    int choice;

    do
    {
        displayMenu();
        choice = getIntegerInput("Enter your choice: ");

        switch (choice)
        {
        case 1:
        {
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
            std::string movieName = getStringInput("Enter movie name: ");
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
            std::string movieName = getStringInput("Enter movie name: ");
            std::string theaterName = getStringInput("Enter theater name: ");
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
            std::string theaterName = getStringInput("Enter theater name: ");
            std::string movieName = getStringInput("Enter movie name: ");
            int numSeats = getIntegerInput("Enter number of seats to reserve: ");
            std::vector<std::string> seatsToBook;
            for (int i = 0; i < numSeats; ++i)
            {
                std::string seat = getStringInput("Enter seat " + std::to_string(i + 1) + ": ");
                seatsToBook.push_back(seat);
            }
            bookingSystem.DoReserveSeats(theaterName, movieName, seatsToBook);
            break;
        }
        case 5:
        {
            std::string theaterName = getStringInput("Enter theater name: ");
            uint32_t seatingCapacity = getIntegerInput("Enter seating capacity: ");
            bookingSystem.AddTheater(theaterName, seatingCapacity);
            break;
        }
        case 6:
        {
            std::string movieName = getStringInput("Enter movie name: ");
            std::string theaterName = getStringInput("Enter theater name: ");
            bookingSystem.AddMovie(theaterName, movieName);
            break;
        }
        case 7:
        {
            std::cout << "Exiting program. Goodbye!\n";
            break;
        }
        default:
        {
            std::cout << "Invalid choice. Please try again.\n";
        }
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    } while (choice != 7);

    return 0;
}
