class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int n = nums.size(), res = 0;
        vector<long long> preSum(n);
        
        preSum[0] = nums[0];
        for(int i = 1; i < n; i++)
            preSum[i] = nums[i] + preSum[i-1];
        
        for(auto p : preSum)
            if(p > 0)
                res++;
        
        return res;
    }
};