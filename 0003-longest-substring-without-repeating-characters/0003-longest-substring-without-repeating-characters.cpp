class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> symb(256, -1);
        int ans = 0, start = -1;
        
        for(int i = 0; i < s.length(); i++) {
            if(symb[s[i]] > start)
                start = symb[s[i]];
            symb[s[i]] = i;
            ans = max(ans, i - start);
        }
        
        return ans;
    }
};