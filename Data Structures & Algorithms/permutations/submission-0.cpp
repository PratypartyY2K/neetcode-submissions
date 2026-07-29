class Solution {
    vector<vector<int>> result;
private:
    void backtrack(vector<int>& nums, vector<int>& temp) {
        // base case
        if (temp.size() >= nums.size()) {
            result.push_back(temp);
            return;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(find(temp.begin(), temp.end(), nums[i]) != temp.end()) {
                continue;
            }

            temp.push_back(nums[i]);

            backtrack(nums, temp);

            temp.pop_back();
        }

    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        backtrack(nums, temp);

        return result;
    }
};
