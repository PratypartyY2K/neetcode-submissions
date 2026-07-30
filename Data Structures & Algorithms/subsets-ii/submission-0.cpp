class Solution {
private:
    void backtrack(int index, vector<int>& nums, vector<int>& temp, vector<vector<int>>& result) {
        if(index == nums.size()) {
            result.push_back(temp);
            return;
        }
        
        temp.push_back(nums[index]);
        backtrack(index+1, nums, temp, result);
        temp.pop_back();

        int nextIndex = index + 1;
        while (nextIndex < nums.size() && nums[nextIndex] == nums[index]) {
            nextIndex++;
        }
        backtrack(nextIndex, nums, temp, result);
        
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> result;
        backtrack(0, nums, temp, result);
        return result;
    }
};
