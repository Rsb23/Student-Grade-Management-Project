#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "person.h"
#include "./include/sqlite3.h"

class StudentDAO : public PersonDAO
{
private:
    std::vector<float> grades;
    std::vector<int> classesTaken;
    sqlite3 *db;

public:
    StudentDAO(sqlite3 *db); // constructor, calls prompts
    ~StudentDAO();           // deconstuctor, saves data

    // polymorphism b/c we have new variables and therefore prompts
    void promptAll() override;

    // new class instances -> get data via CLI prompts
    void promptGrades();
    void promptClassesTaken();

    std::vector<float> getGrades() const { return grades; };
    void clearGrades() { grades.clear(); };
    void addGrade(float grade) { grades.push_back(grade); };
    void removeGrade(int index);
    float calcAvgGrade() const;
    float getMinGrade() const;
    float getMaxGrade() const;
    int getGradesCount() const { return grades.size(); };

    std::vector<int> getClassesTaken() const { return classesTaken; };
    void clearClassesTaken() { classesTaken.clear(); };
    void addClassTaken(int classID) { classesTaken.push_back(classID); };
    void removeClassTaken(int classID);
    int getClassesTakenCount() const { return classesTaken.size(); };

    // helper
    std::string createStringCommas(std::vector<float> list);
    std::string createStringCommas(std::vector<int> list);

    // polymorphism b/c Student has more information to save than Person
    void saveData() override;
    void loadData(int ID) override;
};

#endif