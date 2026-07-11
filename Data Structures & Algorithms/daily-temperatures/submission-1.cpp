class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> result(n, 0);
        stack<int> st;
        
        for (int i = 0; i < n; i++) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                int prevDayIndex = st.top();
                st.pop();
                
                result[prevDayIndex] = i - prevDayIndex;
            }
            
            st.push(i);
        }
        
        return result;
    }
};