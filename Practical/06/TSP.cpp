#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main() {
    int n;

    cout << "Enter number of cities: ";
    cin >> n;

    vector<vector<int>> cost(n, vector<int>(n));

    cout << "Enter cost matrix:\n";

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> cost[i][j];
        }
    }

    vector<bool> visited(n, false);

    int currentCity = 0;
    visited[currentCity] = true;

    int totalCost = 0;

    cout << "Path: " << currentCity;

    for(int count = 0; count < n - 1; count++) {

        int nextCity = -1;
        int minCost = INT_MAX;

        for(int i = 0; i < n; i++) {

            if(!visited[i] && cost[currentCity][i] < minCost) {
                minCost = cost[currentCity][i];
                nextCity = i;
            }
        }

        visited[nextCity] = true;

        cout << " -> " << nextCity;

        totalCost += minCost;

        currentCity = nextCity;
    }

    totalCost += cost[currentCity][0];

    cout << " -> 0";

    cout << "\nTotal Cost = " << totalCost;

    return 0;
}

// START

// Input number of cities n

// Input cost matrix

// Mark all cities as unvisited

// Start from city 0

// Mark city 0 as visited

// totalCost = 0

// Repeat (n - 1) times

//     Find nearest unvisited city

//     Move to that city

//     Mark it visited

//     Add distance to totalCost

// Return to starting city

// Add return cost to totalCost

// Print path and totalCost

// END
//----------------------------------
// Time Complexity - O(N^2)