class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string> str(strs.begin(), strs.end());
        vector<vector<string>> ans;
        int n = size(strs);
        
        for(int i = 0; i < n; i++) {
            string sr = str[i];
            sort(sr.begin(), sr.end());
            str[i] = sr;
        }
        
        unordered_map<string, vector<int>> mp;
        for(int i = 0; i < n; i++) {
            mp[str[i]].push_back(i);
        }
        
        for(auto m : mp) {
            int l = size(m.second);
            vector<string> row;
            for(int i = 0; i < l; i++)
                row.push_back(strs[m.second[i]]);
            ans.push_back(row);
            row.clear();
        }
        return ans;
    }
};