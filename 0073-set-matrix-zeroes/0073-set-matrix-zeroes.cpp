class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<pair<int, int>> v;
        
        for(int  i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(matrix[i][j] == 0)
                    v.push_back({i, j});
            }
        }
        
        for(int i = 0; i < v.size(); i++) {
            int x = v[i].first, y = v[i].second;
            while(x >= 0)
                matrix[x--][y] = 0;
            x = v[i].first, y = v[i].second;
            while(x < n)
                matrix[x++][y] = 0;
            x = v[i].first, y = v[i].second;
            while(y >= 0)
                matrix[x][y--] = 0;
            x = v[i].first, y = v[i].second;
            while(y < m)
                matrix[x][y++] = 0;
        }
    }
};