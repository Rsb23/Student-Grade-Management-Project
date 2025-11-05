#include "include/sqlite3.h"
#include <string>
#include <iostream>


class DatabaseConnection{
private:
    static DatabaseConnection * instance;
    std::string dbFilename {"test.db"};
    sqlite3 * db;

    DatabaseConnection(){
        try{
            sqlite3_open(dbFilename.c_str(), &db);

            std::cout << "DatabaseConnection '" << dbFilename << "' Successful\n";
        }
        catch (int errorCode) {
            std::cout << "Error Occured: " << errorCode << "\n";
            throw errorCode;
        }
    }
public:
    static DatabaseConnection * getInstance(){
        if (!instance){
            instance = new DatabaseConnection();
        }

        return instance;
    }
    void testFunc(){
        std::cout << "testFunc called\n";
    }
    void createDB(){
        sqlite3_stmt* stmt;

        sqlite3_prepare_v2(db, "CREATE DATABASE test_db", -1, &stmt, NULL);
        sqlite3_step(stmt);

        sqlite3_prepare_v2(db, "CREATE TABLE people (id INTEGER PRIMARY KEY AUTOINCREMENT,\nfirst_name TEXT NOT NULL,\nlast_name TEXT NOT NULL\n);", -1, &stmt, NULL);
        sqlite3_step(stmt);
        
        for (int i {0}; i < 5; i++){
            sqlite3_prepare_v2(db, "INSERT INTO people (first_name, last_name)\nVALUES('Stefan', 'Barbu')", -1, &stmt, NULL);
            sqlite3_step(stmt);
        }
    }
};

DatabaseConnection* DatabaseConnection::instance = nullptr;

int main(){
    DatabaseConnection * dbConn = DatabaseConnection::getInstance();
    
    dbConn->testFunc();
    dbConn->createDB();
    return 0;
}