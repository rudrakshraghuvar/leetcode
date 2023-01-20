class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> row;
        solve(0, nums, row, ans);
        return ans;
    }
    
    void solve(int idx, vector<int>& num, vector<int>& row,
               vector<vector<int>>& ans) {
        if(size(row) >= 2) ans.push_back(row);
        
        unordered_set<int> hash;
        
        for(int i = idx; i < size(num); i++) {
            if((size(row) == 0 || num[i] >= row.back()) && 
               hash.find(num[i]) == hash.end()) {
                row.push_back(num[i]);
                solve(i+1, num, row, ans);
                row.pop_back();
                hash.insert(num[i]);
            }
        }
    }
};

// see notes section