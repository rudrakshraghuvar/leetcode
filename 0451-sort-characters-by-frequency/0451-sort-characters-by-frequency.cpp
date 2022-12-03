class Solution {
public:
    static bool cmp(pair<char, int>& a, pair<char, int>& b) {
        return a.second > b.second;
    }
    
    string frequencySort(string s) {
        unordered_map<char, int> mp;
        
        for(int i = 0; i < s.size(); i++)
            mp[s[i]]++;
        
        vector<pair<char, int>> vp;
        for(auto& it : mp)
            vp.push_back(it);
        
        sort(vp.begin(), vp.end(), cmp);
        string ans = "";
        
        for(auto& c : vp) {
            while(c.second--)
                ans += c.first;
        }
        return ans;
    }
};