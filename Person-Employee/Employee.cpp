#include "Employee.h"

Employee::~Employee()
{
    delete[] sal_change_rates;
    cnt_sal_changes = 0;
}

Employee::Employee() : Person() //0.0->salary, 10->cnt_sal_changes, "work@"->work_email, sal_change_rates: allocate memory to hold 10 doubles, each of which has an initial value of 0.0
{
    salary = 0.0;
    cnt_sal_changes = 10;
    work_email = "work@";
    sal_change_rates = new double[cnt_sal_changes];
}

Employee::Employee(const Employee &clone)
{
    delete[] sal_change_rates;

    static_cast<Person &>(*this) = clone;
    salary = clone.salary;
    cnt_sal_changes = clone.cnt_sal_changes;
    work_email = clone.work_email;
    sal_change_rates = new double[clone.cnt_sal_changes];
}

Employee Employee::operator=(const Employee &rhs)
{
    if (&rhs != this)
    {
        delete[] sal_change_rates;

        static_cast<Person &>(*this) = rhs;
        salary = rhs.salary;
        cnt_sal_changes = rhs.cnt_sal_changes;
        work_email = rhs.work_email;
        sal_change_rates = new double[rhs.cnt_sal_changes];
    }

    return *this;
}

double Employee::getChangeRate(int i) const ////return the i-th rate in the sal_change_rates array if i is valid; otherwise return -1.00
{
    if (i >= 0 && i < cnt_sal_changes)
        return sal_change_rates[i];
    else
        return -1.00;
}

string Employee::getEmail() const //return work_email
{
    return work_email;
}

void Employee::setEmail(string new_email) //new_email-->work_email
{
    work_email = new_email;
}

string Employee::getTypeOfObj() const //return "Employee"
{
    return "Employee";
}

double Employee::getSalary() const
{
    return salary;
}

int Employee::getCount() const
{
    return cnt_sal_changes;
}

//see below for more details about this function.
void mixedArray(Person **&arrayPersonEmp, int numPersons, int numEmployees)
{
    arrayPersonEmp = new Person *[numPersons + numEmployees];
    for (int i = 0; i < numPersons + numEmployees; i++)
    {
        if (i < numPersons)
        {
            Person *p = new Person;
            arrayPersonEmp[i] = p;
            arrayPersonEmp[i]->setEmail("personal@mail.com");
        }
        else
        {
            Employee *e = new Employee;
            arrayPersonEmp[i] = e;
            arrayPersonEmp[i]->setEmail("work@mail.com");
        }
    }
}

//see below for more details about this function.
void deleteMixedArray(Person **&arrayPersonEmp, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arrayPersonEmp[i]->getTypeOfObj() << " object is deleting..." << endl;
        delete arrayPersonEmp[i];
    }
}