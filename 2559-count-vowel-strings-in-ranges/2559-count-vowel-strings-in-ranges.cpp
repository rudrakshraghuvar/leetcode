class Solution {
public:
    bool isVowel(char c) {
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        return false;
    }
    
    vector<int> vowelStrings(vector<string>& w, vector<vector<int>>& q) {
        int n = q.size();
        vector<int> ans(n), tmp;
        
        for(auto s : w) {
            int l = s.size();
            if(isVowel(s[0]) && isVowel(s[l-1]))
                tmp.push_back(1);
            else
                tmp.push_back(0);
        }
        int s = tmp.size();
        vector<int> preSum(s);
        preSum[0] = tmp[0];
        
        for(int i = 1; i < s; i++)
            preSum[i] = tmp[i] + preSum[i-1];
        
        int i = 0;
        for(auto x : q) {
            if(x[0] == 0)
                ans[i] = preSum[x[1]];
            else
                ans[i] = preSum[x[1]]-preSum[x[0]-1];
            i++;
        }
        
        return ans;
    }
};