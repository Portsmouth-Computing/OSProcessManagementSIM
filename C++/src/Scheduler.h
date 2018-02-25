#pragma once

#include "PCB.h"
#include "Globals.h"

#include <vector>

class QueueManager
{
    public:
        void addProcess(const PCB& pcb);
        void implementAlgorithm(Alogorithm alg);

    private:
        void FCFS(CPUMode mode);
        void roundRobin(CPUMode mode);


        void processSwitchOverhead();
        void processExecuteOverhead();

        std::vector<PCB> m_queue;
        int m_processSwitches = 0;
};