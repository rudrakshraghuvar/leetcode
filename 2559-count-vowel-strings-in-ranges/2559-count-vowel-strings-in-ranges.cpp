class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        vector<int> ans, tmp(1);
        
        for(auto s : w) {
            int l = s.size();
            tmp.push_back(tmp.back() + (isVowel(s[0]) && isVowel(s[l-1])));
        }
    
        for(auto x : q)
            ans.push_back(tmp[x[1]+1] - tmp[x[0]]);
        
        return ans;
    }
};