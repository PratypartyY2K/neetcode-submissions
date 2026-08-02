class Solution {
private:
    bool solve(vector<int>& nums, vector<int>& subsets, int index, int target, int k) {

        // base case: successfully placed all numbers
        if (index == nums.size()) return true;

        for(int i = 0; i < k ; i++) {
            if(subsets[i] + nums[index] <= target) {

                subsets[i] += nums[index];

                if(solve(nums, subsets, index+1, target, k)) {
                    return true;
                }

                subsets[i] -= nums[index];
            }

            if (subsets[i] == 0) break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if (sum%k != 0 || nums.size() < k) return false;

        int target = sum / k;

        sort(nums.rbegin(), nums.rend());

        if (nums[0] > target) return false;

        vector<int> subsets(k, 0);
        return solve(nums, subsets, 0, target, k);
    }
};