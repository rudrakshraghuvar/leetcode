class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int n = q.size(), m = d.size();
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                string s1 = q[i], s2 = d[j];
                int l = s1.size();
                int x = 0, cnt = 0;
                
                while(x < l) {
                    if(s1[x] != s2[x])
                        cnt++;
                    x++;
                }
                
                if(cnt <= 2) {
                    ans.push_back(s1);
                    break;
                }
            }
        }
        
        return ans;
    }
};