#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

class JoinPolicy;
class Simulation;

enum State
{
    Waiting,
    CollectingOffers,
    Joined
};

class Party
{
public:
    Party(int id, string name, int mandates, JoinPolicy *); 

    State getState() const;
    void setState(State state);
    int getMandates() const;
    void step(Simulation &s);
    const string &getName() const;
    void addOffer(int coalitionId, int agentId);
    bool isLegalOffer(int indexCoalition);
    int getCoalition() const;
    ~Party();
    Party(const Party &other);
    Party(Party && other);
    Party& operator=(const Party &other);
    Party& operator=(Party &&other);

private:
    int mId;
    string mName;
    int mMandates;
    JoinPolicy *mJoinPolicy;
    State mState;
    int timer;
    vector<vector<int>> offers_list;
    int coalition;
};