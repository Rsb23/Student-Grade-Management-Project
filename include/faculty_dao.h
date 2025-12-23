#ifndef FACULTY_DAO_H
#define FACULTY_DAO_H

#include <vector>
#include <string>
#include <iostream>
#include "./include/sqlite3.h"
#include "./include/person_dao.h"

class FacultyDAO : public PersonDAO
{
private:
    std::vector<int> classesTaught{};

public:
    // constructor, deconstructor
    FacultyDAO(sqlite3 *db, bool newPerson = false, int ID = 0);
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

    // override b/c Faculty has more information to save than Person
    // database access
    void saveData() override;
    void loadData(int ID) override;
};

#endif