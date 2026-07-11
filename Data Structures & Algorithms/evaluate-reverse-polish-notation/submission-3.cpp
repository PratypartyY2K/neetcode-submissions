class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<int> st;
        for(string token : tokens) {
            if(token!="+" && token!="-" && token != "*" && token != "/") {
                st.push(std::stoi(token));
            }
            else if(token == "+") {
                int temp = st.top();
                st.pop();
                temp += st.top();
                st.pop();
                st.push(temp);

            }
            else if (token == "*") {
                int temp = st.top();
                st.pop();
                temp *= st.top();
                st.push(temp);
            } else if (token == "-") {
                int temp = st.top();
                st.pop();
                temp = st.top() - temp;
                st.pop();
                st.push(temp);
            } else if (token == "/") {
                int temp = st.top();
                st.pop();
                temp = st.top()/temp;
                st.pop();
                st.push(temp);
            }
        }
        return st.top();
    }
};
