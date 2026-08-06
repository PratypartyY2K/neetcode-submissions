class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;
        int time = 0;

        vector<vector<int>> result = grid;

        int rows = result.size();
        int cols = result[0].size();

        queue<pair<int, int>> q;
        int freshCount = 0;

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(result[r][c] == 2) {
                    q.push({r, c});
                } else if (result[r][c] == 1) {
                    freshCount++;
                }
            }
        }

        if (freshCount == 0) return 0;


        int dirR[] = {-1, 1, 0, 0};
        int dirC[] = {0, 0, -1, 1};


        while(!q.empty() && freshCount > 0) {
            int currentLevelSize = q.size();
            time++;

            for(int k = 0; k < currentLevelSize; k++) {
                auto [r,c] = q.front();
                q.pop();

                for(int i = 0; i < 4; i++) {
                    int newR = r + dirR[i];
                    int newC = c + dirC[i];

                    if(newR >= 0 && newR < rows && newC >= 0 && newC < cols && result[newR][newC] == 1) {
                        result[newR][newC] = 2;
                        freshCount--;
                        q.push({newR, newC});
                    }
                }
            }
        }
        return freshCount == 0 ? time : -1;
    }
};
