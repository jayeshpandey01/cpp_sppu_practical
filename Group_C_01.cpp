/*
Write C++ program using STL for sorting and searching with user defined records such as 
person record(Name, DOB, Telephone number), Item record (Item code, name, 
cost,quantity) using vector container
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// Person record structure
struct PersonRecord {
    string name;
    string dob;
    string phoneNumber;
};

// Item record structure
struct ItemRecord {
    int itemCode;
    string name;
    double cost;
    int quantity;
};

// Function to print a person record
void printPersonRecord(const PersonRecord& person) {
    cout << "Name: " << person.name << ", DOB: " << person.dob << ", Telephone: " << person.phoneNumber << endl;
}

// Function to print an item record
void printItemRecord(const ItemRecord& item) {
    cout << "Item Code: " << item.itemCode << ", Name: " << item.name << ", Cost: " << item.cost << ", Quantity: " << item.quantity << endl;
}

int main() {
    vector<PersonRecord> personRecords;
    vector<ItemRecord> itemRecords;

    // Input person records
    personRecords.push_back({ "Alice", "1990-01-15", "123-456-7890" });
    personRecords.push_back({ "Bob", "1985-05-20", "987-654-3210" });
    personRecords.push_back({ "Charlie", "1995-08-10", "111-222-3333" });

    // Input item records
    itemRecords.push_back({ 101, "Book", 15.99, 50 });
    itemRecords.push_back({ 102, "Laptop", 899.99, 10 });
    itemRecords.push_back({ 103, "Phone", 399.99, 20 });

    // Sort person records by name
    sort(personRecords.begin(), personRecords.end(), [](const PersonRecord& a, const PersonRecord& b) {
        return a.name < b.name;
    });

    // Sort item records by item code
    ssort(itemRecords.begin(), itemRecords.end(), [](const ItemRecord& a, const ItemRecord& b) {
        return a.itemCode < b.itemCode;
    });

    // Print sorted records
    cout << "Sorted Person Records:" << endl;
    for (const auto& person : personRecords) {
        printPersonRecord(person);
    }

    cout << "\nSorted Item Records:" << endl;
    for (const auto& item : itemRecords) {
        printItemRecord(item);
    }

    // Search for a person by name
    string searchName = "Bob";
    auto personIt = find_if(personRecords.begin(), personRecords.end(), [&searchName](const PersonRecord& person) {
        return person.name == searchName;
    });

    if (personIt != personRecords.end()) {
        cout << "\nFound Person Record:" << endl;
        printPersonRecord(*personIt);
    } else {
        cout << "\nPerson not found." << endl;
    }

    // Search for an item by item code
    int searchItemCode = 102;
    auto itemIt = find_if(itemRecords.begin(), itemRecords.end(), [&searchItemCode](const ItemRecord& item) {
        return item.itemCode == searchItemCode;
    });

    if (itemIt != itemRecords.end()) {
        cout << "\nFound Item Record:" << endl;
        printItemRecord(*itemIt);
    } else {
        cout << "\nItem not found." << endl;
    }

    return 0;
}
/*Created by jayesh pandey*/
