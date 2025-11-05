#include "include/sqlite3.h"

// TODO: refactor based on database.cpp

class DatabaseConnection{
private:
    static DatabaseConnection * instance;

public:
    DatabaseConnection * getInstance(){
        if (!instance){
            instance = new DatabaseConnection();
        }

        return instance;
    }
};