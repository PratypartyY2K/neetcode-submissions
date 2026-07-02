class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string mergedWord = "";
        int l1 = word1.size();
        int l2 = word2.size();
        if (l1 == l2) {
            for(int i = 0;i < l1; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }
        } else if (l1 > l2) {
            int i = 0;
            for(;i < l2; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }
            int parsed = i;
            cout << i << " ";
            for(;i < l1-l2+parsed; i++) {
                mergedWord += word1[i];
            }
            cout << "\n";
        } else if (l2 > l1) {
            int i = 0;
            for(;i < l1; i++) {
                mergedWord += word1[i];
                mergedWord += word2[i];
            }
            int parsed = i;
            cout << i << " \n";
            for(;i < l2-l1+parsed; i++) {
                cout << i << " " << word2[i] << " ";
                mergedWord += word2[i];
            }
            cout << "\n";
        }
        return mergedWord;
    }
};