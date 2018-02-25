#pragma once

enum class CPUMode
{
    Interrupt = 0,
    FixedCycle = 1
};

enum class State
{
    Processing = 0,
    Terminated = 1,
    Waiting = 2
};

enum class Alogorithm
{
    FCFS,
    RoundRobin
};