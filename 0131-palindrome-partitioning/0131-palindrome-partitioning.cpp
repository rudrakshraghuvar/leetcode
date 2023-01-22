class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, s, v, ans);
        return ans;
    }
    
    bool isPalindrome(int start, int end, string s) {
        while(start <= end) {
            if(s[start++] == s[end--]) continue;
            return false;
        }
        return true;
    }
    
    void solve(int idx, string s, vector<string> v, vector<vector<string>>& ans) {
        if(idx == s.length()) {
            ans.push_back(v);
            return;
        }
        
        for(int i=idx; i<s.length(); i++) {
            if(isPalindrome(idx, i, s)) {
                v.push_back(s.substr(idx, i-idx+1));
                solve(i+1, s, v, ans);
                v.pop_back();
            }
        }
    }
};