class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int writeIndex = 1;
        int n = nums.size();
        for(int r=1;r<n;r++) {
            if(nums[r]!=nums[r-1]) {
                nums[writeIndex] = nums[r];
                writeIndex++;
            }
        }
        return writeIndex;
    }
};