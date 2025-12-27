#include "../../include/dao/person_dao.h"
#include "../../include/dao/course_dao.h"
#include "../../include/dao/faculty_dao.h"
#include "../../include/dao/student_dao.h"
#include "../include/db_conn.h"
#include "../../include/sqlite3.h"

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