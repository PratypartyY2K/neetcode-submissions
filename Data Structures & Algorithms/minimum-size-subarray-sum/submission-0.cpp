class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = 0;
        int sum = 0;
        int minLength = INT_MAX;
        while (r < n) {
            sum += nums[r];
            
            while (sum >= target) {
                minLength = min(r - l + 1, minLength);
                sum -= nums[l];
                l++;
            }
            r++;
        }
        return minLength == INT_MAX ? 0 : minLength;
    }
};