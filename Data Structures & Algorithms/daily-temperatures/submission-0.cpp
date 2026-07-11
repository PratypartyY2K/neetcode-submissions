class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> result(temperatures.size(), 0);
        stack<pair<int, int>> st;

        for(int i = 0; i < temperatures.size(); i++) {
            int temperature = temperatures[i];
            while(!st.empty() && temperature > st.top().first) {
                auto p = st.top();
                st.pop();
                result[p.second] = i - p.second;
            }
            st.push({temperature, i});
        }
        return result;
    }
};
