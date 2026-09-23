#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
    string foodName;
    char itemCode;
    int quantity;
    double unitPrice;
    char member;

    cout << "Enter food name: ";
    getline(cin, foodName);

    cout << "Enter item code: ";
    cin >> itemCode;

    cout << "Enter quantity: ";
    cin >> quantity;

    cout << "Enter unit price: $";
    cin >> unitPrice;

    cout << "Are you a member? (y/n): ";
    cin >> member;

    double subtotal = quantity * unitPrice;

    double discount = 0.0;
    string cashiernotes;
    if (member == 'y' or member == 'Y')
    {
        discount = subtotal * 0.10;
    }
    cin.ignore();
    cout << "any notes?: ";
    getline(cin, cashiernotes);


    cout << "\n========== RECEIPT ==========\n";

    cout << left << setw(15) << "Food:"
        << right << setw(15) << foodName << endl;

    cout << left << setw(15) << "Item Code:"
        << right << setw(15) << itemCode << endl;

    cout << left << setw(15) << "Quantity:"
        << right << setw(15) << quantity << endl;

    cout << left << setw(15) << "Unit Price:"
        << right << setw(15) << fixed << setprecision(2)
        << unitPrice << endl;

    cout << left << setw(15) << "Subtotal:"
        << right << setw(15) << subtotal << endl;

    cout << "=============================\n";
    
    cout << left << setw(6) << "food" <<setw(10) << "itemCode"<<setw(10)<< "unitPrice"<< right<<setw(8)<<"units" << endl;
    cout << left << setw(6) << foodName << setw(10) << itemCode << setw(10) << unitPrice<< setw(8)<<quantity << endl;

    return 0;
}

//feat: Add basic receipt output and input formatting"