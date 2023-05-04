#include "../include/JoinPolicy.h"
#include "Simulation.h"
#include<vector>
using std::vector;
#include <iostream>





 MandatesJoinPolicy::MandatesJoinPolicy(){
    }
    vector<int> MandatesJoinPolicy::run(vector<vector<int>> &offers, const Simulation &s) {
    int max=0, temp, returnValue=-1;
    for (int i=0; i<static_cast<int>(offers.size()); i++){ 
        temp = s.getCoalition(((s.getAgents())[offers[i][1]]).getCoalition()).getMandates();
        if (temp > max){
            max = temp;
            returnValue = i;
       }
    }
    return offers[returnValue];
    }

    MandatesJoinPolicy::~MandatesJoinPolicy(){

    }
    JoinPolicy* MandatesJoinPolicy::clone(){
            return  new MandatesJoinPolicy;
    }

    LastOfferJoinPolicy::LastOfferJoinPolicy(){
    }
     vector<int> LastOfferJoinPolicy::run(vector<vector<int>> &offers, const Simulation &s){
            //return the last offer
            return offers[offers.size()-1];
    }

    LastOfferJoinPolicy::~LastOfferJoinPolicy(){
    }
    JoinPolicy* LastOfferJoinPolicy::clone(){
            return  new LastOfferJoinPolicy;
    }
