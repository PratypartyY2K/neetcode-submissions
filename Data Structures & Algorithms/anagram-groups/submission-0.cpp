class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hm;

        for(const auto &str: strs) {
            vector<int> count(26, 0);
            for(char character: str) {
                count[character - 'a']++;
            }
            string key = to_string(count[0]);
            for(int i = 1; i < 26; i++) {
                key += ',' + to_string(count[i]);
            }
            hm[key].push_back(str);
        }

        vector<vector<string>> result;
        for(const auto& pair: hm) {
            result.push_back(pair.second);
        }
        return result;
    }
};
