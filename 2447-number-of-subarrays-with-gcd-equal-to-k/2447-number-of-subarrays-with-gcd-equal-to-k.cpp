class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int ans = 0, n = nums.size();
        
        for(int i = 0; i < n; i++) {
            if(nums[i] % k != 0)
                continue;
            if(nums[i] == k)
                ans++;
            int g = nums[i];
            for(int j = i+1; j < n; j++) {
                if(nums[i] % k == 0) {
                    g = __gcd(g, nums[j]);
                    if(g == k)
                        ans++;
                }
                else
                    break;
            }
        }
        return ans;
    }
};