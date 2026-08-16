class Solution {
public:
    int climbStairs(int n) {
        int previous = 1;
        int second_previous = 1;
        int current;
        for(int i =2; i <= n; i++) {
            current = previous + second_previous;
            second_previous = previous;
            previous = current;
        }

        return previous;
    }
};
