#include "../include/Simulation.h"
#include "Party.h"

Simulation::Simulation(Graph graph, vector<Agent> agents) : mGraph(graph), mAgents(agents), coalitions(), terminate(false) 
{
    // You can change the implementation of the constructor, but not the signature!
    //make a new coalition for each agent
    for(Agent a : agents){
        a.setCoalition(a.getId());
        coalitions.push_back(Coalition(a.getId(), graph.getParty(a.getPartyId()).getMandates(), vector<int>{a.getPartyId()}));
    }
}

void Simulation::step(){
    terminate = shouldTerminate();
    if (terminate == false){
        for (Party &party : mGraph.getPartyies())
            party.step(*this);

        for(Agent &a : mAgents)
           a.step(*this);

    }
}

 const Coalition &Simulation::getCoalition(int indexCoalition) const {
    
    return coalitions[indexCoalition];
}


bool Simulation::shouldTerminate() const
{
    //check if has a coalition with 61
    bool isAllPartyiesJoined = true;
    for (Coalition co : coalitions){
    if (co.getMandates() >= 61)
       return true;
    }
    //check if all the parties has status joined
    for (Party party : mGraph.getPartyies()){
        if (party.getState() != Joined)
            isAllPartyiesJoined = false;
    }

    return isAllPartyiesJoined;
}

const Graph &Simulation::getGraph() const
{
    return mGraph;
}

 Graph &Simulation::getGraph() 
{
    return mGraph;
}

const vector<Agent> &Simulation::getAgents() const 
{
    return mAgents;
}
void Simulation::addAgent(int paryId, int oldAgentId, int coalitionId , int mandatesToAdd){
    mAgents.push_back(mAgents[oldAgentId].clone(mAgents.size(), paryId));
    coalitions[coalitionId].AddParty(paryId , mandatesToAdd);
}
    
 


const Party &Simulation::getParty(int partyId) const
{
    return mGraph.getParty(partyId);
}


/// This method returns a "coalition" vector, where each element is a vector of party IDs in the coalition.
/// At the simulation initialization - the result will be [[agent0.partyId], [agent1.partyId], ...]
const vector<vector<int>> Simulation::getPartiesByCoalitions() const
{
    // TODO: you MUST implement this method for getting proper output, read the documentation above.
    vector<vector<int>> returnVector;
    for (Coalition c : coalitions)
        returnVector.push_back(c.getParties());
    return returnVector;    
}
