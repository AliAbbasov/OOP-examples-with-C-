#include <iostream>
#include <vector>
#include <string>

using namespace std;

/*
    What You Will Learn:

    By completing this exercise, you will not only have enhanced your understanding of constructor design 
    and access specifiers but also gained insights into the principles of encapsulation and object-oriented design. 
    You will be better equipped to create classes with well-designed constructors 
    and appropriately chosen access specifiers for improved code organization and maintainability.
*/


/*
    Exercise Description:

    In this exercise, you will work on enhancing the provided C++ program 
    that models a basic object-oriented project and task management system. 
    The focus will be on constructing classes with optimal constructor design 
    and understanding the selection of access specifiers (public, protected, private) to achieve encapsulation. 
    Your task is to both complete the exercise objectives and respond to questions about constructor design and access specifiers.
*/



/*
    Exercise Tasks:

    1. Class Constructor Design:
    Review the constructor design of the existing classes (Project, TeamMember, Task). 
    Analyze how constructors are used to initialize class attributes. 
    Identify any areas for improvement in terms of constructor parameters and member initialization. 
    Refactor the constructors as needed to ensure optimal and meaningful initialization of class attributes.

    2. Access Specifier Analysis:
    Study the classes and their member attributes (projectName, memberName, taskName). 
    For each attribute, decide whether it should be declared as public, 
    protected, or private based on the principle of encapsulation. 
    Explain your decision-making process for each attribute and its access specifier choice.

    3. Constructors and Inheritance:
    Explore how constructors are inherited in C++ classes.
    Given the inheritance relationships between classes (ProjectTeamMember, TeamMemberTask),
    discuss how constructors from base classes are called during the creation of derived class instances. 
    What considerations should be made when working with constructors in an inheritance hierarchy?

    4. Constructor Overloading:
    Introduce constructor overloading in one of the classes (e.g., Project). 
    Provide multiple constructors with different parameter sets. 
    Explain the scenarios in which each constructor might be useful and how they contribute to the flexibility of object creation.

    5. Access Specifiers and Inheritance:
    Consider the access specifiers used in the ProjectTeamMember and TeamMemberTask classes. 
    Explain the impact of these access specifiers on the visibility of inherited members within the derived classes. 
    Provide examples of scenarios where the choice of access specifiers affects class behavior.
*/



/* Starter Code: */

class Project {
    protected:
        string projectName;

    public:
        Project(const string& name) : projectName(name) {}

        void displayProject() const {
            cout << "Project: " << projectName << endl;
        }
};


class TeamMember {
    protected:
        string memberName;

    public:
        TeamMember(const string& name) : memberName(name) {}

        void displayTeamMember() const {
            cout << "Team Member: " << memberName << endl;
        }
};


class Task {
    protected:
        string taskName;

    public:
        Task(const string& name) : taskName(name) {}

        void displayTask() const {
            cout << "Task: " << taskName << endl;
        }
};


class ProjectTeamMember : public Project, public TeamMember {
    public:
        ProjectTeamMember(const string& projectName, const string& memberName)
            : Project(projectName), TeamMember(memberName) {}

        void displayProjectTeamMember() const {
            displayProject();
            displayTeamMember();
        }
};


class TeamMemberTask : public TeamMember, public Task {
    public:
        TeamMemberTask(const string& memberName, const string& taskName)
            : TeamMember(memberName), Task(taskName) {}

        void displayTeamMemberTask() const {
            displayTeamMember();
            displayTask();
        }
};



int main() {

    system("clear");

    ProjectTeamMember ptm("Project X", "Alice");
    TeamMemberTask tmt("Bob", "Code Review");

    cout << "Project Team Member Information:" << endl;
    ptm.displayProjectTeamMember();

    cout << "\nTeam Member Task Information:" << endl;
    tmt.displayTeamMemberTask();

    /*
        [Sample Output]
        
        Project Team Member Information:
        Project: Project X
        Team Member: Alice

        Team Member Task Information:
        Team Member: Bob
        Task: Code Review
    */

    /*
        Discussion Questions:

        1. How does constructor chaining contribute to the efficient initialization of class attributes in an inheritance hierarchy?
        2. When designing constructors, what factors should you consider to ensure meaningful and concise parameter lists?
           Provide examples of scenarios where each access specifier is suitable.
        3. How can constructor overloading improve the usability of a class and simplify object creation for different use cases?
    */

    return 0;
}