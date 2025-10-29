#ifndef STUDENT_H
#define STUDENT_H

#include <vector>
#include "person.h"

class Student : public Person
{
private:
    std::vector<float> grades{};
    std::vector<int> classesTaken{};

public:
    Student();  // constructor, calls prompts
    ~Student(); // deconstuctor, saves data

    // for new class objects, get new data via CLI prompt
    void promptGrades();
    void promptClassesTaken();

    std::vector<float> getGrades();
    void setGrades(std::vector<float>);

    std::vector<int> getClassesTaken();
    void setClassesTaken(std::vector<int>);

    // need polymorphism b/c Student has more information to save than Person
    int saveData(std::string);
    void readData(std::string);

    float calcAvgGrade();
    float returnLowestGrade();
    float returnHighestGrade();
};

#endif