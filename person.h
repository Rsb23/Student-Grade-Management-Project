#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class PersonDAO
{
protected:
    int ID{0};
    std::string firstName{""};
    std::string lastName{""};
    sqlite3 *db;

public:
    PersonDAO(sqlite3 *db); // constructor, calls prompts
    ~PersonDAO();           // deconstuctor, saves data

    // new class instances -> get data via CLI prompts
    virtual void promptAll();

    void promptID();
    void promptFirstName();
    void promptLastName();

    int getID() const { return ID; };
    void setID(int ID) { this -> ID = ID; };

    std::string getFirstName() const { return firstName; };
    void setFirstName(std::string firstName) { this -> firstName = firstName; };

    std::string getLastName() const { return lastName; };
    void setLastName(std::string lastName) { this->lastName = lastName; };

    std::string getFullName() const { return (firstName + " " + lastName); };

    virtual void saveData();
    virtual void loadData(int ID);
};

#endif