#include "../include/SelectionPolicy.h"
#include<vector>
using std::vector;
#include <bits/stdc++.h>


    MandatesSelectionPolicy::MandatesSelectionPolicy(){
        cout<< "nothing" << endl;
    }

    int MandatesSelectionPolicy::run(const vector<int> &neighbors , const Simulation &s , int partyId){
    if (neighbors.size() == 0)
        return -1;
    int max = 0;
    int index = -1;
    for(int x : neighbors){
        int cur = s.getParty(x).getMandates();
        if(max < cur){
            index = x;
            max = cur;
        }
    }
    return index;
    }
    MandatesSelectionPolicy::~MandatesSelectionPolicy(){
        
    }

    SelectionPolicy* MandatesSelectionPolicy::clone(){
        return  new MandatesSelectionPolicy();
    }


    EdgeWeightSelectionPolicy::EdgeWeightSelectionPolicy(){
    }

    int EdgeWeightSelectionPolicy::run(const vector<int> &neighbors , const Simulation &s , int partyId){
            if (neighbors.size() == 0)
                return -1;
        int max = 0;
        int index = -1;
        for(int x : neighbors){
            int cur = s.getGraph().getEdgeWeight(partyId , x);
            if(max < cur){
                max = cur;
                index = x;
            }   
        }
        return index;
        }

    EdgeWeightSelectionPolicy::~EdgeWeightSelectionPolicy(){
        }
        
    SelectionPolicy* EdgeWeightSelectionPolicy::clone(){
            return  new EdgeWeightSelectionPolicy();
        }
    
    