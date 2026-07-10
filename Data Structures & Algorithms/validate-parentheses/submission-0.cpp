class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        for(char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) 
                    return false;
                if ((c == ')' && st.top() != '(') ||
                    (c == '}' && st.top() != '{') ||
                    (c == ']' && st.top() != '[')) {
                    return false;
                }
            st.pop();
            }
        }
        return st.empty();
    }
};
