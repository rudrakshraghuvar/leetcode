class Solution {
public:
    int minimumRounds(vector<int>& t) {
        int ans = 0;
        int n = t.size();
        map<int, int> m;
        
        for(int i = 0; i < n; i++)
            m[t[i]]++;
        
        for(auto i : m) {
            int x = i.second;
            if(x == 1)
                return -1;
            else if(x % 3 == 0)
                ans += x/3;
            else
                ans += x/3 + 1;
        }
        
        return ans;
    }
};