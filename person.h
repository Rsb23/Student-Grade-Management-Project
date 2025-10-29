#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>
#include <sqlite.h>

class Person
{
protected:
    std::string ID{""};
    std::string firstName{""};
    std::string lastName{""};

public:
    Person();  // constructor, calls prompts
    ~Person(); // deconstuctor, saves data

    // for new class objects, get new data via CLI prompt
    void promptID();
    void promptFirstName();
    void promptLastName();

    std::string getID();
    void setID(std::string);

    std::string getFirstName();
    void setFirstName(std::string);

    std::string getLastName();
    void setLastName();

    std::string getFullName();

    int saveData(std::string);
    void readData(std::string);
};

#endif