class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size(), m = n;
        unordered_map<int, int> mp;
        vector<int> ans;
        
        int i = 1, j = 0;
        while(n--) {
            int c = 0;
            mp[A[j++]] = 1;
            
            for(int k = 0; k < i; k++) {
                if(mp.find(B[k]) != mp.end())
                    c++;
            }
            ans.push_back(c);
            i++;
        }
        
        return ans;
    }
};