class Solution {
private:
    void backtrack(int n, string& temp, vector<string>& result) {
        if(temp.size() == 2*n) {
            if(isValid(temp)) {
                result.push_back(temp);
            }
            return;
        }

        temp.push_back('(');
        backtrack(n, temp, result);
        temp.pop_back();

        temp.push_back(')');
        backtrack(n, temp, result);
        temp.pop_back();
    }

    bool isValid(const string& s) {
        int balance = 0;
        for (char ch : s) {
            if (ch == '(') balance++;
            else balance--;
            
            if (balance < 0) return false; // More closing than opening
        }
        return balance == 0;
    }
public:
    vector<string> generateParenthesis(int n) {
        string temp = "";
        vector<string> result;
        backtrack(n, temp, result);

        return result;
    }
};
