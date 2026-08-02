class Solution {
private:
    bool solve(vector<int>& matchsticks, vector<int>& sides, int index, int sideLength) {
        if (index == matchsticks.size()) {
            return true;
        }

        for(int i = 0; i < 4; i++) {
            
            if(sides[i] + matchsticks[index] <= sideLength) {
                sides[i] += matchsticks[index];
                if (solve(matchsticks, sides, index+1, sideLength)) {
                    return true;
                }
                sides[i] -= matchsticks[index];
            }

            if (sides[i] == 0) break;
        }

        return false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        sort(matchsticks.begin(), matchsticks.end(), greater<int>());
        int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
        if (perimeter % 4 != 0 ) return false;
        int sideLength = perimeter/4;
        vector<int> sides(4, 0);

        return solve(matchsticks, sides, 0, sideLength);

    }
};