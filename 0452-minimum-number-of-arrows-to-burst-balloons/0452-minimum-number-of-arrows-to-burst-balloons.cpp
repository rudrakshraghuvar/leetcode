class Solution {
public:
    static bool cmp(vector<int>&a, vector<int>& b) {
        return a[1] < b[1];
    }
    
    int findMinArrowShots(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp);
        int n = p.size(), ans = 1, j = 0;
        
        for(int i = 1;  i < n; i++) {
            if(p[i][1] >= p[j][1] && p[i][0] <= p[j][1])
                continue;
            else {
                ans++;
                j = i;
            }
        }
        
        return ans;
    }
};