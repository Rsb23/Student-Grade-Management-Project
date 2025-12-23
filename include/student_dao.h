#ifndef STUDENT_DAO_H
#define STUDENT_DAO_H

#include <vector>
#include "./include/person_dao.h"
#include "./include/sqlite3.h"

class StudentDAO : public PersonDAO
{
private:
    std::vector<float> grades;
    std::vector<int> classesTaken;
    sqlite3 *db;

public:
    // constructor, deconstructor
    StudentDAO(sqlite3 *db, bool newPerson = false, int ID = 0);
    ~StudentDAO();

    // prompts
    void promptAll() override;
    void promptGrades();
    void promptClassesTaken();

    // getters & setters, helper getters & setters
    std::vector<float> getGrades() const { return grades; };
    void clearGrades() { grades.clear(); };
    void addGrade(float grade) { grades.push_back(grade); };
    void removeGrade(int index);
    int getGradesCount() const { return grades.size(); };
    // grade calculation
    float calcAvgGrade() const;
    float getMinGrade() const;
    float getMaxGrade() const;

    std::vector<int> getClassesTaken() const { return classesTaken; };
    void clearClassesTaken() { classesTaken.clear(); };
    void addClassTaken(int classID) { classesTaken.push_back(classID); };
    void removeClassTaken(int classID);
    int getClassesTakenCount() const { return classesTaken.size(); };

    // polymorphism b/c Student has more information to save than Person
    // database access
    void saveData() override;
    void loadData(int ID) override;
};

#endif