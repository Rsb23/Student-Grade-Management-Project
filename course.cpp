#include "course.h"

CourseDAO::CourseDAO(sqlite3 *db)
{
    this->db = db;
}

// CourseDAO::~CourseDAO(){}

void CourseDAO::saveData()
{
    sqlite3_stmt *saveCourseStmt;

    sqlite3_prepare_v2(db, "INSERT INTO Courses VALUES(NULL, ?1, ?2);", -1, &saveCourseStmt, NULL);

    sqlite3_bind_int(saveCourseStmt, 1, professorID);
    sqlite3_bind_text(saveCourseStmt, 2, subject.c_str(), -1, SQLITE_TRANSIENT);

    try
    {
        sqlite3_step(saveCourseStmt);
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "\n";
    }
}

void CourseDAO::loadData(int professorID)
{
    sqlite3_stmt *loadCourseStmt;

    sqlite3_prepare_v2(db, "SELECT subject FROM Courses WHERE faculty_id = ?1;", -1, &loadCourseStmt, NULL);
    sqlite3_bind_int(loadCourseStmt, 1, professorID);

    try
    {
        while (sqlite3_step(loadCourseStmt) == SQLITE_ROW)
        {
            subject = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadCourseStmt, 0)));
        }
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "\n";
    }
}