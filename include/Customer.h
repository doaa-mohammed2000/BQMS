#ifndef CLIENT _H
#define CLIENT _H
#pragma once

#include <string>
#include <ctime>
#include <iostream>
using namespace std;
class Customer {
public:
    string customerName;
    int age;
    int eventTime;
    string eventType = "Arrival";
    int waitingTime;
    int serviceTime;
bool isVIP;

    Customer(string name, int EventTime, int ServiceTime, bool isVIP)
    : customerName(name), eventTime(EventTime), serviceTime(ServiceTime), isVIP(isVIP) {}

    void Display()
    {
        cout << "--------------------------------------------------------------------------------\n";
        cout << "|Customer Name : " << this->customerName << " | "
            << "|Waiting Time : " << this->waitingTime << " | "
            << "|Service Time : " << this->serviceTime << " | "
            << "|Leave Time : " << this->eventTime << " | "
            << "|VIP : " << (isVIP ? "Yes" : "No") << " | " << endl;
    }
};

#endif // CLIENT _H
