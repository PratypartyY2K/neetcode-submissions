class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long totalGifts = 0;
        priority_queue<int> pq (gifts.begin(), gifts.end());

        while( k-- > 0 && !pq.empty()) {
            long long maxPile = pq.top();
            pq.pop();
            pq.push(floor(sqrt(maxPile)));
        }

        while(!pq.empty()) {
            int pile = pq.top();
            pq.pop();
            totalGifts += pile;
        }

        return totalGifts;
    }
};