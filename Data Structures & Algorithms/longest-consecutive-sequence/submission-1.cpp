class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) return 0;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int maxLength = 0, expectedNumber = nums[0], length = 0, i = 0;

        while ( i < n) {
            if (expectedNumber!=nums[i]) {
                expectedNumber = nums[i];
                length = 0;
            }
            while (i < n and nums[i] == expectedNumber) {
                i++;
            }
            length++;
            expectedNumber++;
            maxLength = max(maxLength, length);
        }
        return maxLength;
    }
};
