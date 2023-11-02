/*
Write a C++ program that creates an output file, writes information to it, closes the file 
andopen it again as an input file and read the information from the file.
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    // Create an output file and write information to it
    ofstream outputFile("output.txt");
    if (!outputFile.is_open()) {
        scerr << "Failed to open the output file." << endl;
        return 1;
    }

    string data = "This is a sample text written to the file.";
    outputFile << data << endl;
    outputFile.close();

    // Open the same file as an input file and read the information
    ifstream inputFile("output.txt");
    if (!inputFile.is_open()) {
        cerr << "Failed to open the input file." << endl;
        return 1;
    }

    string readData;
    while (getline(inputFile, readData)) {
        cout << "Read from the file: " << readData << endl;
    }

    inputFile.close();

    return 0;
}
