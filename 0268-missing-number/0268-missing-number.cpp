class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), a = 0, b = 0;
        
        for(int i = 0; i <= n; i++)
            a ^= i; 
        
        for(int i = 0; i < n; i++) {
            b ^= nums[i];
        }
        
        return a^b;
    }
};