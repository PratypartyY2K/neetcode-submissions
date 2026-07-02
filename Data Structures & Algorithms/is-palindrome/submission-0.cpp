class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            while (left < right and !std::isalnum(s[left])) {
                left++;
            }
            while (right > left and !std::isalnum(s[right])) {
                right--;
            }
            if(tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            left++; right--;
        }
        return true;
    }
};
