#include "Coalition.h"
Coalition::Coalition(int idCoalition , int mandates, vector<int> otherParty) :  mIdCoalition(idCoalition) , mNumOfMandates(mandates) ,  parties(otherParty)
{
}

int Coalition::getMandates() const
{
    return mNumOfMandates;
}
int Coalition::setMandates(int numOfMandates) 
{
    return mNumOfMandates = numOfMandates;
}

vector<int> Coalition::getParties(){
    return parties;
}
void Coalition::AddParty(int partyId, int mandates){
    parties.push_back(partyId);
    mNumOfMandates += mandates;
}


