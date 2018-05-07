#include "Person.h"

Person::~Person()
{
    delete[] placesVisited;
    cntPlaces = 0;
}

Person::Person() //0->SSN, "na"->name, "personal@"->personalEmail, 10->cntPlaces, allocate space to placesVisited and initializes each place to "unknown"
{
    SSN = 0;
    name = "na";
    personalEmail = "personal@";
    cntPlaces = 10;
    placesVisited = new string[cntPlaces];
    for (int i = 0; i < cntPlaces; i++)
    {
        placesVisited[i] = "unknown";
    }
}

Person::Person(int pSSN, string pName, string email, int count, string *places)
{
    SSN = pSSN;
    name = pName;
    personalEmail = email;
    cntPlaces = count;
    placesVisited = new string[count];
    for (int i = 0; i < count; i++)
    {
        placesVisited[i] = places[i];
    }
}

Person &Person::operator=(const Person &rhs)
{
    if (&rhs != this)
    {
        delete[] placesVisited;

        SSN = rhs.SSN;
        name = rhs.name;
        personalEmail = rhs.personalEmail;
        cntPlaces = rhs.cntPlaces;
        placesVisited = new string[rhs.cntPlaces];
        for (int i = 0; i < rhs.cntPlaces; i++)
        {
            placesVisited[i] = rhs.placesVisited[i];
        }
    }

    return *this;
}

//copy constructor
Person::Person(const Person &clone)
{
    delete[] placesVisited;

    SSN = clone.SSN;
    name = clone.name;
    personalEmail = clone.personalEmail;
    cntPlaces = clone.cntPlaces;
    placesVisited = new string[clone.cntPlaces];
    for (int i = 0; i < clone.cntPlaces; i++)
    {
        placesVisited[i] = clone.placesVisited[i];
    }
}

string Person::getPlace(int i) const //return the i-th place in the placesVisited array if i is valid; otherwise return "out-of-boundary".
{
    if (i >= 0 && i < cntPlaces)
        return placesVisited[i];
    else
        return "out-of-boundary";
}

string Person::getEmail() const //return personalEmail
{
    return personalEmail;
}

void Person::setEmail(string new_email) //new_email-->personalEmail
{
    personalEmail = new_email;
}

string Person::getTypeOfObj() const //return "Person"
{
    return "Person";
}

int Person::getSSN() const
{
    return SSN;
}

string Person::getName() const
{
    return name;
}

int Person::getCount() const
{
    return cntPlaces;
}