#include "person.h"

PersonDAO::PersonDAO(sqlite3 *db)
{
    this->db = db;
    promptAll();
}

PersonDAO::~PersonDAO()
{
    saveData();
}

void PersonDAO::promptAll()
{
    promptID();
    promptFirstName();
    promptLastName();
}

void PersonDAO::promptID()
{
    std::cout << "Enter ID (only digits): ";

    int id{0};

    std::cin >> ID;
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
}

void PersonDAO::loadData(int ID)
{
}