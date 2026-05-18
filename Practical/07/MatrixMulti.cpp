#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainMultiplication(vector<int>& p) {
    int n = p.size() - 1;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; len++) {

        for (int i = 0; i <= n - len; i++) {

            int j = i + len - 1;

            dp[i][j] = INT_MAX;

            for (int k = i; k < j; k++) {

                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i] * p[k + 1] * p[j + 1];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    return dp[0][n - 1];
}

int main() {

    vector<int> p = {10, 20, 30, 40, 30};

    cout << "Minimum multiplications: "
         << matrixChainMultiplication(p);

    return 0;
}

// Algorithm MatrixChainMultiplication(p)
// Input:
//     Array p[] containing matrix dimensions
// Output:
//     Minimum scalar multiplications
// n = size of p - 1
// Create 2D array dp[n][n]
// For i = 0 to n-1
//     dp[i][i] = 0
// For len = 2 to n
//     For i = 0 to n-len
//         j = i + len - 1
//        dp[i][j] = INFINITY
//         For k = i to j-1
//             cost = dp[i][k]
//                  + dp[k+1][j]
//                  + p[i] * p[k+1] * p[j+1]
//             If cost < dp[i][j]
//                 dp[i][j] = cost
// Return dp[0][n-1]

//-----------------------------------------------

// Time Complexity

// There are 3 nested loops:
// Chain length loop → O(n)
// Starting index loop → O(n)
// Partition loop → O(n)
// Therefore:
// Time Complexity=O(n3)
// T(n)=O(n3)
// Space Complexity
// DP table of size n × n is used.
// Space Complexity=O(n2)
// S(n)=O(n2)