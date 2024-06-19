#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
public:
    LibraryItem(const string& title) : title(title) {
        totalItems++;
    }

    virtual ~LibraryItem() {
        totalItems--;
    }
    
    virtual double calculateLateFee(int daysLate) const = 0;

    virtual void displayInfo() const {
        cout << "Title: " << title << endl;
    }

    static int totalItems;

protected:
    string title;
};

int LibraryItem::totalItems = 0;

class Book : public LibraryItem {
public:
    Book(const string& title, const string& author) : LibraryItem(title), author(author) {}

    double calculateLateFee(int daysLate) const override {
        return 0.1 * daysLate; 
    }

    void displayInfo() const override {
        LibraryItem::displayInfo();
        cout << "Author: " << author << endl;
    }

private:
    string author;
};

class DVD : public LibraryItem {
public:
    DVD(const string& title, int duration) : LibraryItem(title), duration(duration) {}

    double calculateLateFee(int daysLate) const override {
        return 0.2 * daysLate; 
    }

    void displayInfo() const override {
        LibraryItem::displayInfo();
        cout << "Duration: " << duration << " minutes" << endl;
    }

private:
    int duration;
};


int main() {
    Book book("Thus Spoke Zarathustra", "Friedrich Nietzsche");
    DVD dvd("The Dark Knight", 120);

    cout << "Book Information:" << endl;
    book.displayInfo();
    cout << "Late Fee for the book (5 days late): $" << book.calculateLateFee(5) << endl;

    cout << "\nDVD Information:" << endl;
    dvd.displayInfo();
    cout << "Late Fee for the DVD (3 days late): $" << dvd.calculateLateFee(3) << endl;

    cout << "\nTotal number of library items: " << LibraryItem::totalItems << endl;

    return 0;
}