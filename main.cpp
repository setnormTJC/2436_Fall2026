#include <algorithm>
#include <iostream>
#include<queue> //gives access to queue, deque, priority queue
#include <memory>

#include"Customer.h"
#include "Demos.h"
#include "QueueAbstractDataType.h"

///@param customers -> passed in by VALUE (so we don't "accidentally" empty the
int getTotalItemCountOfAllCustomers_exceptLastCustomer(std::deque<Customer> customers)
{
    int totalItemCount = 0;

    int numberOfItemsFrontCustomerHas = 0;
    while (customers.empty() == false)
    {
        numberOfItemsFrontCustomerHas = customers.front().numberOfItems;

        totalItemCount += numberOfItemsFrontCustomerHas;

        customers.pop_front();
    }

    return totalItemCount - numberOfItemsFrontCustomerHas;
}


///@brief runs through all customers in the lane and checks them out
void simulateCheckoutLane(std::deque<Customer>& customers)
{
    while (!customers.empty())
    {
        //first, perhaps someone gets impatient, and they want to leave the queue:
        if (getTotalItemCountOfAllCustomers_exceptLastCustomer(customers) > 10)
        {
            std::cout << "The customer who was last in line got impatient and left the queue" << std::endl;
            customers.pop_back(); //this method is exclusive to the DEQUE data structure
        }

        Customer front = customers.front();

        std::cout << "Checking out " << front.name << " who has this many items: " << front.numberOfItems
            << std::endl;

        customers.pop_front(); //removes first customer from the line

    }
}

class Process
{
public:
    std::string id; //leave it as the empty string
    int priority = 0; //higher number means greater priority

    ///@brief compares processes by their priority (not by their id)
     bool operator < (const Process& rightHandSideProcess) const
     {
         if (this->priority < rightHandSideProcess.priority)
         {
             return true;
         }
         else
         {
             return false;
         }
     }
};


int main()
{
    std::vector<Process> processes;

    processes.push_back({"A", 1});
    processes.push_back({"B", 22});
    processes.push_back({"C", 3});

    std::sort(processes.begin(), processes.end());

    std::priority_queue<Process> priorityQueue;

    Process firstProcess = {"A", 2};

    priorityQueue.push(firstProcess);

    priorityQueue.push({"B", 3});

    // std::priority_queue<int> priorityQueue;
    //
    // priorityQueue.push(1);
    // priorityQueue.push(-1);
    // priorityQueue.push(3);
    //
    // int dummyBreakPointVariable = 123;
    //
    // priorityQueue.pop();

    // // Demos::demoCircularStaticQueueAlgos();
    //
    // //a smarter, simpler intro to priority_queue
    // std::priority_queue<int> nums;
    // nums.push(1);
    // nums.push(11);
    // nums.push(-233);
    //
    // //what I was doing last time:
    // std::priority_queue<Process> priorityQueue;
    //
    // Process firstProcess("A", 1);
    // priorityQueue.push(firstProcess);
    //
    // //add another process with higher priority:
    // priorityQueue.push({"B", 23});

}
