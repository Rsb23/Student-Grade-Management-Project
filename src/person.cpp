#include "person.h"

PersonDAO::PersonDAO(bool newPerson = false, int ID = 0)
{
    if (newPerson)
    {
        promptAll();
    }
}

PersonDAO::~PersonDAO()
{
}

void PersonDAO::promptAll()
{
    promptFirstName();
    promptLastName();
}

void PersonDAO::promptFirstName()
{
    std::cout << "Enter First Name: ";

    std::cin >> firstName;
}
void PersonDAO::promptLastName()
{
    std::cout << "Enter Last Name: ";

    std::cin >> lastName;
}

void PersonDAO::saveData()
{
    // function not used since we don't have a table for the person datatype
    // class serves only as a parent class for other person objects: Faculty and Student
}

void PersonDAO::loadData(int ID)
{
}