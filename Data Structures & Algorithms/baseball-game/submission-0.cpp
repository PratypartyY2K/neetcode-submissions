class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> temp;
        int n = operations.size();
        int score = 0;
        temp.push_back(std::stoi(operations[0]));
        for(int i = 1; i < n; i++) {
            if(operations[i]!="+" && operations[i]!="C" && operations[i]!="D") {
                temp.push_back(std::stoi(operations[i]));
            }
            else if(operations[i]=="+") {
                int temp_size = temp.size();
                temp.push_back(temp[temp_size - 1] + temp[temp_size - 2]);
            } else if(operations[i] == "C") {
                temp.pop_back();
            } else if(operations[i] == "D") {
                temp.push_back(2*temp.back());
            }
        }
        return std::reduce(temp.begin(), temp.end());
    }
};