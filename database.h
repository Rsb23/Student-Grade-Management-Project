#include "include/sqlite3.h"
#include <iostream>
#include <string>

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
    void setDbFilename(std::string newDbFilename) { dbFilename = newDbFilename; }
    // singleton utility func
    static DatabaseConnection *getInstance();
    // database general access functions
    void createDB() const;
};