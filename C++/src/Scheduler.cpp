#include "Scheduler.h"

#include <thread>
#include <chrono>

QueueManager::QueueManager()
    : m_table({ "ID", "Name", "Priority", "State", "Jobs Left" })
{
}

void QueueManager::addProcess(const PCB & pcb)
{
    m_queue.push_back(pcb);
}

void QueueManager::implementAlgorithm(Alogorithm alg)
{
    switch (alg) {
        case Alogorithm::FCFS:
            FCFS(CPUMode::Interrupt);
            break;

        case Alogorithm::RoundRobin:
            roundRobin(CPUMode::FixedCycle);
            break;
    }
}

void QueueManager::printQueue()
{
    for (auto& pcb : m_queue) {
        pcb.addToTable(m_table);
    }
    m_table.print();
    m_table.clear();
}

void QueueManager::FCFS(CPUMode mode)
{
    for (auto& pcb : m_queue) {
        processSwitchOverhead();
        for (int i = 0; i < pcb.getJobLength(); i++) {
            pcb.reduceJob();
            pcb.setState(State::Processing);
            printQueue();
            processExecuteOverhead();
            if (pcb.getJobLength() <= 0) {
                pcb.setState(State::Terminated);
                printQueue();
            }
        }
    }
}

void QueueManager::roundRobin(CPUMode mode)
{
}

void QueueManager::processSwitchOverhead()
{
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

void QueueManager::processExecuteOverhead()
{
    std::this_thread::sleep_for(std::chrono::seconds(1));
}
