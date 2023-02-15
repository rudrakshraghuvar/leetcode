class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        int ans = 0;
        map<int, int> mp;
        for(auto b : banned)
            mp[b]++;
        
        for(int i = 1; i <= n; i++) {
            if(!mp[i] && i <= maxSum) {
                ans++;
                maxSum -= i;
            }
        }
        
        return ans;
    }
};