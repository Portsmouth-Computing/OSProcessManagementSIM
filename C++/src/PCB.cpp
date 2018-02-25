#include "PCB.h"

PCB::PCB(const std::string& name, const std::string & id, int priority, State state, int jobLength)
    :   m_name      (name)
    ,   m_id        (id)
    ,   m_priority  (priority)
    ,   m_state     (state)
    ,   m_jobLength (jobLength)
{

}

void PCB::reduceJob()
{
    m_jobLength--;
}
