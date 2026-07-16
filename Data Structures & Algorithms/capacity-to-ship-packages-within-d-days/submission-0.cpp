class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end()); 
        int r = accumulate(weights.begin(), weights.end(), 0);
        int result = r;
        while (l <= r) {
            int lwc = (l+r)/2;
            if (canShip(weights, days, lwc)) {
                result = min(result, lwc);
                r = lwc - 1;
            } else {
                l = lwc + 1;
            }
        }
        return result;
    }
private:
    bool canShip(vector<int> &weights, int days, int capacity) {
        int ships = 1, currentCapacity = capacity;
        for(int w : weights) {
            if ( currentCapacity - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currentCapacity = capacity;
            }
            currentCapacity -= w;
        }
        return true;
    }
};