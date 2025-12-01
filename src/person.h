#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <limits> // for str input validation

class Person
{
protected:
    int ID{0};
    std::string firstName{""};
    std::string lastName{""};

public:
    Person();  // constructor
    ~Person(); // deconstuctor, saves data

    // for new class objects, get new data via CLI prompt
    void promptID();
    void promptFirstName();
    void promptLastName();

    int getID();
    void setID(int newID);

    std::string getFirstName();
    void setFirstName(std::string newFirstName);

    std::string getLastName();
    void setLastName(std::string newLastName);

    std::string getFullName();

    int saveData(std::string);
    void readData(std::string);
};

#endif