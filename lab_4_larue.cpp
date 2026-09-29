#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string foodName;
    char itemChoice;
    char sizeChoice;
    int quantity;
    double unitPrice = 0.0;
    char member;
    string cashiernotes;

    cout << "              Small   Medium   Large" << endl;
    cout << "A. Hot dog     5.00     6.00     7.00" << endl;
    cout << "B. Dumplings   6.00     7.00     8.00" << endl;
    cout << "C. 1 chip      4.00     5.00     6.00" << endl;
    cout << "D. Halo 3      2.00     3.00     4.00" << endl;

    cout << endl;

    cout << "Choose an item (A-D): ";
    cin >> itemChoice;

    cout << "Choose a size (s, m, l): ";
    cin >> sizeChoice;

    switch (itemChoice)
    {
    case 'A':
    case 'a':
        foodName = "Hot Dog";

        if (sizeChoice == 's' || sizeChoice == 'S')
            unitPrice = 5.00;
        else if (sizeChoice == 'm' || sizeChoice == 'M')
            unitPrice = 6.00;
        else if (sizeChoice == 'l' || sizeChoice == 'L')
            unitPrice = 7.00;
        break;

    case 'B':
    case 'b':
        foodName = "Dumplings";

        if (sizeChoice == 's' || sizeChoice == 'S')
            unitPrice = 6.00;
        else if (sizeChoice == 'm' || sizeChoice == 'M')
            unitPrice = 7.00;
        else if (sizeChoice == 'l' || sizeChoice == 'L')
            unitPrice = 8.00;
        break;

    case 'C':
    case 'c':
        foodName = "1 chip";

        if (sizeChoice == 's' || sizeChoice == 'S')
            unitPrice = 4.00;
        else if (sizeChoice == 'm' || sizeChoice == 'M')
            unitPrice = 5.00;
        else if (sizeChoice == 'l' || sizeChoice == 'L')
            unitPrice = 6.00;
        break;

    case 'D':
    case 'd':
        foodName = "Halo 3";

        if (sizeChoice == 's' || sizeChoice == 'S')
            unitPrice = 2.00;
        else if (sizeChoice == 'm' || sizeChoice == 'M')
            unitPrice = 3.00;
        else if (sizeChoice == 'l' || sizeChoice == 'L')
            unitPrice = 4.00;
        break;

    default:
        cout << "Invalid item." << endl;
        return 0;
    }

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Are you a member? (y/n): ";
    cin >> member;

    double subtotal = quantity * unitPrice;

    double discount = 0.0;

    if (member == 'y' || member == 'Y')
    {
        discount = subtotal * 0.10;
        subtotal = subtotal - discount;
    }

    cin.ignore();

    cout << "Any notes?: ";
    getline(cin, cashiernotes);

    cout << "\n           RECEIPT            \n";

    cout << left << setw(15) << "Food:"
        << right << setw(15) << foodName << endl;

    cout << left << setw(15) << "Size:"
        << right << setw(15) << sizeChoice << endl;

    cout << left << setw(15) << "Quantity:"
        << right << setw(15) << quantity << endl;

    cout << left << setw(15) << "Unit Price:"
        << right << setw(15) << fixed << setprecision(2)
        << unitPrice << endl;

    cout << left << setw(15) << "Subtotal:"
        << right << setw(15) << subtotal << endl;

    return 0;
}