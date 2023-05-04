#pragma once
#include<vector>
using std::vector;
#include<Simulation.h>
#include <iostream>
using namespace std;

class JoinPolicy {
    public:
        virtual vector<int> run(vector<vector<int>> &offers,const Simulation &s)=0;       
        virtual ~JoinPolicy() = default;
        virtual JoinPolicy* clone() = 0; 


};

class MandatesJoinPolicy : public JoinPolicy {
    public:
        vector<int> run(vector<vector<int>> &offers,const Simulation &s) ;    
        MandatesJoinPolicy();
        ~MandatesJoinPolicy();
        JoinPolicy* clone(); 

};

class LastOfferJoinPolicy : public JoinPolicy {
    public:
        vector<int> run(vector<vector<int>> &offers, const Simulation &s);    
        LastOfferJoinPolicy();
        ~LastOfferJoinPolicy();
        JoinPolicy* clone(); 

};