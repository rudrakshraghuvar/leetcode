class Solution {
public:
    
    // solved by using tabulation dp with space optimized
    
    int tribonacci(int n) {
        if(n < 2) return n;
        int prev1 = 0, prev2 = 1, prev3 = 1;
        for(int i = 3; i <= n; i++) {
            int curr = prev1 + prev2 + prev3;
            prev1 = prev2;
            prev2 = prev3;
            prev3 = curr;
        }
        return prev3;
    }
};