// These are the header files that we need for the code.

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cctype>


// The line below "using namespace std" statement makes
//it unnecessary to prefix the standard library functions with "std::".
using namespace std;

class Employee {
public:
    Employee(string name, int hoursWorked, double hourlyRate)
        : mName(name), mHoursWorked(hoursWorked), mHourlyRate(hourlyRate) {}

    virtual double CalculatePay() const {
        return mHoursWorked * mHourlyRate;
    }

    virtual void PrintPaycheck() const {
        cout << "Paycheck for " << mName << endl;
        cout << "Hours worked: " << mHoursWorked << endl;
        cout << "Hourly rate: $" << fixed << setprecision(2) << mHourlyRate << endl;
        cout << "Total pay: $" << fixed << setprecision(2) << CalculatePay() << endl;
    }

protected:
    string mName;
    int mHoursWorked;
    double mHourlyRate;
};

class Manager : public Employee {
public:
    Manager(string name, int hoursWorked, double hourlyRate, double salary)
        : Employee(name, hoursWorked, hourlyRate), mSalary(salary) {}

    double CalculatePay() const override {
        return mSalary / 52.0;
    }

    void PrintPaycheck() const override {
        cout << "Paycheck for " << mName << endl;
        cout << "Salary: $" << fixed << setprecision(2) << mSalary << endl;
        cout << "Total pay: $" << fixed << setprecision(2) << CalculatePay() << endl;
    }

private:
    double mSalary;
};
void intro();
int main()
{
    intro();
    vector<Employee*> employees;
    employees.push_back(new Employee("John Doe", 40, 15.0));
    employees.push_back(new Manager("Jane Smith", 0, 0, 52000.0));

    for (auto employee : employees) {
        employee->PrintPaycheck();
        cout << endl;
    }

    for (auto employee : employees) {
        delete employee;
    }

    return 0;
}

        // Introduction section 
void intro(){
    cout << "\n\n\n\t     PAYROLL SYSTEM";
    cout << "\n\n\n\n\t     ALADE TEMITAYO GRACE:";
    cout << "\n\n\n\n\t     H/CTE/22/0677: ";
    cout << "\n\n\n\n\t     SUPERVISOR : ENGR NZUBE";
    cout << "\n\n\n\n\t     SCHOOL : THE FEDERAL POLYTECHNIC ILARO";
    cin.get();
}