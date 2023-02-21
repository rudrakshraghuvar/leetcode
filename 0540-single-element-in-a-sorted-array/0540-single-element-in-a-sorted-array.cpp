class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), l = 0, r = n-1;
        
        while(l <= r) {
            int m = l + ((r-l) / 2);
            bool isHalfEven = (m-l) % 2 == 0;
            
            if(m+1 < n && nums[m] == nums[m+1]) {
                if(isHalfEven)
                    l = m+2;
                else
                    r = m-1;
            }
            else if(m && nums[m] == nums[m-1]) {
                if(isHalfEven)
                    r = m-2;
                else
                    l = m+1;
            }
            else
                return nums[m];
        }
        
        return 0;
    }
};