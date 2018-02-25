#include <iostream>
#include "Scheduler.h"

void init(QueueManager& manager)
{
    manager.addProcess({"Augmented Browser",       "AB",   34, State::Waiting, 72});
    manager.addProcess({"Augmented Media Player",  "AMP",  56, State::Waiting, 452});
    manager.addProcess({"Augmented Browser",       "AB",   23, State::Waiting, 33});
    //manager.printQueue();
}

int main()
{
    QueueManager manager;
    init(manager);
    manager.implementAlgorithm(Alogorithm::RoundRobin);
}