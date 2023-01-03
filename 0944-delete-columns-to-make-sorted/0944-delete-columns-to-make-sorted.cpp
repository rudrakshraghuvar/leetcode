class Solution {
public:
    int minDeletionSize(vector<string>& s) {
        int n = s.size();
        int m = s[0].size();
        int ans = 0;
        
        for(int i = 0; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(s[j-1][i] > s[j][i]) {
                    ans++;
                    break;
                }
            }
        }
        
        return ans;
    }
};