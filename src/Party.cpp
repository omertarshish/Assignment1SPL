#include "Party.h"
#include<iostream>
#include<vector>
#include<algorithm>
#include<Simulation.h>
#include "JoinPolicy.h"

Party::Party(int id, string name, int mandates, JoinPolicy *jp) : mId(id), mName(name),
 mMandates(mandates), mJoinPolicy(jp), mState(Waiting), timer(1), offers_list(0), coalition(-1)
{
    // You can change the implementation of the constructor, but not the signature!
}

State Party::getState() const
{
    return mState;
}

void Party::setState(State state)
{
    mState = state;
}

int Party::getMandates() const
{
    return mMandates;
}

const string & Party::getName() const
{
    return mName;
}



void Party::step(Simulation &s)
{
    // set coalition if the party has been Joined
    if(mState == Joined && coalition == -1){
        for (Agent agent : s.getAgents()){
            if (agent.getPartyId() == mId)
                this->coalition = agent.getId();
        }
    }
    if(mState == CollectingOffers){
        //set coalition for party that joined
        //select coalition by join policy
        if(timer == 3){
            vector <int> result = mJoinPolicy->run(offers_list, s);
            int coalitionToJoin = result[0];
            this->coalition = coalitionToJoin;
            this->mState = Joined;
            s.addAgent(mId, result[1] , result[0] , mMandates);
        }
        else{
            timer++;
        }
    } 
}

int Party::getCoalition() const{
    return this->coalition;
}

bool Party::isLegalOffer(int fromIndexCoalition){
    for(vector<int> x : offers_list){
        if(x[0] == fromIndexCoalition)
            return false;
    }
    return mState != Joined;
}

void Party::addOffer(int coalitionId, int agentId){
    if(mState == Waiting){
    setState(CollectingOffers);
    }
    vector<int> vector1 = {coalitionId , agentId};
    offers_list.push_back(vector1);
}  

//destructor
Party::~Party(){
    if(mJoinPolicy) delete mJoinPolicy;
}

//copy constructor
Party::Party(const Party &other) : mId(other.mId) , mName(other.mName), mMandates(other.mMandates) , 
    mJoinPolicy(other.mJoinPolicy->clone()) , mState(other.mState), timer(other.timer) , offers_list(other.offers_list) , coalition(other.coalition) {

}

//move constructor
Party::Party(Party && other) : mId(other.mId) , mName(other.mName), mMandates(other.mMandates) , 
    mJoinPolicy(other.mJoinPolicy), mState(other.mState), timer(other.timer) , offers_list(other.offers_list) , coalition(other.coalition) {
    other.mJoinPolicy = nullptr;
  }

// copy assignment operator
Party& Party::operator=(const Party &other){
    *mJoinPolicy = (*(other.mJoinPolicy));
    return *this;
}

// move assignment operator
Party& Party::operator=(Party &&other){
    if(mJoinPolicy) delete mJoinPolicy;
    mJoinPolicy = other.mJoinPolicy;
    other.mJoinPolicy = nullptr;
    return *this;
}
