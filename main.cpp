#include "database.h"
#include "course.h"
#include "./include/sqlite3.h"

DatabaseConnection *DatabaseConnection::instance = nullptr;

int main()
{
    DatabaseConnection *dbConn = DatabaseConnection::getInstance();

    CourseDAO courseDAO(dbConn->getDB());
    courseDAO.setProfessorID(34034);
    courseDAO.setSubject("CSC1100");
    courseDAO.saveData();

    return 0;
}