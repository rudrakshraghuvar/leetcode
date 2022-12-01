class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<pair<int, int>> row(m), col(n);
        
        for(int i = 0; i < m; i++) {
            int cnt1 = 0, cnt0 = 0;
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1)
                    cnt1++;
                else
                    cnt0++;
            }
            row[i] = {cnt1, cnt0};
        }
        
        for(int i = 0; i < n; i++) {
            int cnt1 = 0, cnt0 = 0;
            for(int j = 0; j < m; j++) {
                if(grid[j][i] == 1)
                    cnt1++;
                else
                    cnt0++;
            }
            col[i] = {cnt1, cnt0};
        }
        
        vector<vector<int>> ans;
    
        for(int i = 0; i < m; i++) {
            vector<int> r;
            for(int j = 0; j < n; j++)
                r.push_back(row[i].first+col[j].first-row[i].second-col[j].second);
            ans.push_back(r);
        }
    return ans;   
    }
};