class Solution {
private:
    void backtrack(int open, int close, int n, string& temp, vector<string>& result) {
        // Base case: formed a valid sequence of length 2 * n
        if (temp.size() == 2 * n) {
            result.push_back(temp);
            return;
        }

        // Add '(' if we haven't placed n open brackets yet
        if (open < n) {
            temp.push_back('(');
            backtrack(open + 1, close, n, temp, result);
            temp.pop_back(); // Backtrack
        }

        // Add ')' if it won't exceed the number of open brackets
        if (close < open) {
            temp.push_back(')');
            backtrack(open, close + 1, n, temp, result);
            temp.pop_back(); // Backtrack
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> result;
        backtrack(0,0,n, temp, result);

        return result;
    }
};
