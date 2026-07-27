/*
Since the answer is a continuous subarray of size K, 
we can use Binary Search directly on the starting index mid of the K-element window.
We compare x - arr[mid] vs arr[mid + k] - x.
*/

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
