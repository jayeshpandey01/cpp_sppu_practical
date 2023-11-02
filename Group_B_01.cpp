/*
Crete User defined exception to check the following conditions and throw the exception 
if the criterion does not meet. 
a. User has age between 18 and 55
b. User stays has income between Rs. 50,000 – Rs. 1,00,000 per month
c. User stays in Pune/ Mumbai/ Bangalore / Chennai
d. User has 4-wheeler Accept age, Income, City, Vehicle from the user and check for the conditions mentioned 
*/

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class CustomException : public exception {
private:
    string message;

public:
    CustomException(const string& msg) : message(msg) {}

    const char* what() const noexcept override {
        return message.c_str();
    }
};

int main() {
    int age;
    double income;
    string city;
    char vehicle;

    try {
        // Input user details
        cout << "Enter your age: ";
        cin >> age;
        cout << "Enter your monthly income (in Rs.): ";
        cin >> income;
        cout << "Enter your city (Pune/Mumbai/Bangalore/Chennai): ";
        cin >> city;
        cout << "Do you have a 4-wheeler (Y/N): ";
        cin >> vehicle;

        // Check the conditions
        if (age < 18 || age > 55) {
            throw CustomException("Age must be between 18 and 55.");
        }
        if (income < 50000.0 || income > 100000.0) {
            throw CustomException("Monthly income must be between Rs. 50,000 and Rs. 1,00,000.");
        }
        if (city != "Pune" && city != "Mumbai" && city != "Bangalore" && city != "Chennai") {
            throw CustomException("You must stay in Pune, Mumbai, Bangalore, or Chennai.");
        }
        if (vehicle != 'Y' && vehicle != 'N') {
            throw CustomException("Invalid choice for having a 4-wheeler.");
        }

        // If all conditions are met
        cout << "Congratulations! You meet all the criteria." << endl;
    } catch (const CustomException& ex) {
        cerr << "Error: " << ex.what() << endl;
    }

    return 0;
}
