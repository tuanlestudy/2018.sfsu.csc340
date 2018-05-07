#include "Person.h"
#include "Employee.h"

int main()
{
    string *places = new string[8]{"Halong Bay", "Petra", "Venice", "Mu Cang Chai", "Iguazu Falls", "Keukenhof", "Li River"};

    Person p1(123, "John Smith", "johns@mail.com", 8, places);

    Person p2(p1);

    Person p3 = p2;

    cout << "Person's details..." << endl;
    cout << "SSN: " << p3.getSSN() << endl;
    cout << "Name: " << p3.getName() << endl;
    cout << "Email: " << p3.getEmail() << endl;
    cout << "Number of visited places: " << p3.getCount() << endl;
    cout << "Visited places:" << endl;
    for (int i = 0; i < p3.getCount(); i++)
    {
        cout << " " << p3.getPlace(i) << endl;
    }

    Person **p;
    mixedArray(p, 2, 3);
    cout << "\nObjects created from mixedArray function..." << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i]->getTypeOfObj() << " : " << p[i]->getEmail() << endl;
    }

    cout << "\nObjects deleting from deleteMixedArray function..." << endl;
    deleteMixedArray(p, 5);

    cout << endl;
    return 0;
}