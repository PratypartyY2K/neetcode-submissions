class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        for(int i = 0; i < numbers.size(); i++) {
            int left = i + 1, right = numbers.size() - 1;
            int temp = target - numbers[i];
            while(left <= right) {
                int mid = left + (right - left) / 2;
                if (numbers[mid] == temp) {
                    return { i + 1, mid + 1};
                } else if ( numbers[mid] < temp ) {
                    left = mid + 1;
                } else {
                    right = mid - 1;
                }
            }
        }
        return {};
    }
};
