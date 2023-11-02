/*
Write a program in C++ to use map associative container. The keys will be the names of 
states, and the values will be the populations of the states. When the program runs, the 
user is prompted to type the name of a state. The program then looks in the map, using 
the state name as an index, and returns the population of the state.
*/

#include <iostream>
#include <map>
#include <string>
using namespace std;
int main() {
    map<string, long long> statePopulations;

    // Populate the map with state names and populations
    statePopulations["California"] = 39538223; // Example population for California
    statePopulations["Texas"] = 29145505;      // Example population for Texas
    statePopulations["New York"] = 20380482;   // Example population for New York
    statePopulations["Florida"] = 21538187;    // Example population for Florida
    // Add more states and populations as needed

    string stateName;

    // Prompt the user to enter a state name
    cout << "Enter the name of a state: ";
    getline(cin, stateName);

    // Look up the state population in the map
    auto it = statePopulations.find(stateName);

    if (it != statePopulations.end()) {
        // State found, print its population
        cout << "The population of " << stateName << " is " << it->second << " people." << endl;
    } else {
        // State not found in the map
        cout << "State not found in the database." << endl;
    }

    return 0;
}
/*Created by jayesh pandey*/
