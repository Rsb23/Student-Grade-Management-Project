#include "person.h"

Person::Person()
{
}

Person::~Person()
{
    saveData("test.db"); // TODO: call from database.h
}

void Person::promptID()
{
    while (true)
    {
        std::cout << "Enter Student ID: ";

        std::string inputStr{""};
        std::getline(std::cin, inputStr);

        try
        {
            ID = std::stoi(inputStr);
            break;
        }
        catch (const std::invalid_argument &e)
        { // if we can't convert str -> int
            std::cout << "Please input a number!\n";
        }
        catch (const std::out_of_range &e)
        {
            std::cout << "Inputted ID is either too small or too large!\n";
        }
    }
}

void Person::promptFirstName()
{
    while (true)
    {
        std::cout << "Enter Student First Name: ";

        std::string inputStr{""};
        std::getline(std::cin, inputStr);

        if (inputStr.empty())
        {
            std::cout << "Please enter a name!\n";
            continue;
        }

        if (std::cin.fail())
        {
            std::cout << "Invalid Input!\n";

            std::cin.clear();                                                   // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore anything inputted thus far stopping at
        }

        firstName = inputStr;
    }
}

void Person::promptLastName()
{
    while (true)
    {
        std::cout << "Enter Student Last Name: ";

        std::string inputStr{""};
        std::getline(std::cin, inputStr);

        if (inputStr.empty())
        {
            std::cout << "Please enter a name!\n";
            continue;
        }

        if (std::cin.fail())
        {
            std::cout << "Invalid Input!\n";

            std::cin.clear();                                                   // clear error flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // ignore anything inputted thus far stopping at
        }

        lastName = inputStr;
    }
}

int Person::getID()
{
    return ID;
}

void Person::setID(int newID)
{
    ID = newID;
}

std::string Person::getFirstName()
{
    return firstName;
}

void Person::setFirstName(std::string newFirstName)
{
    firstName = newFirstName;
}

std::string Person::getLastName()
{
    return lastName;
}

void Person::setLastName(std::string newLastName)
{
    lastName = newLastName;
}

std::string Person::getFullName()
{
    return firstName.append(" ").append(lastName);
}
