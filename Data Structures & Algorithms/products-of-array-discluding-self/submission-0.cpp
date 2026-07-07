class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n , 1);

        int left_product = 1;
        int right_product = 1;
        for(int i = 0; i < n ; i++) {
            result[i] *= left_product;
            left_product *= nums[i];

            int j = n - 1 - i;
            result[j] *= right_product;
            right_product *= nums[j];
        }
        return result;
    }
};
