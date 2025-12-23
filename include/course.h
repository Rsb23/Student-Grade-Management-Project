#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class CourseDAO
{
private:
    bool newCourse{false}; // used for tracking how constructor was used, if true, means prompts were called and its new data, if false, data is representing a row in the database
    int courseCRN{0};      // this is the primary key, auto-incremented, only here when loading existing data
    std::string subject{""};
    int professorID{0};
    sqlite3 *db;

public:
    // constructor, deconstructor
    CourseDAO(sqlite3 *db, bool newCourse = false, int courseCRN = 0);
    ~CourseDAO();

    // prompts
    void promptAll();
    void promptSubject();
    void promptProfessorID();

    // getters & setters
    int getClassCRN() const { return courseCRN; };
    void setClassCRN(int courseCRN) { this->courseCRN = courseCRN; };

    std::string getSubject() const { return subject; };
    void setSubject(std::string subject) { this->subject = subject; };

    int getProfessorID() const { return professorID; };
    void setProfessorID(int professorID) { this->professorID = professorID; };

    // database access
    void saveData();
    void loadData(int courseCRN);
};

#endif