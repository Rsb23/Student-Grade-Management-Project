#include "database.h"

DatabaseConnection::DatabaseConnection(std::string dbFilename)
{
    this->dbFilename = dbFilename;

    try
    {
        sqlite3_open(dbFilename.c_str(), &db);

        std::cout << "DatabaseConnection '" << dbFilename << "' Successful\n";
    }
    catch (int errorCode)
    {
        std::cout << "Error Occured: " << errorCode << "\n";
        throw errorCode;
    }
}
DatabaseConnection *DatabaseConnection::getInstance()
{
    if (!instance)
    {
        instance = new DatabaseConnection("test.db");
    }

    instance->createDB();

    return instance;
}
void DatabaseConnection::createDB() const
{
    sqlite3_stmt *createDBStmt;
    sqlite3_stmt *createStudentsTableStmt;
    sqlite3_stmt *createFacultyTableStmt;
    sqlite3_stmt *createCoursesTableStmt;

    sqlite3_prepare_v2(db, "CREATE DATABASE db", -1, &createDBStmt, NULL);
    sqlite3_prepare_v2(db, "CREATE TABLE Students(id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            first_name TEXT NOT NULL,\
                            last_name TEXT NOT NULL,\
                            grades TEXT,\
                            classes_taken TEXT);",
                       -1, &createStudentsTableStmt, NULL);
    sqlite3_prepare_v2(db, "CREATE TABLE Faculty(id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            first_name TEXT NOT NULL,\
                            last_name TEXT NOT NULL,\
                            classes_taught TEXT);",
                       -1, &createFacultyTableStmt, NULL);
    sqlite3_prepare_v2(db, "CREATE TABLE Courses(id INTEGER PRIMARY KEY AUTOINCREMENT,\
                            faculty_id INTEGER NOT NULL,\
                            subject TEXT NOT NULL,\
                            FOREIGN KEY(faculty_id) REFERENCES faculty(id));",
                       -1, &createCoursesTableStmt, NULL);

    // execute prepared SQL statements, check for errors
    try
    {
        sqlite3_step(createDBStmt); // this must be run before the others
        sqlite3_step(createStudentsTableStmt);
        sqlite3_step(createFacultyTableStmt);
        sqlite3_step(createCoursesTableStmt);
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n" << exception.what() << "n";
    }
}