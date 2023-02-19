class Solution {
public:
//     int solve(int i, vector<int> a, int k) {
//         int n = a.size();
//         if(i == n) return 0;
        
//         int res = solve(i+1, a, k);
//         int val = a[i] + k;
//         int j = upper_bound(a.begin(), a.end(), val) - a.begin();
        
//         if(j >= n) return res;
        
//         res = max(res, j - i + 1);
//         return res;
//     }
    
//     int maximizeWin(vector<int>& a, int k) {
//         int res = 0;
//         int n = a.size();
        
//         for(int i = 0; i < n; i++) {
//             int val = a[i] + k;
//             int j = upper_bound(a.begin(), a.end(), val) - a.begin();
//             if(j >= n) 
//                 break;
//             int prevPrizes = j - i + 1;
//             res = max(res, prevPrizes + solve(i + 1, a, k));
//         }
        
//         return res;
//     }
    
    int maximizeWin(vector<int>& A, int k) {
        int res = 0, n = A.size(), j = 0;
        vector<int> dp(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            while (A[j] < A[i] - k)
                ++j;
            dp[i + 1] = max(dp[i], i - j + 1);
            res = max(res, i - j + 1 + dp[j]);
        }
        return res;
    }
};