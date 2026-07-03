class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int f = 0, s = 1;
        int counter = 0;
        bool nextGreater = false;
        int n = nums.size();
        while (s < n) {
            if(nums[s] > nums[f]) {
                nextGreater = true;
                nums[counter] = nums[f];
                counter++;
                f = s;
            }
            nextGreater = false;
            s++;
            
        }

        nums[counter] = nums[s-1];
        nums.erase(nums.begin()+counter+1, nums.end());
        return nums.size();
    }
};