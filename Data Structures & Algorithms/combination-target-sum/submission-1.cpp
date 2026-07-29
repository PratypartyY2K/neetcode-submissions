class Solution {
private:
    void backtrack(int index, int target, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        
        if(target == 0) {
            result.push_back(temp);
            return;
        }

        if(target < 0 || index == nums.size()) {
            return;
        }

        temp.push_back(nums[index]);
        backtrack(index, target-nums[index], nums, temp, result);
        temp.pop_back();

        backtrack(index+1, target, nums, temp, result);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(0, target, nums, temp, result);

        return result;
    }
};
