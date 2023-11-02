/*
Imagine a publishing company which does marketing for book and audio cassette 
versions. Create a class publication that stores the title (a string) and price (type float) of 
a publication. 
From this class derive two classes: book, which adds a page count (type int), and tape, 
which adds a playing time in minutes (type float).
Write a program that instantiates the book and tape classes, allows user to enter data 
and displays the data members. If an exception is caught, replace all the data member 
values with zero values.
*/

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;
class Publication {
protected:
    string title;
    float price;

public:
    Publication() : title(""), price(0.0) {}

    void getData() {
        cout << "Enter title: ";
        cin.ignore();
        getline(std::cin, title);
        cout << "Enter price: ";
        cin >> price;
    }

    void displayData() {
        cout << "Title: " << title << endl;
        cout << "Price: " << price << endl;
    }
};

class Book : public Publication {
private:
    int pageCount;

public:
    Book() : pageCount(0) {}

    void getData() {
        Publication::getData();
        cout << "Enter page count: ";
        cin >> pageCount;
    }

    void displayData() {
        Publication::displayData();
        cout << "Page Count: " << pageCount << endl;
    }
};

class Tape : public Publication {
private:
    float playingTime;

public:
    Tape() : playingTime(0.0) {}

    void getData() {
        Publication::getData();
        cout << "Enter playing time (minutes): ";
        cin >> playingTime;
    }

    void displayData() {
        Publication::displayData();
        cout << "Playing Time: " << playingTime << " minutes" << endl;
    }
};

int main() {
    try {
        Book book;
        Tape tape;

        cout << "Enter book details:" << endl;
        book.getData();

        cout << "\nEnter tape details:" << endl;
        tape.getData();

        cout << "\nBook details:" << endl;
        book.displayData();

        cout << "\nTape details:" << endl;
        tape.displayData();
    } catch (const exception& e) {
        cerr << "Exception caught: " << e.what() << endl;
        // If an exception is caught, reset data members to zero
        Book book;
        Tape tape;
        cout << "Book details after exception handling:" << endl;
        book.displayData();
        cout << "Tape details after exception handling:" << endl;
        tape.displayData();
    }

    return 0;
}
/*Created by jayesh pandey*/
