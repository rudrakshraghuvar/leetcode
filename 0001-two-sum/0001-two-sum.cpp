class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        for(int i = 0; i < nums.size(); i++)
            mp[nums[i]] = i;
        
        for(int i = 0; i < nums.size(); i++) {
            int temp = target-nums[i];
            if(mp.count(temp) && mp[temp] != i) {
                ans.push_back(i);
                ans.push_back(mp[temp]);
                break;
            }
        }
        
        return ans;
    }
};