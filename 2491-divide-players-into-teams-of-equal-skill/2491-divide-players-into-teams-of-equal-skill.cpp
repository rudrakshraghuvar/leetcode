class Solution {
public:
    long long dividePlayers(vector<int>& s) {
        sort(s.begin(), s.end());
        int n = s.size();
        vector<pair<int, int>> vp;
        int sum = s[0] + s[n-1], i = 1, j = n-2;
        vp.push_back({s[0], s[n-1]});
        
        while(i < j) {
            if(s[i] + s[j] != sum)
                return -1;
            vp.push_back({s[i], s[j]});
            i++;
            j--;
        }
        
        long long ans = 0;
        
        for(auto& i : vp)
            ans += i.first * i.second;
        
        return ans;
    }
};