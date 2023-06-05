class Solution {
public:
    string longestCommonPrefix(vector<string>& s) {
        string ans = "";
        sort(s.begin(), s.end());
        string s1 = s[0], s2 = s[s.size()-1];
        int l1 = s1.size(), l2 = s2.size();
        
        for(int i = 0; i < min(l1, l2); i++) {
            if(s1[i] != s2[i])
                return ans;
            ans += s1[i];
        }
        return ans;
    }
};