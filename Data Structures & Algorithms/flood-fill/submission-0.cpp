class Solution {
private:
    void dfs(vector<vector<int>>& grid, int r, int c, int originalColor, int newColor, int rows, int cols) {
        if(r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c]!= originalColor) return;

        grid[r][c] = newColor;

        dfs(grid, r-1, c, originalColor, newColor, rows, cols);
        dfs(grid, r+1, c, originalColor, newColor, rows, cols);
        dfs(grid, r, c-1, originalColor, newColor, rows, cols);
        dfs(grid, r, c+1, originalColor, newColor, rows, cols);
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> result = image;

        int originalColor = result[sr][sc];

        if(originalColor == color) return result;

        int rows = result.size();
        int cols = result[0].size();

        dfs(result, sr, sc, originalColor, color, rows, cols);

        return result;
    }
};