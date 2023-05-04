#pragma once
#include<vector>
#include "Simulation.h"
#include <iostream>
using namespace std;

class SelectionPolicy { 
    public:
        //SelectionPolicy();
        virtual int run(const vector<int> &neighbors , const Simulation &s , int partyId)=0;  
        virtual ~SelectionPolicy() = default;
        virtual SelectionPolicy* clone() = 0; 
};

class MandatesSelectionPolicy: public SelectionPolicy{
    public:
        MandatesSelectionPolicy();
        ~MandatesSelectionPolicy();
        virtual int run(const vector<int> &neighbors , const Simulation &s , int partyId);  
        SelectionPolicy* clone(); 
 };

class EdgeWeightSelectionPolicy: public SelectionPolicy{
    public:
        EdgeWeightSelectionPolicy();
        ~EdgeWeightSelectionPolicy();
        virtual int run(const vector<int> &neighbors , const Simulation &s , int partyId);  
        SelectionPolicy* clone(); 
 };