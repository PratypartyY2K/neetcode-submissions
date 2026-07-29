class Solution {
private:
    void backtrack(int index, int n, int k, vector<vector<int>>& res, vector<int> temp) {
        if (k == 0) {
            res.push_back(temp);
            return;
        }

        if (index > n) {
            return;
        }

        // Decision 1: Add index to temp
        temp.push_back(index);
        backtrack(index+1, n, k-1, res, temp);
        temp.pop_back();

        // Decision 2: Do not add index to temp
        backtrack(index+1, n, k, res, temp);

    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        backtrack(1, n, k, result, temp);
        return result;
    }
};