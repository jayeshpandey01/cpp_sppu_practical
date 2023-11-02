/*
A book shop maintains the inventory of books that are being sold at the shop. The list 
includes details such as author, title, price, publisher and stock position. Whenever a 
customer wants a book, the sales person inputs the title and author and the system 
searches the list and displays whether it is available or not. If it is not, an appropriate 
message is displayed. If it is, then the system displays the book details and requests for 
the number of copies required. If the requested copies book details and requests for the 
number of copies required. If the requested copies are available, the total cost of the 
requested copies is displayed; otherwise the message Required copies not in stock is 
displayed. Design a system using a class called books with suitable member functions and 
Constructors. Use new operator in constructors to allocate memory space required. 
Implement C++ program for the system.
*/

#include <iostream>
#include <string>
using namespace std;
class Book {
private:
    string title;
    string author;
    double price;
    string publisher;
    int stock;

public:
    // Constructor to initialize a book
    Book(const string& title, const string& author, double price, const string& publisher, int stock)
        : title(title), author(author), price(price), publisher(publisher), stock(stock) {}

    // Function to check if a book is available
    bool isAvailable(const string& searchTitle, const string& searchAuthor) const {
        return (title == searchTitle && author == searchAuthor && stock > 0);
    }

    // Function to calculate the cost for a given number of copies
    double calculateCost(int copies) const {
        return copies * price;
    }

    // Display book details
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Price: $" << price << endl;
        cout << "Publisher: " << publisher << endl;
        cout << "Stock: " << stock << " copies" << endl;
    }
};

int main() {
    // Create an array to store book objects
    const int maxBooks = 5;
    Book books[maxBooks] = {
        Book("Book1", "Author1", 20.0, "Publisher1", 10),
        Book("Book2", "Author2", 25.0, "Publisher2", 5),
        Book("Book3", "Author3", 18.0, "Publisher3", 15),
        Book("Book4", "Author4", 30.0, "Publisher4", 8),
        Book("Book5", "Author5", 22.0, "Publisher5", 12)
    };

    string searchTitle, searchAuthor;
    int copies;

    // Input title and author to search for a book
    cout << "Enter the title of the book: ";
    cin >> searchTitle;
    cout << "Enter the author of the book: ";
    cin >> searchAuthor;

    bool bookFound = false;

    // Search for the book
    for (const Book& book : books) {
        if (book.isAvailable(searchTitle, searchAuthor)) {
            bookFound = true;
            book.display();
            cout << "Enter the number of copies required: ";
            cin >> copies;

            if (copies <= book.calculateCost(copies)) {
                cout << "Total cost: $" << book.calculateCost(copies) << endl;
            } else {
                cout << "Required copies not in stock." << endl;
            }
        }
    }

    if (!bookFound) {
        cout << "The book is not available in the inventory." << endl;
    }

    return 0;
}
/*Created by jayesh pandey*/
