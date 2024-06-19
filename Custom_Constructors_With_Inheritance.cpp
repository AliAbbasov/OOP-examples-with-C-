#include<iostream>
#include <string>

using namespace std;

class BackendService {
    public:
        void connect() {
            cout << "Backend service connected." << endl;
        }
        virtual void performTask () {
            cout << "Performing a generic task." << endl;
        }
};

class DatabaseService : public BackendService {
    public:
        void connect(const string& connectionString) {
            cout << "Database service connected: " << connectionString << endl;
        }
        void performTask () override {
            cout << "Performing a database task." << endl;
        }
};

class APIService : public BackendService {
    public:
    void connect (const string& apiKay) {
        cout << "API service connected: " << apiKay << endl;
    }

    void connect() {
        cout << "Connected to an API without an API key." << endl;
    }

    void performTask () override {
        cout << "Performing an API task." << endl;
    }

};


int main() {

BackendService genericService;
DatabaseService database;
APIService api;

genericService.connect(); // Calls the base class method
genericService.performTask(); // Calls the base class method

database.connect("db_connection_string"); // Calls the derived class method (overloaded)
database.performTask(); // Calls the derived class method (overridden)

api.connect("api_key"); // Calls the derived class method (overloaded with a parameter)
api.performTask(); // Calls the derived class method (overridden)

// Method hiding example
api.connect(); // Calls the derived class method (hiding the base class method)


}