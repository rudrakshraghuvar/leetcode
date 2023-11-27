class Solution {
public:
    int beautifulSubstrings(string s, int k) {
        int n = s.size();
        int ans = 0;
        
        for(int j = 0; j < n; j++) {
            int c = 0, v = 0;
            for(int i = j; i < n; i++) {
                if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
                    v += 1;
                else
                    c += 1;
                
                if((v == c) && (v*c % k == 0))
                    ans++;
            }
        }
        
        return ans;
    }
};