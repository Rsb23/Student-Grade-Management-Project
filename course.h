#ifndef COURSE_H
#define COURSE_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class CourseDAO
{
private:
    std::string subject{""};
    int professorID{0};
    sqlite3 *db;

public:
    CourseDAO(sqlite3 *db);
    ~CourseDAO();

    std::string getSubject() const { return subject; };
    void setSubject(std::string subject) { this->subject = subject; };

    int getProfessorID() const { return professorID; };
    void setProfessorID(int professorID) { this->professorID = professorID; };

    void saveData();
    void loadData(int professorID);
};

#endif