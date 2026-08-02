class Solution {
private:
    void backtrack(int index, string& digits, string& temp, vector<string>& result, unordered_map<char, string>& mp) {

        // BASE CASE
        if(index >= digits.length()) {
            result.push_back(temp);
            return;
        }

        char ch = digits[index];
        string str = mp[ch];

        for(int i = 0; i < str.length(); i++) {
            temp.push_back(str[i]); // do
            backtrack(index+1, digits, temp, result, mp); // explore
            temp.pop_back(); //undo
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.length() == 0) return {};
        vector<string> result;
        string temp = "";
        unordered_map<char, string> mp;

        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";

        backtrack(0, digits, temp, result, mp);

        return result;
    }
};
