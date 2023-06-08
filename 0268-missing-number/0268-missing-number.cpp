class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        
        for(int i = 1; i <= n; i++) {
            sum += i;
            sum -= nums[i-1];
        }
        
        return sum;
    }
};