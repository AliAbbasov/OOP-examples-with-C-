#include <iostream>
#include <string>

using namespace std;

class AdminUser {
protected:
    string username;

public:
    AdminUser(const string& username) : username(username) {}

    virtual string getUsername() const {
        return username;
    }

    virtual void viewProfile() {
        cout << "Viewing the profile of: " << username << endl;
    }

    virtual void postComment() {
        cout << "Comment posted by: " << username << endl;
    }

    virtual void performAction() = 0;
    virtual void login() = 0;
    virtual void logout() = 0;
};

class SiteUser : public AdminUser {
public:
    SiteUser(const string& _username) : AdminUser(_username) {}

    void performAction() override {

    }

    void login() override {
    }

    void logout() override {

    }
};

class ModeratorUser : public AdminUser {
public:
    ModeratorUser(const string& _username) : AdminUser(_username) {}

    void moderateContent() {
        cout << "Content moderated by: " << getUsername() << endl;
    }

    void performAction() override {
    }

    void login() override {
    }

    void logout() override {
    }
};

class ManagerUser : public AdminUser {
public:
    ManagerUser(const string& _username) : AdminUser(_username) {}

    void manageUsers() {
        cout << "Users managed by: " << getUsername() << endl;
    }

    void performAction() override {
    }

    void login() override {
    }

    void logout() override {
    }
};

int main() {
    AdminUser* user1 = new ModeratorUser("ModUser123");
    AdminUser* user2 = new ManagerUser("ManagerUser456");

    user1->login();
    user1->performAction();
    user1->viewProfile();
    user1->logout();

    user2->login();
    user2->performAction();
    user2->viewProfile();
    user2->logout();


    // Specific actions for ModeratorUser and ManagerUser
    ModeratorUser* modUser = dynamic_cast<ModeratorUser*>(user1);
    if (modUser) {
        modUser->moderateContent();
    }

    ManagerUser* managerUser = dynamic_cast<ManagerUser*>(user2);
    if (managerUser) {
        managerUser->manageUsers();
    }

    delete user1;
    delete user2;
    return 0;
}
