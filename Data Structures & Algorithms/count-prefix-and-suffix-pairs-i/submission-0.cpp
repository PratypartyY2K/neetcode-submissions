class Solution {
private:
    bool isPrefixAndSuffix(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();

        if(n>m) return false;

        string prefix = str2.substr(0, n);
        string suffix = str2.substr(m-n, n);

        return (prefix == str1) && (suffix == str1);
    }
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int count = 0;
        for(int i = 0; i < words.size()-1; i++) {
            string s1 = words[i];
            for(int j = i+1; j < words.size(); j++) {
                string s2 = words[j];
                if (isPrefixAndSuffix(s1, s2)) count++;
            }
        }
        return count;
    }
};