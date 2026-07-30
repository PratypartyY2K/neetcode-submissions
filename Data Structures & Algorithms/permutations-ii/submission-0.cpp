class Solution {
private:
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& result) {

        // base case
        if (temp.size() == nums.size()) {
            result.push_back(temp);
            return;
        }

        for(int i=0; i < nums.size(); i++) {
            if(used[i]) continue;

            if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

            used[i] = true;
            temp.push_back(nums[i]);
            backtrack(nums, used, temp, result);

            temp.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        vector<int> temp;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, temp, result);

        return result;
    }
};