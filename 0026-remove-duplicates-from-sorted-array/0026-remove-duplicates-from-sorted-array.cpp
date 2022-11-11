class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, l = nums.size(), j = 1;
        for(int i = 1; i < l; i++) {
            if(nums[i-1] == nums[i])
                cnt++;
            else
                nums[j++] = nums[i];
        }
        
        return l-cnt;
    }
};