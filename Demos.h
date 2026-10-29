//
// Created by Work on 10/22/2026.
//

#ifndef INC_2436_FALL2026_DEMOS_H
#define INC_2436_FALL2026_DEMOS_H
#include <iostream>
#include <queue>

#include "QueueAbstractDataType.h"

namespace Demos
{
    void printQueue(std::queue<std::string> queue)//pass by value!
    {
        while (queue.empty() == false)
        {
            std::cout << queue.front() << std::endl; //
            queue.pop(); //removes first element (ex: Alice in example in main)
        }
    }
    void demoOption1FromQueueAssignment()
    {
        struct PrinterJob
        {
            int numberOfPages = 5;
            std::string name = "Alpha";
        };

        std::queue<PrinterJob> runningJobs;
        std::queue<PrinterJob> sleepingJobs;

        runningJobs.push({3, "Bravo"}); //suppose Bravo is using the printer in this room
        //suppose a process named "Charlie" also needs the printer
        int MAX_NUMBER_OF_RUNNING_JOBS = 10;
        if (runningJobs.size() >= MAX_NUMBER_OF_RUNNING_JOBS)
        {
            runningJobs.push({5, "Charlie"});
        }

        else
        {
            std::cout << "You have to wait until the number of jobs in the running queue gets smaller" << std::endl;
        }
    }

    void demoCircularStaticQueueAlgos()
    {
        QueueImplementedWithCircularArray queue; //max size (capacity) is 3 (see the header file)

        queue.pushBack("Alice");
        queue.pushBack("Bob");
        queue.pushBack("Carol");
        queue.pushBack("Darth"); //triggers full queue exception (Darth will NOT get into the queue)
        queue.popFront(); //cases index of first element to become 1 (not 0, as is always the case in a "linear array")
        queue.pushBack("Eve"); //causes index of last element to wrap around to 0!

        queue.traverse();


    }

}

#endif //INC_2436_FALL2026_DEMOS_H
