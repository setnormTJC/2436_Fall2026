#include <iostream>
#include<queue>
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
    std::string name;
    int priority = 0; //how important is this task? higher number means higher priority

    //the part I was failing to remember at the end of last lecture (Oct. 29)
    bool operator < (const Process& other) const
    {
        return this->priority < other.priority;
    }

};

int main()
{
    // Demos::demoCircularStaticQueueAlgos();

    //a smarter, simpler intro to priority_queue
    std::priority_queue<int> nums;
    nums.push(1);
    nums.push(11);
    nums.push(-233);

    //what I was doing last time:
    std::priority_queue<Process> priorityQueue;

    Process firstProcess("A", 1);
    priorityQueue.push(firstProcess);

    //add another process with higher priority:
    priorityQueue.push({"B", 23});

}
