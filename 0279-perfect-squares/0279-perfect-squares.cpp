class Solution {
public:
//     int solve(int x, int sum) {
//         if(x == 0)
//             return 0;
//         if(sum == 0)
//             return 0;
        
//         int pick;
//         if(sum >= x*x)
//             pick = 1 + solve(x, sum-(x*x));
        
//         int notPick = solve(x-1, sum);
        
//         return max(pick, notPick);
//     }
    
    int numSquares(int n) {
        vector<int> dp(n+1,INT_MAX);
        dp[0]=0;
        int count = 1;
        while(count*count <= n) {
            int sq = count*count;
            for(int i = sq; i < n+1; i++)
                dp[i] = min(dp[i-sq] + 1,dp[i]);
            
            count++;
        }
        return dp[n];
    }
};