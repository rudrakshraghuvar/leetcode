class Solution {
public:
    vector<int> findCoordinates(int curr, int n) {
        int r = n - ((curr-1)/n) - 1;
        int c = (curr-1) % n;
        if(r%2 == n%2)
            return {r, n-c-1};
        return {r, c};
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board.size();
        int step = 0;
        queue<int> q;
        q.push(1);
        vector<vector<bool>> vis(n, vector<bool>(n, false));
        vis[n-1][0] = true;
        while(!q.empty()) {
            int s = q.size();
            
            for(int i = 0; i < s; i++) {
                int x = q.front();
                q.pop();
                if(x == n*n)
                    return step;
                for(int k = 1; k <= 6; k++) {
                    if(k+x > n*n)
                        break;
                    vector<int> pos = findCoordinates(k+x, n);
                    int r = pos[0];
                    int c = pos[1];
                    if(vis[r][c] == true)
                        continue;
                    vis[r][c] = true;
                    if(board[r][c] == -1)
                        q.push(k+x);
                    else
                        q.push(board[r][c]);
                }
            }
            
            step++;
        }
        return -1;
    }
};