#pragma once
#include <vector>
#include "Graph.h"
#include "Agent.h"
#include "Coalition.h"

using std::string;
using std::vector;

class Simulation
{
public:
    Simulation(Graph g, vector<Agent> agents);

    void step();
    bool shouldTerminate() const;

    const Graph &getGraph() const;
     Graph &getGraph();
    const vector<Agent> &getAgents() const;
    void addAgent(int paryId, int oldAgentId, int coalitionId , int mandatesToAdd);
    const Party &getParty(int partyId) const;
    const vector<vector<int>> getPartiesByCoalitions() const;
    const Coalition &getCoalition(int indexCoalition) const;
    
private:
    Graph mGraph;
    vector<Agent> mAgents;
    vector<Coalition> coalitions;
    bool terminate;
};