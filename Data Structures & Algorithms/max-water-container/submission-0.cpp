class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;
        for(int i = 0; i < heights.size(); i++) {
            for(int j = i+1; j < heights.size(); j++) {
                int area = min(heights[i], heights[j]) * (j-i);
                maxArea = max(area, maxArea);
            }
        }
        return maxArea;
    }
};
