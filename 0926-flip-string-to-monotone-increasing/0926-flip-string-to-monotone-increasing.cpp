class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = 0, ans = 0;
        for(auto c : s) {
            if(c == '0')
                ans = min(ans + 1, n);
            else
                n++;
        }
        
        return ans;
    }
};