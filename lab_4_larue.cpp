#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

int main()
{
    string customerName;
    string foodName;

    char itemChoice;
    char sizeChoice;
    int quantity;

    double unitPrice = 0.0;
    double orderSubtotal = 0.0;
    double itemSubtotal = 0.0;

    // Accumulator to track ordered items for the receipt (name, qty, subtotal)
    string orderDetails = "";

    // Track daily totals
    double grandTotalSales = 0.0;
    int totalCustomers = 0;
    char anotherCustomer = 'y';

    char member;
    string cashiernotes;

    // Loop to simulate an entire day's worth of customers
    do
    {
        cout << "Enter customer name: ";
        getline(cin, customerName);

        // reset per-customer accumulators
        orderSubtotal = 0.0;
        orderDetails.clear();

    // Loop keeps running until customer chooses Checkout
    do
    {
        cout << "\n              Small   Medium   Large" << endl;
        cout << "A. Hot dog     5.00     6.00     7.00" << endl;
        cout << "B. Dumplings   6.00     7.00     8.00" << endl;
        cout << "C. 1 chip      4.00     5.00     6.00" << endl;
        cout << "D. Halo 3      2.00     3.00     4.00" << endl;
        cout << "E. Checkout" << endl;

        cout << "\nChoose an item (A-E): ";
        cin >> itemChoice;


        while (itemChoice != 'A' && itemChoice != 'a' &&
            itemChoice != 'B' && itemChoice != 'b' &&
            itemChoice != 'C' && itemChoice != 'c' &&
            itemChoice != 'D' && itemChoice != 'd' &&
            itemChoice != 'E' && itemChoice != 'e')
        {
            cout << "Invalid choice. Choose A-E: ";
            cin >> itemChoice;
        }

        if (itemChoice == 'E' || itemChoice == 'e')
        {
            break;
        }

        cout << "Choose a size (s, m, l): ";
        cin >> sizeChoice;


        while (sizeChoice != 's' && sizeChoice != 'S' &&
            sizeChoice != 'm' && sizeChoice != 'M' &&
            sizeChoice != 'l' && sizeChoice != 'L')
        {
            cout << "Invalid size. Choose s, m, or l: ";
            cin >> sizeChoice;
        }

        unitPrice = 0.0;

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
        }

        cout << "Enter quantity: ";
        cin >> quantity;


        while (quantity <= 0)
        {
            cout << "Invalid quantity. Enter at least 1: ";
            cin >> quantity;
        }


        itemSubtotal = quantity * unitPrice;


        orderSubtotal = orderSubtotal + itemSubtotal;

        // Build a receipt line for this item and append to the accumulator.
        // Use a string stream so monetary values are formatted to 2 decimal places.
        // Format: <name> x<quantity>  $<itemSubtotal>\n
        {
            ostringstream oss;
            oss << fixed << setprecision(2) << itemSubtotal;
            orderDetails += foodName + " x" + to_string(quantity) + "  $" + oss.str() + "\n";
        }

        cout << "Item added to order." << endl;

    } while (itemChoice != 'E' && itemChoice != 'e');



    cout << "\nAre you a member? (y/n): ";
    cin >> member;

    double subtotal = orderSubtotal;
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
        cout << "Enter custom tip percentage: ";

        double customPct = 0.0;
        cin >> customPct;

        tipRate = customPct / 100.0;
    }

    tip = subtotal * tipRate;

    double grandTotal = total + tip;


    cout << "\n           RECEIPT            \n";

    cout << "Customer: " << customerName << endl;

    cout << fixed << setprecision(2);

    
    cout << "\nItems:\n";
    cout << orderDetails;

    cout << left << setw(25) << "Order Subtotal:" 
        << right << setw(15) << orderSubtotal << endl;

    cout << left << setw(25) << "Discount:"
        << right << setw(15) << discount << endl;

    cout << left << setw(25) << "AR State Tax (6.5%):"
        << right << setw(15) << tax1 << endl;

    cout << left << setw(25) << "Faulkner County Tax:"
        << right << setw(15) << tax2 << endl;

    cout << left << setw(25) << "Conway Mun. Tax:"
        << right << setw(15) << tax3 << endl;

    cout << left << setw(25) << "Total Tax:"
        << right << setw(15) << totalTax << endl;

    cout << left << setw(25) << "Total (before tip):"
        << right << setw(15) << total << endl;

    cout << left << setw(25) << "Tip:"
        << right << setw(15) << tip << endl;

    cout << left << setw(25) << "Grand Total:"
        << right << setw(15) << grandTotal << endl;

    cout << "Notes: " << cashiernotes << endl;

    
    int loyaltyPoints = static_cast<int>(floor(total / 3.0));
    
    cout << left << setw(25) << "Loyalty Points:" << right << setw(15) << (to_string(loyaltyPoints) + "*") << endl;

    
    grandTotalSales += grandTotal;
    totalCustomers++;

    cout << "\nAnother customer? (y/n): ";
    cin >> anotherCustomer;
    cin.ignore();

    } while (anotherCustomer == 'y' || anotherCustomer == 'Y');

    
    cout << "\nDaily Summary:\n";
    cout << fixed << setprecision(2);
    cout << left << setw(25) << "Total Customers:" << right << setw(15) << totalCustomers << endl;
    cout << left << setw(25) << "Total Sales:" << right << setw(15) << grandTotalSales << endl;

    return 0;
}
