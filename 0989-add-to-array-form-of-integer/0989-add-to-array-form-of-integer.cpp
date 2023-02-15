class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int n = num.size();
        
        while(n-- > 0 || k > 0) {
            if(n >= 0)
                k += num[n];
            ans.push_back(k % 10);
            k = k / 10;
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};