int dp[100][27][101][101];
class Solution {
public:
    string str;
    int solve(int i, int prev, int l, int k) {
        if(k < 0) return INT_MAX;
        if(i == str.size()) return 0;
        if(dp[i][prev][l][k] != -1) return dp[i][prev][l][k];
        
        int del = solve(i+1, prev, l, k-1);
        int keep = 0;
        if(prev == str[i]-'a') {
            if(l == 1 || l == 9 || l == 99) keep += 1;
            keep += solve(i+1, prev, l+1, k);
        }
        else
            keep = 1 + solve(i+1, str[i]-'a', 1, k);
        
        return dp[i][prev][l][k] = min(del, keep);
    }
    
    int getLengthOfOptimalCompression(string s, int k) {
        str = s;
        memset(dp, -1, sizeof(dp));
        return solve(0, 26, 0, k);
    }
};