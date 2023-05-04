#pragma once
#include <vector>
#include "Party.h"

using std::vector;

class Graph
{
public:
    Graph(vector<Party> vertices, vector<vector<int>> edges);
    int getMandates(int partyId) const;
    int getEdgeWeight(int v1, int v2) const;
    int getNumVertices() const;
    const Party &getParty(int partyId) const;
    const vector<int> &p_neighbors(int partyId);
    vector<int> p_neighborsForSelect(int partyId , int indexCoalition);
    const vector<Party> &getPartyies() const;
    vector<Party> &getPartyies();
    void addOffer(int fromCoalitionId , int fromAgentId, int toPartyId);

private:
    vector<Party> mVertices;
    vector<vector<int>> mEdges;
};