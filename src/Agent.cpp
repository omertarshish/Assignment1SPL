#include "Agent.h"
#include "Simulation.h"
#include "SelectionPolicy.h"
#include "Party.h"
#include "Coalition.h"

Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy) : mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy) , indexCoalition(mAgentId){
}
    

 Agent::Agent(int agentId, int partyId, SelectionPolicy *selectionPolicy , int indexC):
    mAgentId(agentId), mPartyId(partyId), mSelectionPolicy(selectionPolicy->clone()) , indexCoalition(indexC){
    }


int Agent::getId() const
{
    return mAgentId;
}

int Agent::getPartyId() const
{
    return mPartyId;
}

int Agent::getCoalition() const
{
    return indexCoalition;
}


Agent Agent::clone(int newAgentId, int otherPartyId){
    return Agent(newAgentId, otherPartyId, mSelectionPolicy, indexCoalition);
}




void Agent::setCoalition(int indexC){
    indexCoalition = indexC;
}

void Agent::step(Simulation &sim)
{
    vector<int> vec = sim.getGraph().p_neighborsForSelect(mPartyId , indexCoalition);
    int chosen = mSelectionPolicy->run(vec , sim , mPartyId);
    if (chosen != -1){
        sim.getGraph().addOffer(indexCoalition , mAgentId , chosen);
    } 
}

//destructor
Agent::~Agent(){
    if(mSelectionPolicy) delete mSelectionPolicy;
}

//copy constructor
Agent::Agent(const Agent &other) : mAgentId(other.mAgentId) , mPartyId(other.mPartyId) , mSelectionPolicy(other.mSelectionPolicy->clone()) , indexCoalition(other.indexCoalition) {

}

//move constructor
Agent::Agent(Agent && other) : mAgentId(other.mAgentId) , mPartyId(other.mPartyId) , mSelectionPolicy(other.mSelectionPolicy) , indexCoalition(other.indexCoalition){
    other.mSelectionPolicy = nullptr;
  }

// copy assignment operator
Agent& Agent::operator=(const Agent &other){
    *mSelectionPolicy = (*(other.mSelectionPolicy));
    return *this;
}


// move assignment operator
Agent& Agent::operator=(Agent &&other){
    if(mSelectionPolicy) delete mSelectionPolicy;
    mSelectionPolicy = other.mSelectionPolicy;
    other.mSelectionPolicy = nullptr;
    return *this;
}
