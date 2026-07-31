class Solution {
    int m, n, l;
    vector<vector<int>> directions {{0,1}, {0,-1}, {1,0}, {-1,0}};
private:
    bool find(vector<vector<char>>& board, int i, int j, string& word, int index) {
        if (index >= word.size()) return true;

        if (i < 0 || j < 0 || i >=m || j >=n || board[i][j] != word[index] || board[i][j] == ' ') return false;

        char temp = board[i][j];
        board[i][j] = ' ';
        for(auto& direction : directions) {
            int i_ = i + direction[0];
            int j_ = j + direction[1];

            if (find(board, i_, j_, word, index+1))
                return true;
        }

        board[i][j] = temp;
        return false;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();
        l = word.size();

        if(m*n < l) return false;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == word[0] && find(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
