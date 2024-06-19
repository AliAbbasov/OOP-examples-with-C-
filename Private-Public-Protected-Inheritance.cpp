#include <iostream>
#include <string>

using namespace std; 

class Employee {
protected:
    string name;
    double baseSalary;
public:
        Employee(const string& name, double salary) : name(name), baseSalary(salary) {}

        virtual double calculateSalary() const {
            return baseSalary;}

    virtual void display() const {
        cout << "Employee - Name: " << name << ", Salary: $" << calculateSalary() << endl;
    }

        virtual ~Employee() {}

};

class Manager : public Employee {
    private:
        double bonus;

    public:
        Manager(const string& name, double salary, double bonus) : Employee(name, salary), bonus(bonus) {}
        double calculateSalary() const {
            return baseSalary + bonus;
            }
        void display () const override {
            cout << "Manager Name: " << name << ", Salary: $"<< calculateSalary() << endl;
            }
};

class Developer : public Employee {
private:
    int numberOfProject;

public:
        Developer( const string& name, double salary, int project): Employee( name , salary) , numberOfProject(project) {}

    double calculateSalary() const {
        return baseSalary + (numberOfProject*1000);
    }
    void display () const override {
        cout << "Developer Name: " << name << ", Salary: $" << calculateSalary() << endl;
    }
};


int main() {

/*  Example Usage  */
const int numEmployees = 3;
Employee* employees[numEmployees];

employees[0] = new Manager("Alice", 50000, 10000);
employees[1] = new Developer("Bob", 60000, 5);
employees[2] = new Developer("Charlie", 55000, 3);

for (int i = 0; i < numEmployees; i++) {
    employees[i]->display();
    delete employees[i];
}

return 0;
}
