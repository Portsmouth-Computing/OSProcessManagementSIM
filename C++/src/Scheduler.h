#pragma once

#include "PCB.h"
#include "Globals.h"
#include "TablePrinter.h"

#include <vector>

class QueueManager
{
    public:
        QueueManager();

        void addProcess(const PCB& pcb);
        void implementAlgorithm(Alogorithm alg);

    private:
        void printQueue();

        void FCFS(CPUMode mode);
        void roundRobin(CPUMode mode);


        void processSwitchOverhead();
        void processExecuteOverhead();

        std::vector<PCB> m_queue;
        int m_processSwitches = 0;
        TablePrinter m_table;
};