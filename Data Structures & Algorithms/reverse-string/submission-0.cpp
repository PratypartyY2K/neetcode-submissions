class Solution {
public:
    void reverseString(vector<char>& s) {
        int n = s.size();
        if (n <=0) return;
        int i = 0, j = n - 1;
        while(i < n/2 and j >=n/2 and i!=j) {
            char temp;
            temp = s[i];
            // cout << temp << " ";
            s[i] = s[j];
            // cout << s[i] << " ";
            s[j] = temp;
            // cout << s[j] << " ";
            i++; j--;
            // cout << "\n";
        }
    }
};