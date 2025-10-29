#ifndef FACULTY_H
#define FACULTY_H

#include <vector>

class Faculty : public Person
{
private:
    std::vector<int> classesTaught{};

public:
    Faculty();  // constructor, calls prompts
    ~Faculty(); // deconstuctor, saves data

    // for new class objects, get new data via CLI prompt
    void promptClassesTaught();

    std::vector<int> getClassesTaught();
    void setClassesTaught(std::vector<int>);

    // need polymorphism b/c Faculty has more information to save than Person
    int saveData(std::string);
    void readData(std::string);
};

#endif