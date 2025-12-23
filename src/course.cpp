#include "course.h"

CourseDAO::CourseDAO(sqlite3 *db, bool newCourse = false, int courseCRN = 0)
{
    this->newCourse = newCourse;
    this->db = db;

    if (newCourse)
    {
        promptAll();
        saveData();
    }
    else
    {
        loadData(courseCRN);
    }
}

CourseDAO::~CourseDAO()
{
    saveData();
}

void CourseDAO::saveData()
{
    sqlite3_stmt *saveCourseStmt;

    if (!newCourse)
    {
        sqlite3_prepare_v2(db, "UPDATE Courses VALUES(?1, ?2, ?3) WHERE id = ?1;", -1, &saveCourseStmt, NULL);

        sqlite3_bind_int(saveCourseStmt, 1, courseCRN);
        sqlite3_bind_text(saveCourseStmt, 2, subject.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(saveCourseStmt, 3, professorID);
    }
    else
    {
        sqlite3_prepare_v2(db, "INSERT INTO Courses VALUES(NULL, ?1, ?2);", -1, &saveCourseStmt, NULL);

        sqlite3_bind_text(saveCourseStmt, 1, subject.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_int(saveCourseStmt, 2, professorID);
    }

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

void CourseDAO::loadData(int courseCRN)
{
    sqlite3_stmt *loadCourseStmt;

    sqlite3_prepare_v2(db, "SELECT professor_id, subject FROM Courses WHERE id = ?1;", -1, &loadCourseStmt, NULL);
    sqlite3_bind_int(loadCourseStmt, 1, courseCRN);

    try
    {
        while (sqlite3_step(loadCourseStmt) == SQLITE_ROW)
        {
            professorID = sqlite3_column_int(loadCourseStmt, 0);
            subject = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadCourseStmt, 0)));
        }
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "\n";
    }
}