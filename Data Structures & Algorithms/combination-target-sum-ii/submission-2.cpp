class Solution {
private:
    void backtrack(int index, int target, vector<int>& candidates, vector<int>& temp, vector<vector<int>>& result) {
        // base case 1: target is reached
        if (target == 0) {
            result.push_back(temp);
            return;
        }

        // base case 2: if index has reached end of array or target has gone below 0
        if(index == candidates.size() || target < 0 || candidates[index] > target) {
            return;
        }

        // choice 1: choose candidates[index]
        temp.push_back(candidates[index]);
        backtrack(index+1, target - candidates[index], candidates, temp, result);
        temp.pop_back();

        // choice 2: not choose current index
        int nextIndex = index + 1;
        while (nextIndex < candidates.size() && candidates[nextIndex] == candidates[index]) {
            nextIndex++;
        }
        backtrack(nextIndex, target, candidates, temp, result);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        std::sort(candidates.begin(), candidates.end());
        backtrack(0, target, candidates, temp, result);
        
        return result;
    }
};
