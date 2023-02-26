class Solution {
public:
    int dp[501][501];
    
    int solve(int i, int j, string w1, string w2) {
        if(i < 0) return j+1;
        if(j < 0) return i+1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(w1[i] == w2[j]) 
            return dp[i][j] = solve(i-1, j-1, w1, w2);
        int del = 1 + solve(i-1, j, w1, w2); // delete
        int rep = 1 + solve(i-1, j-1, w1, w2); // replace
        int ins = 1 + solve(i, j-1, w1, w2); // insert
        return dp[i][j] = min(del, min(rep, ins));
    }
    
    int minDistance(string w1, string w2) {
        int n1 = w1.size(), n2 = w2.size();
        
        memset(dp, -1, sizeof(dp));
        
        return solve(n1-1, n2-1, w1, w2);
    }
};