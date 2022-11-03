class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();
        vector<int> ans;
        
        for(auto n : nums)
            mp[n]++;
        
        for(auto m : mp) {
            if(m.second > n/3)
                ans.push_back(m.first);
        }
        
        return ans;
    }
};