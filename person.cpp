#include "person.h"

Person::Person()
{
    promptID();
    promptFirstName();
    promptLastName();
}

Person::~Person()
{
    saveData();
}

Person::promptID()
{
}
