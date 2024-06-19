#include <iostream>
#include <string>

using namespace std;

// Base class for user authentication
class Authenticator {
public:

    // TODO: Declare a pure virtual function for authentication
    virtual bool authenticate(const string& username, const string& password) const = 0;
};

    // TODO: Decide whether to mark the following class as final or not
class BasicAuthenticator : public Authenticator {
public:
    BasicAuthenticator(const string& validUsername, const string& validPassword)
        : validUsername_(validUsername), validPassword_(validPassword) {}

    // TODO: Implement the authenticate function
    bool authenticate(const string& username, const string& password) const override {
        return username == validUsername_ && password == validPassword_;
    }

private:
    string validUsername_;
    string validPassword_;
};

class CustomAuthenticator : public BasicAuthenticator {
public:
    CustomAuthenticator(const string& validUsername, const string& validPassword)
        : BasicAuthenticator(validUsername, validPassword) {}

    bool authenticate(const string& username, const string& password) const final  {
        return BasicAuthenticator::authenticate(username, password);
    }
};

int main() {

    // TODO: Create an instance of BasicAuthenticator
    BasicAuthenticator basicAuth("admin", "admin123");

    // TODO: Authenticate using the BasicAuthenticator
    if (basicAuth.authenticate("admin", "admin123")) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    CustomAuthenticator customAuth("user", "pass");

    if (customAuth.authenticate("user", "pass")) {
        cout << "Authentication successful!" << endl;
    } else {
        cout << "Authentication failed!" << endl;
    }

    return 0;
}
