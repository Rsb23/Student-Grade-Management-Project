#ifndef DATABASE_CONN_H
#define DATABASE_CONN_H

#include <iostream>
#include <string>
#include "./include/sqlite3.h"

class DatabaseConnection
{
private:
    static DatabaseConnection *instance;
    std::string dbFilename{""};
    sqlite3 *db;
    DatabaseConnection(std::string dbFilename);

public:
    // getters & setters
    std::string getDbFilename() const { return dbFilename; }
    void setDbFilename(std::string newDbFilename) { dbFilename = newDbFilename; };

    sqlite3 *getDB() const { return db; };
    // singleton utility func
    static DatabaseConnection *getInstance();
    // database general access functions
    void createDB() const;
};

#endif