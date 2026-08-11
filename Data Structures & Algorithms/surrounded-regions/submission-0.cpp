#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        // Base cases: out of bounds or not an 'O'
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }
        
        // Mark cell as safe (temporary character)
        board[r][c] = '#';
        
        // Explore all 4 adjacent directions recursively
        dfs(board, r + 1, c, m, n);
        dfs(board, r - 1, c, m, n);
        dfs(board, r, c + 1, m, n);
        dfs(board, r, c - 1, m, n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        // Step 1 & 2: Run DFS from top and bottom borders
        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c, m, n);
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c, m, n);
        }
        
        // Run DFS from left and right borders
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0, m, n);
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1, m, n);
        }
        
        // Step 3: Flip remaining 'O's to 'X', and restore '#' back to 'O'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};