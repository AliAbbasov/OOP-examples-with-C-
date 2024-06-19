#include <iostream>
#include <string>

using namespace std;

class LibraryItem {
    protected:
    string title;
    int year;
    bool checkedOut;
    public:
    LibraryItem (const string& title, int year) : title(title), year(year),checkedOut(false) {}

    virtual void checkout () {
        checkedOut = true;
    }
    virtual void checkin () {
        checkedOut = false;
    }

    virtual void displayInfo() const {
        cout << "Title: \"" << title << "\"" << endl;
        cout << "Year: " << year << endl;
        cout << "Status: " << (checkedOut ? "Checked out" : "Checked in") << endl;
    }

};

class Book :  public LibraryItem {
    private:
        string author;
    public:
        Book (const string& title, int year, const string& author) : LibraryItem(title, year), author(author) {}

        void displayInfo () const override {
            cout  << " Book:";
            LibraryItem::displayInfo();
            cout << "Author: " << author << endl;
    }
};

class EBook : public LibraryItem {
    private:
    string format;
    public:
    EBook (const string& title, int year, const string& author) : LibraryItem(title, year), format(author) {}

    void displayInfo () const override {
        cout  << " EBook:";
        LibraryItem::displayInfo();
        cout << "Format: " << format << endl;
    }
};

class AudioCD : public LibraryItem {
    private:
    string artist;
    public:
    AudioCD (const string& title, int year, const string& artist) : LibraryItem(title, year), artist(artist) {}

    void displayInfo () const override {
        cout  << " AudioCD:";
        LibraryItem::displayInfo();
        cout << "Artist: " << artist << endl;
    }
};



int main() {
    // Example usage
    Book book("The Great Gatsby", 1925, "F. Scott Fitzgerald");
    EBook ebook("The Hitchhiker's Guide to the Galaxy", 1979, "EPUB");
    AudioCD audioCD("Abbey Road", 1969, "The Beatles");

    LibraryItem* items[] = { &book, &ebook, &audioCD };


    for (int i = 0; i < 3; i++) {
        items[i]->checkout();
        items[i]->displayInfo();
        items[i]->checkin();
        items[i]->displayInfo();
        cout << endl;
    }

    return 0;
}