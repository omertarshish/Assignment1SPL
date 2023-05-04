#pragma once
#include <vector>
using std::vector;

class Coalition{
public :
    Coalition(int idCoalition, int mandates, vector<int> otherParties);
    void AddParty(int partyId , int mandates);
    int getMandates() const;
    int setMandates(int numOfMandates);
    vector<int> getParties();
     


private :
    int mIdCoalition;
    int mNumOfMandates;
    std::vector<int> parties;
};