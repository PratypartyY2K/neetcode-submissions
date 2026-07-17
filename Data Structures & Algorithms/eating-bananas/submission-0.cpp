class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int result = r;

        while (l <= r) {
            int k = l + (r - l) / 2; 
            long long hours = 0;
            
            for (int p : piles) {
                hours += (p + (long long)k - 1) / k;
                
                if (hours > h) break; 
            }
            
            if (hours <= h) {
                result = k;
                r = k - 1;
            } else {
                l = k + 1;
            }
        }
        return result;
    }
};