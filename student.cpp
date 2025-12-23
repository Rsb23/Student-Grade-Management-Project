#include "student.h"

StudentDAO::StudentDAO(sqlite3 *db)
{
    this->db = db;
    promptAll();
}

StudentDAO::~StudentDAO()
{
}

void StudentDAO::promptAll()
{
    promptID();
    promptFirstName();
    promptLastName();
    promptGrades();
    promptClassesTaken();
}

void StudentDAO::promptGrades()
{
    while (true)
    {
        std::cout << "Please enter grade: ";

        float grade{0.0f};
        std::cin >> grade;

        grades.push_back(grade);

        char res{'n'};
        std::cout << "Would You Like To Add Another? (y/n): ";
        std::cin >> res;

        if (res == 'n')
        {
            break;
        }
    }
}
void StudentDAO::promptClassesTaken()
{
    while (true)
    {
        std::cout << "Please enter class_ID: ";

        int classID{0};
        std::cin >> classID;

        classesTaken.push_back(classID);

        char res{'n'};
        std::cout << "Would You Like To Add Another? (y/n): ";
        std::cin >> res;

        if (res == 'n')
        {
            break;
        }
    }
}
void StudentDAO::removeGrade(int index)
{
    for (int i{0}; i < grades.size(); i++)
    {
        if (i == index)
        {
            grades.erase(grades.begin() + i);
        }
    }
}
float StudentDAO::calcAvgGrade() const
{
    float total{0.0f};

    for (float grade : grades)
    {
        total += grade;
    }

    return total / grades.size();
}

float StudentDAO::getMinGrade() const
{
    float smallest{0.0f};

    for (float grade : grades)
    {
        if (grade < smallest)
        {
            smallest = grade;
        }
    }

    return smallest;
}

float StudentDAO::getMaxGrade() const
{
    float largest{0.0f};

    for (float grade : grades)
    {
        if (grade > largest)
        {
            largest = grade;
        }
    }

    return largest;
}

std::string StudentDAO::createStringCommas(std::vector<float> list)
{
    std::string returnStr{""};

    for (int i{0}; i < list.size(); i++)
    {
        returnStr += std::to_string(list[i]);

        if (i != list.size() - 1)
        {
            returnStr += ",";
        }
    }

    return returnStr;
}
std::string StudentDAO::createStringCommas(std::vector<int> list)
{
    std::string returnStr{""};

    for (int i{0}; i < list.size(); i++)
    {
        returnStr += std::to_string(list[i]);

        if (i != list.size() - 1)
        {
            returnStr += ",";
        }
    }

    return returnStr;
}

void StudentDAO::saveData()
{
    sqlite3_stmt *saveStudentStmt;

    sqlite3_prepare_v2(db, "INSERT INTO Students VALUES(NULL, ?1, ?2, ?3, ?4);", -1, &saveStudentStmt, NULL);

    sqlite3_bind_text(saveStudentStmt, 1, firstName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(saveStudentStmt, 2, lastName.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(saveStudentStmt, 3, createStringCommas(grades).c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(saveStudentStmt, 4, createStringCommas(classesTaken).c_str(), -1, SQLITE_TRANSIENT);

    try
    {
        sqlite3_step(saveStudentStmt);
    }
    catch (const std::exception &exception)
    {
        std::cerr << "An error occurred!\n"
                  << exception.what() << "n";
    }
}

void StudentDAO::loadData(int ID)
{
    sqlite3_stmt *loadStudentStmt;

    sqlite3_prepare_v2(db, "SELECT * FROM Students WHERE student_id = ?1;", -1, &loadStudentStmt, NULL);

    sqlite3_bind_int(loadStudentStmt, 1, ID);

    while (sqlite3_step(loadStudentStmt) == SQLITE_ROW)
    {
        firstName = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadStudentStmt, 1)));
        lastName = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadStudentStmt, 2)));
        grades = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadStudentStmt, 3)));
        classesTaken = std::string(reinterpret_cast<const char *>(sqlite3_column_text(loadStudentStmt, 4)));
    }
}