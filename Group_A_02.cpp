/*
Write a C++ program create a calculator for an arithmetic operator (+, -, *, /). The 
program should take two operands from user and performs the operation on those two 
operands depending upon the operator entered by user. Use a switch statement to select 
the operation. Finally, display the result.
*/

#include <iostream>
using namespace std;
int main() {
    char op;
    double operand1, operand2, result;

    // Input
    cout << "Enter the first operand: ";
    cin >> operand1;
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;
    cout << "Enter the second operand: ";
    cin >> operand2;

    // Perform the operation based on the operator
    switch (op) {
        case '+':
            result = operand1 + operand2;
            break;
        case '-':
            result = operand1 - operand2;
            break;
        case '*':
            result = operand1 * operand2;
            break;
        case '/':
            if (operand2 != 0) {
                result = operand1 / operand2;
            } else {
                cerr << "Error: Division by zero is not allowed." << std::endl;
                return 1; // Exit with an error code
            }
            break;
        default:
            cerr << "Error: Invalid operator entered." << std::endl;
            return 1; // Exit with an error code
    }

    // Output the result
    cout << "Result: " << result << std::endl;

    return 0;
}
/*Created by jayesh pandey*/
