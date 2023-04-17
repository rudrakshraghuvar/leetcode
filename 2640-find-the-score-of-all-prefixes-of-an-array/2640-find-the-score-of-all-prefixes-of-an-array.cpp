class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& nums) {
        vector<long long> ans(nums.size());
        ans[0] = 2*nums[0];
        
        long long mx = nums[0];
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > mx)
                mx = nums[i];
            
            ans[i] = ans[i-1] + mx + 1LL*nums[i];
        }
        
        return ans;
    }
};