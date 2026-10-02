#include <iostream>

using namespace std;

/**
 * @brief Interactive Arithmetic & Safe Calculator Console
 * Demonstrates procedural control flow, error checking, and arithmetic operation dispatching.
 */
int main()
{
    int operation = 0;
    double number1 = 0.0;
    double number2 = 0.0;

    cout << "====================================================\n";
    cout << "          Interactive C++ Calculator                \n";
    cout << "====================================================\n";

    while (true)
    {
        cout << "\nChoose an operation:\n";
        cout << "  1. Addition (+)\n";
        cout << "  2. Subtraction (-)\n";
        cout << "  3. Multiplication (*)\n";
        cout << "  4. Division (/)\n";
        cout << "  5. Exit\n";
        cout << "Enter selection (1-5): ";
        
        if (!(cin >> operation)) {
            cerr << "Invalid input format. Exiting.\n";
            break;
        }

        if (operation == 5) {
            cout << "Exiting calculator. Goodbye!\n";
            break;
        }

        if (operation < 1 || operation > 5) {
            cout << "Please select a valid option from 1 to 5.\n";
            continue;
        }

        cout << "Enter first number: ";
        cin >> number1;
        cout << "Enter second number: ";
        cin >> number2;

        switch (operation)
        {
        case 1:
            cout << "\nResult: " << number1 << " + " << number2 << " = " << (number1 + number2) << "\n";
            break;
        case 2:
            cout << "\nResult: " << number1 << " - " << number2 << " = " << (number1 - number2) << "\n";
            break;
        case 3:
            cout << "\nResult: " << number1 << " * " << number2 << " = " << (number1 * number2) << "\n";
            break;
        case 4:
            if (number2 == 0.0) {
                cerr << "\nError: Division by zero is undefined!\n";
            } else {
                cout << "\nResult: " << number1 << " / " << number2 << " = " << (number1 / number2) << "\n";
            }
            break;
        }

        cout << "\n----------------------------------------------------\n";
    }

    return 0;
}
