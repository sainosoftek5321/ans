#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// custom comparator for sorting (issa ham sorting ka bheaviour change kr sakte hai)
bool cmp(pair<int , int> &p1, pair<int,int> &p2){
    double r1 = (double)p1.first / p1.second;
    double r2 = (double)p2.first / p2.second;

    return r1 > r2;
}

double fractionalKnapsack(vector<int> &profit, vector<int> &weight, int n , int w){
    vector<pair<int,int>> arr;
    for(int i = 0; i < n; i++){
        arr.push_back({profit[i],weight[i]});
    }
    sort(arr.begin(),arr.end(),cmp);
    double pft = 0;
    for(auto x : arr){
        if(w >= x.second){
            pft += x.first;
        }
        else{ // pick partial
            pft += (x.first * w)/ x.second;
        }
        w -= x.second;
    }
    return pft;
}
int main(){
    vector<int> profit = {60,100,120};
    vector<int> weight = {10,20,30};
    int w = 50;
    cout<< fractionalKnapsack(profit,weight,3,w);
}

// FRACTIONAL_KNAPSACK(weight[], profit[], n, capacity)

// FOR each item
//     ratio = profit / weight

// Sort all items in descending order of ratio

// totalProfit = 0

// FOR each item

//     IF weight <= capacity

//         totalProfit = totalProfit + profit

//         capacity = capacity - weight

//     ELSE

//         fraction = capacity / weight

//         totalProfit = totalProfit + (profit * fraction)

//         BREAK

// RETURN totalProfit

//--------------------------------------------
// Time Complexity Analysis of Knapsack
// 1. Fractional Knapsack (Greedy)

// Steps:

// Sort items by profit/weight ratio
// Traverse all items once

// Time complexity:

// T(n)=O(nlogn)+O(n)

// Final:

// Time Complexity = O(n log n)

// Reason:

// Sorting takes O(n log n)
// Traversing takes O(n)

// Space Complexity:

// Space Complexity = O(1)