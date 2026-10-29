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

int main()
{
    // // Demos::demoCircularStaticQueueAlgos();
    //
    std::deque<Customer> customers; //customers in line at a grocery store
    //
    //customers.push_back({"Alice", 1});
    customers.push_back(Customer("Alice", 1));
    customers.push_back(Customer("Bob", 2));
    customers.push_back(Customer("Carol", 3));
    //
    Customer someCustomer = {"Very important person", 12};
    if (someCustomer.name == "Very important person")
    {
         customers.push_front(someCustomer);
    }
    //
    else
    {
         customers.push_back(someCustomer);
    }
    //
    simulateCheckoutLane(customers);


}
