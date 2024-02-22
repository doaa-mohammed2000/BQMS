#include "Customer.h"
#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    int numOfCustomers, tellersNumber;
    cout << "\t\t\t\t\t-------------------------------------------------" << endl;
    cout << "\t\t\t\t\t{                                                }" << endl;
    cout << " \t\t\t\t\t }    %%Bank Queue Management System(BQMS)%%    {\n";
    cout << "\t\t\t\t\t{                                                }" << endl;
    cout << "\t\t\t\t\t-------------------------------------------------" << endl;
    cout << endl;
    cout << "Enter Number of Customers You Want To Enter To The System:  ";
    cin >> numOfCustomers;
    cout << "Please Enter The Tellers Number: ";
    cin >> tellersNumber;
    Bank bank(tellersNumber);
    cout << "\n{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}" << endl;

    for (int i = 0; i < numOfCustomers; i++) {
        string customer_name;
        int arrival_time, service_time;
        bool isVIP;

        cout << "Enter Data of Customer " << i + 1 << ":" << endl;
        cout << "Name of Customer: ";
        cin >> customer_name;
        cout << "Arrival Time : ";
        cin >> arrival_time;
        cout << "Service Time : ";
        cin >> service_time;
        cout << "Is the customer VIP? (1 for Yes, 0 for No): ";
        cin >> isVIP;

       Customer customer(customer_name, arrival_time, service_time, isVIP);

        if (isVIP) {
            bank.addClientToPriorityQueue(customer);
        } else {
            bank.addClientToPriorityQueue(customer);
        }
        cout << "\n{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{}{" << endl;
    }

    system("cls");
    bank.run();
    return 0;
}
