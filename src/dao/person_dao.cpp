#include "../../include/dao/person_dao.h"

PersonDAO::PersonDAO(bool newPerson, int ID)
{
    if (newPerson)
    {
        promptAll();
    }
}

PersonDAO::~PersonDAO()
{
}

void PersonDAO::promptAll()
{
    promptFirstName();
    promptLastName();
}

void PersonDAO::promptFirstName()
{
    std::cout << "Enter First Name: ";

    std::cin >> firstName;
}
void PersonDAO::promptLastName()
{
    std::cout << "Enter Last Name: ";

    std::cin >> lastName;
}
std::string PersonDAO::serialize(std::vector<int> inputVector)
{
    // serialization func, converts vector<int> obj to str with CRN separated by commas (CSV)
    std::string returnStr{""};

    for (int i{0}; i < inputVector.size(); i++)
    {
        returnStr += inputVector[i];

        if (i != inputVector.size() - 1)
        {
            returnStr += ",";
        }
    }

    return returnStr;
}
std::string PersonDAO::serialize(std::vector<float> inputVector)
{
    // serialization func, converts vector<int> obj to str with CRN separated by commas (CSV)
    std::string returnStr{""};

    for (int i{0}; i < inputVector.size(); i++)
    {
        returnStr += inputVector[i];

        if (i != inputVector.size() - 1)
        {
            returnStr += ",";
        }
    }

    return returnStr;
}
std::vector<float> PersonDAO::deserialize(std::string str)
{
    std::vector<float> returnVector;
    std::string iterableStr{""};

    for (char ch : str)
    {
        if (ch != ',')
        {
            iterableStr += ch;
        }
        else
        {
            returnVector.push_back(std::stof(iterableStr));
            iterableStr = "";
        }
    }

    return returnVector;
}
void PersonDAO::saveData()
{
    // function not used since we don't have a table for the person datatype
    // class serves only as a parent class for other person objects: Faculty and Student
}

void PersonDAO::loadData(int ID)
{
}