#ifndef FACULTY_H
#define FACULTY_H

#include "person.h"
#include <vector>
#include <string>
#include <iostream>
#include "./include/sqlite3.h"

class FacultyDAO : public PersonDAO
{
private:
    std::vector<int> classesTaught{};

public:
    // constructor, deconstructor
    FacultyDAO(sqlite3 *db);
    ~FacultyDAO();

    // prompts
    void promptAll() override;
    void promptClassesTaught();

    // getters & setters, helper getters & setters
    std::vector<int> getClassesTaught() const { return classesTaught; };
    void clearClassesTaught() { classesTaught.erase(classesTaught.begin(), classesTaught.end()); };
    void addClassTaught(int classCRN) { classesTaught.push_back(classCRN); };
    void removeClassTaught(int classID);
    int getClassesTaughtCount() const { return classesTaught.size(); };

    // helper function(s)
    std::string convertClassesTaughtToCSV();

    // override b/c Faculty has more information to save than Person
    // database access
    void saveData() override;
    void loadData(int ID) override;
};

#endif