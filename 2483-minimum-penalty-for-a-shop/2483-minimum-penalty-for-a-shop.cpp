class Solution {
public:
    int bestClosingTime(string c) {
        int ans = 0, l = c.size();
        vector<int> yes(l), no(l);
        
        if(c[0] == 'Y') { 
            yes[0] = 1;
            no[0] = 0;
        }
        else {
            yes[0] = 0;
            no[0] = 1;
        }
        
        for(int i = 1; i < l; i++) {
            if(c[i] == 'Y') {
                yes[i] = 1 + yes[i-1];
                no[i] = no[i-1];
            }
            else {
                yes[i] = yes[i-1];
                no[i] = 1 + no[i-1];
            }
        }
        
        int j = 0, min = yes[l-1];
        while(j < l) {
            int cnt = no[j] + yes[l-1] - yes[j];
                
            if(cnt < min) {
                min = cnt;
                ans = j+1;
            }
            j++;
        }
        
        return ans;
    }
};