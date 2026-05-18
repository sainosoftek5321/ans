#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solve(string &s, vector<bool> &used,
               string curr, vector<string> &ans) {

        // Base Case
        if(curr.length() == s.length()) {
            ans.push_back(curr);
            return;
        }

        for(int i = 0; i < s.length(); i++) {

            // Skip already used characters
            if(used[i])
                continue;

            // Skip duplicates
            if(i > 0 && s[i] == s[i-1] && !used[i-1])
                continue;

            used[i] = true;

            solve(s, used, curr + s[i], ans);

            // Backtrack
            used[i] = false;
        }
    }

    vector<string> findPermutation(string s) {

        vector<string> ans;

        sort(s.begin(), s.end());

        vector<bool> used(s.length(), false);

        solve(s, used, "", ans);

        return ans;
    }
};

int main() {

    Solution obj;

    string s = "ABSG";

    vector<string> result = obj.findPermutation(s);

    for(string str : result)
        cout << str << " ";

    return 0;
}

// FUNCTION Permutation(s)
//     sort(s)
//     create empty list ans
//     create used array initialized to false
//     CALL Backtrack("", used)
//     RETURN ans

//-----------------------------------------------

// FUNCTION Backtrack(curr, used)
//     IF length(curr) == length(s)
//         add curr to ans
//         RETURN
//     FOR i = 0 to length(s)-1
//         IF used[i] == true
//             CONTINUE
//         IF i > 0 AND s[i] == s[i-1] AND used[i-1] == false
//             CONTINUE
//         used[i] = true
//         Backtrack(curr + s[i], used)
//         used[i] = false




// Time Complexity

// Let n = length of string.
// In worst case (all characters distinct):
// Total permutations = n!
// For each permutation, building/storing takes O(n).
// Overall Time Complexity
// O(n × n!)