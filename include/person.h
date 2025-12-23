#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class PersonDAO
{
protected:
    bool newPerson{false};
    int ID{0};
    std::string firstName{""};
    std::string lastName{""};
    sqlite3 *db;

public:
    // constructor, deconstructor
    PersonDAO(bool newPerson = false, int ID = 0);
    ~PersonDAO();

    // prompts
    virtual void promptAll();
    void promptFirstName();
    void promptLastName();

    // getters & setters
    int getID() const { return ID; };
    void setID(int ID) { this->ID = ID; };

    std::string getFirstName() const { return firstName; };
    void setFirstName(std::string firstName) { this->firstName = firstName; };

    std::string getLastName() const { return lastName; };
    void setLastName(std::string lastName) { this->lastName = lastName; };

    std::string getFullName() const { return (firstName + " " + lastName); };

    // database access (not for this base class)
    virtual void saveData();
    virtual void loadData(int ID);
};

#endif