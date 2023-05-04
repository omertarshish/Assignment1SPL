#pragma once

#include <vector>
#include "Graph.h"
#include "Coalition.h"
class SelectionPolicy;

class Agent

{
public:
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy);
    Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy , int indexCoalition);

    int getPartyId() const;
    int getId() const;
    int getCoalition() const ;
    void step(Simulation &);
    void setCoalition(int index);
    Agent clone(int newId, int otherPartyId);
    ~Agent();
    Agent(const Agent &other);
    Agent(Agent && other);
    Agent& operator=(const Agent &other);
    Agent& operator=(Agent &&other);


private:
    int mAgentId;
    int mPartyId;
    SelectionPolicy *mSelectionPolicy;
    int indexCoalition;
};