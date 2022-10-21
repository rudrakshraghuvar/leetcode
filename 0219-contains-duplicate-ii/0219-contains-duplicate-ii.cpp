class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int n=nums.size();
        
        for (int i=0;i<n;i++)
        {
            if (mp.find(nums[i])!=mp.end())
            {
                int d=abs(i-mp[nums[i]]);
                if (d<=k)
                    return true;
                mp[nums[i]]=i;
            }
            else
                mp[nums[i]]=i;
        }
        return false;
    }
};