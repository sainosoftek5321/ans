#include <iostream>
#include <vector>
using namespace std;

class NQueens {
    int n;
    vector<vector<string>> solutions;
    bool isSafe(vector<string>& board, int row, int col) {
        // Check upper column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        // Check upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        // Check upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }

    void solve(vector<string>& board, int row) {

        // Base Case
        if (row == n) {
            solutions.push_back(board);
            return;
        }

        // Try every column
        for (int col = 0; col < n; col++) {

            if (isSafe(board, row, col)) {

                // Place Queen
                board[row][col] = 'Q';

                // Recursive Call
                solve(board, row + 1);

                // Backtrack
                board[row][col] = '.';
            }
        }
    }

public:
    void solveNQueens(int size) {
        n = size;
        vector<string> board(n, string(n, '.'));
        solve(board, 0);
        // Print Solutions
        int count = 1;
        for (auto solution : solutions) {
            cout << "Solution " << count++ << ":\n";
            for (string row : solution) {
                cout << row << endl;
            }
            cout << endl;
        }
    }
};

int main() {
    int n = 4;

    NQueens obj;
    obj.solveNQueens(n);

    return 0;
}
// Pseudo code
// START
// FUNCTION isSafe(board, row, col)
//     FOR i = 0 TO row-1
//         IF queen exists in same column
//             RETURN false
//     CHECK upper-left diagonal
//     IF queen found
//         RETURN false
//     CHECK upper-right diagonal
//     IF queen found
//         RETURN false
//     RETURN true


// FUNCTION solve(board, row)
//     IF row == N
//         PRINT board
//         RETURN
//     FOR col = 0 TO N-1
//         IF isSafe(board, row, col)
//             PLACE queen at (row, col)
//             solve(board, row + 1)
//             REMOVE queen from (row, col)
//             // Backtracking

// MAIN
// INPUT N
// CREATE empty chessboard
// CALL solve(board, 0)
// END


// TIME COMPLEXITY
// ⏱ Time Complexity
// Worst Case: O(N!)
// Because:
// First row → N choices
// Second row → N-1 choices
// Third row → N-2 choices

// So total possibilities are approximately:

// N!

// 📦 Space Complexity
// Board storage → O(N²)
// Recursive stack → O(N)

// Overall:

// O(N2)