#ifndef BANK_H
#define BANK_H
#pragma once
#include<iostream>
#include "Customer.h"
#include <queue>
#include <list>
#include <iterator>
using namespace std;


class compareEventTime {
public:
    bool operator()(const Customer& customer1, const Customer& customer2) const {

        if (customer1.eventTime >= customer2.eventTime) {
            return true;
        } else if (customer1.eventTime <= customer2.eventTime) {
            return false;
        } else {
            return customer1.isVIP && !customer2.isVIP;
        }
    }
};

class Bank
{
private:
    priority_queue<Customer, vector<Customer>, compareEventTime> customerPriorityQueue; // main queue
    list<int> tellerList;
    queue<Customer> normalCustomer;
    int currentTimeOfBank = 0;
    int TotalWaitingTime = 0;
    int TotalServiceTime = 0;
    int countOfCustomers = 0;

public:
    Bank(int tellerListSize)
    {
        for (int i = 0; i < tellerListSize; ++i)
        {
            tellerList.push_back(1);
        }
    }

    void addClientToPriorityQueue(const Customer& PriorityCustomer)
    {
        customerPriorityQueue.push(PriorityCustomer);
    }

    void addClientToNormalQueue(const Customer& NormalCustomer)
    {
        normalCustomer.push(NormalCustomer);
    }

    void DisplayAverages()
    {
          cout<<"--------------------------------------------------------------------------------\n";
	    cout<<"\n\n\n";
	    cout<<"\t\t\t\t-------------------------------------------------\n";
	    cout<<"\t\t\t\t(         Total Service Time: "<<TotalServiceTime <<"              )\n";
        cout<<"\t\t\t\t-------------------------------------------------\n";

        cout<<"\t\t\t\t-------------------------------------------------\n";
	    cout<<"\t\t\t\t(         Average Service Time: "<<TotalServiceTime/countOfCustomers <<"             )\n";
        cout<<"\t\t\t\t-------------------------------------------------\n";

        cout<<"\t\t\t\t-------------------------------------------------\n";
	    cout<<"\t\t\t\t(         Total Waiting Time: "<<TotalWaitingTime <<"               )\n";
        cout<<"\t\t\t\t-------------------------------------------------\n";

        cout<<"\t\t\t\t-------------------------------------------------\n";
	    cout<<"\t\t\t\t(         Average Waiting Time: "<<TotalWaitingTime/countOfCustomers <<"               )\n";
        cout<<"\t\t\t\t-------------------------------------------------\n";


    }

    void run()
    {
        while (!customerPriorityQueue.empty())
        {
            Customer currentPriorityCustomer = customerPriorityQueue.top();
            currentTimeOfBank = currentPriorityCustomer.eventTime;
            customerPriorityQueue.pop();

            if (currentPriorityCustomer.eventType == "Arrival")
            {
                if (!tellerList.empty())
                {
                    currentPriorityCustomer.waitingTime = currentTimeOfBank - currentPriorityCustomer.eventTime;
                    currentPriorityCustomer.eventTime = currentTimeOfBank + currentPriorityCustomer.serviceTime;

                    TotalWaitingTime += currentPriorityCustomer.waitingTime;
                    TotalServiceTime += currentPriorityCustomer.eventTime;
                    currentPriorityCustomer.eventType = "Leave";
                    countOfCustomers++;
                    currentPriorityCustomer.Display();


                    tellerList.pop_front();

                    addClientToPriorityQueue(currentPriorityCustomer);
                }
                else
                {
                    addClientToNormalQueue(currentPriorityCustomer);
                }
            }
            else if (currentPriorityCustomer.eventType == "Leave")
            {
                if (!normalCustomer.empty())
                {
                    Customer currentNormalCustomer = normalCustomer.front();
                    normalCustomer.pop();

                    currentNormalCustomer.waitingTime = currentTimeOfBank - (currentNormalCustomer.eventTime);
                    currentNormalCustomer.eventTime = currentTimeOfBank + currentNormalCustomer.serviceTime;

                    TotalWaitingTime += currentNormalCustomer.waitingTime;
                    TotalServiceTime += currentNormalCustomer.eventTime;
                    countOfCustomers++;
                    currentNormalCustomer.eventType = "Leave";

                    currentNormalCustomer.Display();

                    addClientToPriorityQueue(currentNormalCustomer);
                }
                else
                {
                    tellerList.push_back(1);
                }
            }
        }
        DisplayAverages();
    }
};

#endif // BANK_H
