class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islandCount = 0;

        const vector<pair<int,int>> directions = {
            {-1, 0}, {1, 0}, {0, -1}, {0,1}
        };

        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid[r][c] == '1') {
                    islandCount++;
                
                    grid[r][c] = '0';
                    queue<pair<int, int>> q;
                    q.push({r, c});

                    while(!q.empty()) {
                        auto [currR, currC] = q.front();
                        q.pop();

                        for(const auto& [dR, dC] : directions) {
                            int newR = currR + dR;
                            int newC = currC + dC;

                            if (newR >= 0 && newR < rows && newC >= 0 && newC < cols && grid[newR][newC] == '1') {
                                grid[newR][newC] = '0'; // sink
                                q.push({newR, newC});
                            }
                        }
                    }
                }
            }
        }

        return islandCount;
    }
};
