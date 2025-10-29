#include "person.h"
#include "student.h"
#include "faculty.h"

// forward declarations for main
float calcClassAvg();

int searchByID(int ID);
int searchByName(std::string name);

void displayStudentStats(std::string name);
void displayStudentStats(int ID);

void promptOptions();
int addNewStudent();
int searchForStudent(); // might be better to just use searchByID and searchByName functions
int displayClassStats();

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
