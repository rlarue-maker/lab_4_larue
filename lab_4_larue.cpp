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
    double tax1Rate = 0.065;
    double tax2Rate = 0.005;
    double tax3Rate = 0.02125;


    double tax1 = subtotal * tax1Rate;
    double tax2 = subtotal * tax2Rate;
    double tax3 = subtotal * tax3Rate;
    double totalTax = tax1 + tax2 + tax3;
    double total = subtotal + totalTax;


    int tipChoice = 0;
    double tipRate = 0.0;
    double tip = 0.0;

    cout << "\nTip options (applied to pre-tax total):\n";
    cout << "1. 15%\n";
    cout << "2. 20%\n";
    cout << "3. 25%\n";
    cout << "4. Custom percentage\n";
    cout << "Choose tip option (1-4): ";
    cin >> tipChoice;

    if (tipChoice == 1)
        tipRate = 0.15;
    else if (tipChoice == 2)
        tipRate = 0.20;
    else if (tipChoice == 3)
        tipRate = 0.25;
    else if (tipChoice == 4)
    {
        cout << "Enter custom tip percentage (ex: 12.5 for 12.5%): ";
        double customPct = 0.0;
        cin >> customPct;
        tipRate = customPct / 100.0;
    }

    tip = subtotal * tipRate;
    double grandTotal = total + tip;

    cout << "\n           RECEIPT            \n";


    cout << fixed << setprecision(2);

    cout << left << setw(15) << "Food:"
        << right << setw(15) << foodName << endl;

    cout << left << setw(15) << "Size:"
        << right << setw(15) << sizeChoice << endl;

    cout << left << setw(15) << "Quantity:"
        << right << setw(15) << quantity << endl;

    cout << left << setw(15) << "Unit Price:"
        << right << setw(15) << unitPrice << endl;

    cout << left << setw(15) << "Subtotal:"
        << right << setw(15) << subtotal << endl;

    cout << left << setw(15) << "Discount:"
        << right << setw(15) << discount << endl;

    cout << left << setw(15) << "Ar state Tax (6.5%):"
        << right << setw(15) << tax1 << endl;

    cout << left << setw(15) << "Faulkner County Tax (0.5%):"
        << right << setw(15) << tax2 << endl;

    cout << left << setw(15) << "Conway mun. Tax (2.125%):"
        << right << setw(15) << tax3 << endl;

    cout << left << setw(15) << "Total Tax:"
        << right << setw(15) << totalTax << endl;

    cout << left << setw(15) << "Total (before tip):"
        << right << setw(15) << total << endl;

    cout << left << setw(15) << "Tip:"
        << right << setw(15) << tip << endl;

    cout << left << setw(15) << "Grand Total:"
        << right << setw(15) << grandTotal << endl;

    return 0;
}