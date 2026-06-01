#include <iostream>
#include <vector>

using namespace std;

// There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i].
// You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the journey with an empty tank at one of the gas stations.
// Given two integer arrays gas and cost, return the starting gas station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a solution, it is guaranteed to be unique.

// Example 1:

// Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
// Output: 3

int best_point(vector<int> &gas, vector<int> &cost) {
    int totalGas = 0;
    int totalCost = 0;
    int start = 0;
    int currGas = 0;

    for(int i = 0; i < gas.size(); i++) {
        totalGas += gas[i];
        totalCost += cost[i];
        
        currGas += gas[i] - cost[i];

        if(currGas < 0) {
            start = i+1;
            currGas = 0;
        }
    }

    return totalGas >= totalCost ? start : -1;
}

int main() {
    vector<int> gas = {1,3,4,5,6,9};
    vector<int> cost = {4,10,2,16,1,5};

    cout << best_point(gas, cost) << endl;

    return 0;
}