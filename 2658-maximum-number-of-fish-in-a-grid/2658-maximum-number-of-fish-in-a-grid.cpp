class Solution {
public:
    int solve(vector<vector<int>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if(i >= n || i < 0 || j >= m || j < 0 || grid[i][j] == 0)
            return 0;
        
        int res = grid[i][j];
        grid[i][j] = 0;
        
        res += solve(grid, i-1, j);
        res += solve(grid, i+1, j);
        res += solve(grid, i, j-1);
        res += solve(grid, i, j+1);
        
        return res;
    }
    
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                ans = max(ans, solve(grid, i, j));
            }
        }
        
        return ans;
    }
};