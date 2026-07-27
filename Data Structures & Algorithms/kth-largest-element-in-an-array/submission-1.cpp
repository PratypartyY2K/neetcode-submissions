class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int target = nums.size() - k;
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int pivotIdx = left + rand() % (right - left + 1);
            int pivotVal = nums[pivotIdx];

            swap(nums[pivotIdx], nums[right]);
            int storeIdx = left;

            for(int i = left; i < right; i++) {
                if (nums[i] < pivotVal) {
                    swap(nums[i], nums[storeIdx++]);
                }
            }

            swap(nums[storeIdx], nums[right]);

            if (storeIdx == target) {
                return nums[storeIdx];
            } else if (storeIdx < target) {
                left = storeIdx + 1;
            } else {
                right = storeIdx - 1;
            }
        }
        return -1;
    }
};
