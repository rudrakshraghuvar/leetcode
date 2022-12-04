class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> presum(n);
        presum[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            presum[i] = presum[i-1] + nums[i];
        
        int ans, mn = INT_MAX;
        for(int i = 0; i < n-1; i++) {
            int diff = abs((presum[i]/(i+1)) - ((presum[n-1]-presum[i])/(n-i-1)));
            
            if(diff < mn) {
                mn = diff;
                ans = i;
            }
        }
        
        return presum[n-1]/n < mn ? n-1 : ans;
    }
};