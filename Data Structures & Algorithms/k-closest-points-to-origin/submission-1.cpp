class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq;

        for(int i=0; i < points.size(); i++) {
            int distSq = points[i][0] * points[i][0] + points[i][1] * points[i][1];

            pq.push({distSq, i});

            if(pq.size() > k) {
                pq.pop();
            }
        }

        

        vector<vector<int>> result;
        while(!pq.empty()) {
            int idx = pq.top().second;
            pq.pop();
            result.push_back(points[idx]);
        }
        return result;
    }
};
