class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        int l = nums.size();
        set<int> s;
        
        for(int i = 0; i < l; i++)
            s.insert(nums[i]);
        
        for(int i = 0; i < l; i++) {
            string str = to_string(nums[i]);
            reverse(str.begin(), str.end());
            s.insert(stoi(str));
        }
        
        return s.size();
    }
};