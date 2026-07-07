class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int index = 0, left = 0, right = n - 1;
        while(index <= right) {
            if(nums[index] == 0) {
                swap(nums[left], nums[index]);
                left++;
            } else if (nums[index] == 2) {
                swap(nums[index], nums[right]);
                right--;
                index--;
            }
            index++;
        }
    }
};