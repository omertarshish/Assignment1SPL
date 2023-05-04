#include "Graph.h"

Graph::Graph(vector<Party> vertices, vector<vector<int>> edges) : mVertices(vertices), mEdges(edges) 
{
    // You can change the implementation of the constructor, but not the signature!
}

int Graph::getMandates(int partyId) const
{
    return mVertices[partyId].getMandates();
}

int Graph::getEdgeWeight(int v1, int v2) const
{
    return mEdges[v1][v2];
}

int Graph::getNumVertices() const
{
    return mVertices.size();
}

const Party &Graph::getParty(int partyId) const
{
    return mVertices[partyId];
}

vector<Party> &Graph::getPartyies()  
{
    return mVertices;
}

const vector<Party> &Graph::getPartyies() const
{
    return mVertices;
}


const vector<int> &Graph::p_neighbors(int partyId){
    return mEdges[partyId];
}

vector<int> Graph::p_neighborsForSelect(int partyId , int indexCoalition) {
    vector<int> v;
    for (int i=0; i<static_cast<int>(mEdges[partyId].size()); i++){
        if( getEdgeWeight( partyId, i) > 0 && mVertices[i].isLegalOffer(indexCoalition))
           (v).push_back(i);
    }
    return v;
}

void Graph::addOffer(int fromCoalitionId , int fromAgentId, int toPartyId ){
    mVertices[toPartyId].addOffer(fromCoalitionId , fromAgentId);
}
