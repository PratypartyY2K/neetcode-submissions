class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int right = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        int left = right - 1;

        // Expand 2 pointers to collect k elements
        while (k > 0) {
            if (left < 0) {
                right++;
            } else if (right >= arr.size()) {
                left--;
            } else if (abs(arr[left] - x) <= abs(arr[right] - x)) {
                left--; // Prefer left on tie because arr[left] < arr[right]
            } else {
                right++;
            }
            k--;
        }

        return vector<int>(arr.begin() + left + 1, arr.begin() + right);
    }
};