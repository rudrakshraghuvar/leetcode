class Solution {
public:
    bool solve(int i, int j, vector<vector<char>>& b, string w, int k) {
        int n = b.size();
        int m = b[0].size();
        if(i < 0 || j < 0 || i >= n || j >= m)
            return false;
        
        if(b[i][j] != w[k])
            return false;
        
        if (k == w.size()-1) 
            return true;
        
        char ch = b[i][j];
        b[i][j] = '*';
        bool opt1 = solve(i, j+1, b, w, k+1);
        bool opt2 = solve(i, j-1, b, w, k+1);
        bool opt3 = solve(i+1, j, b, w, k+1);
        bool opt4 = solve(i-1, j, b, w, k+1);
        
        b[i][j] = ch;
        
        return opt1 or opt2 or opt3 or opt4;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++)
                if(solve(i, j, board, word, 0))
                    return true;
        }
        
        return false;
    }
};