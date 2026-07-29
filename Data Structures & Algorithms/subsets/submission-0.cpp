class Solution {
private:
    void backtrack(const vector<int>& nums, int start, vector<int>& current, vector<vector<int>>& result) {
        result.push_back(current); // record the subset generated at the current state

        for(int i = start; i < nums.size(); i++) {

            // include nums[i]
            current.push_back(nums[i]);

            //recurse to process remaining elements
            backtrack(nums, i+1, current, result);

            // backtrack: remove nums[i] to explore other branches
            current.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        backtrack(nums, 0, current, result);
        return result;
    }
};
