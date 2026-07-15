class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int l = 0;
        int maxLength = 0;
        vector<int> lastSeen(128, -1);

        for(int r = 0 ; r < n ; r++) {
            char currentChar = s[r];

            if(lastSeen[currentChar] >= l) {
                l = lastSeen[currentChar] + 1;
            }

            lastSeen[currentChar] = r;

            maxLength = max(maxLength, r - l + 1);
        }
        return maxLength;
    }
};
