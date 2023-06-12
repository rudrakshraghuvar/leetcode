class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), sum = 1, cnt = 0, sum1 = 1, x;
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            sum *= nums[i];
            if(nums[i] == 0) {
                cnt++;
                x = i;
            }
            else
                sum1 *= nums[i];
        }
        
        if(cnt >= 2)
            return ans;
        else if(cnt == 1) {
            ans[x] = sum1;
            return ans;
        }
        
        for(int i = 0; i < n; i++)
            ans[i] = sum / nums[i];
        
        return ans;
    }
};