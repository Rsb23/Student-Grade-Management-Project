#ifndef FACULTY_H
#define FACULTY_H

#include "person.h"
#include <vector>
#include <string>

class FacultyDAO : public PersonDAO
{
private:
    std::vector<int> classesTaught{};

public:
    FacultyDAO();  // constructor, calls prompts
    ~FacultyDAO(); // deconstuctor, saves data

    // polymorphism b/c we have new variables and therefore prompts
    void promptAll() override;

    // new class instances -> get data via CLI prompts
    void promptClassesTaught();

    std::vector<int> getClassesTaught() const;
    void clearClassesTaught();
    void addClassTaught();
    void removeClassTaught(int classID);
    int getClassesTaughtCount() const;

    // need polymorphism b/c Faculty has more information to save than Person
    void saveData(std::string) override;
    void loadData(std::string) override;
};

#endif