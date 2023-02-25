class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, buyS = prices[0];
        
        for(int i = 1; i < prices.size(); i++) {
            if(prices[i] - buyS < 0)
                buyS = prices[i];
            else
                ans = max(ans, prices[i]-buyS);
        }
        
        return ans;
    }
};