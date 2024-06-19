#include <iostream>
#include <string>

using namespace std;

/*
    Exercise: 

    You'll define two classes, Person and Teacher, to represent individuals within the school. 
    The goal is to demonstrate the concept of inheritance and access control modifiers in C++.

    In this example:

    The Person class has protected properties like name, age, and grades.
    The Teacher class is derived from Person. 
    It can directly access the grades property for reviewing purposes using the ReviewGrades method.
    The grades property is not directly accessible from outside the class hierarchy.
    This example reflects your analogy: Teacher objects, which are a type of Person, 
    can access the grades of students (also a type of Person) for reviewing purposes. 
    However, the grades property remains encapsulated and not directly accessible 
    from outside the class hierarchy, preserving data encapsulation.


    Class Descriptions:

    1. Person Class:
        The Person class will serve as the base class for all individuals in the school.
        It will have three protected member variables:
        name (string): Stores the name of the person.
        age (int): Stores the age of the person.
        grades (int): Stores the grades of the person.
        It will have a constructor that takes the name, age, and grades as parameters and initializes the corresponding member variables.
    
    2. Teacher Class (Derived from Person):
        The Teacher class will inherit from the Person class.
        It will have a constructor that takes name, age,
        and grades as parameters and passes them to the base class constructor.
        It will have a public member function:
        void ReviewGrades(): Outputs a message indicating that the teacher is reviewing grades, along with the teacher's name and grades.
*/

/*    Solution    */

class Person {
    protected:
        string name;
        int age;
        int grades;

    public:
        Person(const string& _name, int _age, int _grades)
            : name(_name), age(_age), grades(_grades) {}
};

class Teacher : public Person {
    public:
        Teacher(const string& _name, int _age, int _grades)
            : Person(_name, _age, _grades) {}

        void ReviewGrades() {

            cout << "Teacher " << name << " is reviewing grades: " << grades << endl;
        }
};


int main() {

    Teacher teacher("Ms. Johnson", 35, 5);
    teacher.ReviewGrades(); 

    return 0;
}