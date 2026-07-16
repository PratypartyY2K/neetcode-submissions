class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) return false;
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        int low = 0;
        int high = m * n - 1;
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            int r = mid / n;
            int c = mid % n;
            
            int midValue = matrix[r][c];
            
            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        
        return false;
    }
};