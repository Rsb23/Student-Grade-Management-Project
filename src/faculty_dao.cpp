#include "./include/faculty_dao.h"

FacultyDAO::FacultyDAO(sqlite3 *db, bool newPerson = false, int ID = 0)
{
    this->newPerson = newPerson;
    this->db = db;

    if (newPerson)
    {
        promptAll();
        saveData();
    }
    else
    {
        loadData(ID);
    }
}
FacultyDAO::~FacultyDAO()
{
    saveData();
}
void FacultyDAO::promptAll()
{
    promptFirstName();
    promptLastName();
    promptClassesTaught();
}
void FacultyDAO::promptClassesTaught()
{
    int classCRN{0};
    char res{'n'};

    while (true)
    {
        std::cout << "Add Class (y/n): ";
        std::cin >> res;

        if (res == 'n')
        {
            break;
        }
        std::cout << "Enter Class CRN: ";
        std::cin >> classCRN;

        classesTaught.push_back(classCRN);

        std::cout << "Class " << classCRN << " added!\n";
    }
}
void FacultyDAO::removeClassTaught(int classID)
{
    for (int i{0}; i < classesTaught.size(); i++)
    {
        if (classesTaught[i] == classID)
        {
            classesTaught.erase(classesTaught.begin() + i);
        }
    }
}
void FacultyDAO::saveData()
{
    sqlite3_stmt *saveFacultyData;

    if (!newPerson)
    {
        sqlite3_prepare_v2(db, "UPDATE Faculty VALUES(?1, ?2, ?3, ?4) WHERE id = ?1;", -1, &saveFacultyData, NULL);

        sqlite3_bind_int(saveFacultyData, 1, ID);
        sqlite3_bind_text(saveFacultyData, 2, firstName.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(saveFacultyData, 3, lastName.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(saveFacultyData, 4, serialize(classesTaught).c_str(), -1, SQLITE_TRANSIENT);
    }
    else
    {
        sqlite3_prepare_v2(db, "INSERT INTO Faculty VALUES(NULL, ?1, ?2, ?3);", -1, &saveFacultyData, NULL);

        sqlite3_bind_text(saveFacultyData, 1, firstName.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(saveFacultyData, 2, lastName.c_str(), -1, SQLITE_TRANSIENT);
        sqlite3_bind_text(saveFacultyData, 3, serialize(classesTaught).c_str(), -1, SQLITE_TRANSIENT);
    }

    try
    {
        sqlite3_step(saveFacultyData);
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "\n";
    }
}
void FacultyDAO::loadData(int ID)
{
    sqlite3_stmt *loadFacultyData;

    sqlite3_prepare_v2(db, "SELECT first_name, last_name, courses_taught FROM Faculty WHERE faculty_id = ?1;", -1, &loadFacultyData, NULL);
    sqlite3_bind_int(loadFacultyData, 1, ID);

    try
    {
        while (sqlite3_step(loadFacultyData) == SQLITE_ROW)
        {
            firstName = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadFacultyData, 1)));
            lastName = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadFacultyData, 2)));
            classesTaught = deserialize(std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadFacultyData, 3))));
        }
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "\n";
    }
}