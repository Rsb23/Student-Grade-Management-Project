#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class CourseDAO
{
private:
    int classCRN{0}; // this is the primary key, auto-incremented, only here when loading existing data
    std::string subject{""};
    int professorID{0};
    sqlite3 *db;

public:
    // constructor, deconstructor
    CourseDAO(sqlite3 *db, bool newCourse = false, int classCRN);
    ~CourseDAO();

    // prompts
    void promptAll();
    void promptSubject();
    void promptProfessorID();

    // getters & setters
    int getClassCRN() const { return classCRN; };
    void setClassCRN(int classCRN) { this->classCRN = classCRN; };

    std::string getSubject() const { return subject; };
    void setSubject(std::string subject) { this->subject = subject; };

    int getProfessorID() const { return professorID; };
    void setProfessorID(int professorID) { this->professorID = professorID; };

    // database access
    void saveData();
    void loadData(int classCRN);
};

#endif