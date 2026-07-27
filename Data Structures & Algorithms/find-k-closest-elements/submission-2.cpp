class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        
        int low = 0, high = arr.size() - k;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // Check if window starting at mid + 1 is better than window at mid
            if (x - arr[mid] > arr[mid + k] - x) {
                low = mid + 1; // Move window right
            } else {
                high = mid;    // Keep window at mid or left
            }
        }

        return vector<int>(arr.begin() + low, arr.begin() + low + k);
    
    }
};