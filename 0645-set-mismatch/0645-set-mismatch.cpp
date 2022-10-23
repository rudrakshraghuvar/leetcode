class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans, cnt(n+1, 0);
        
        for(int i = 0; i < n; i++)
            cnt[nums[i]]++;
        
        for(int i = 0; i < n+1; i++)
            if(cnt[i] > 1)
                ans.push_back(i);
        
        for(int i = 0; i < n+1; i++)
            if(cnt[i] == 0 && i != 0)
                ans.push_back(i);
        
        return ans;
    }
};