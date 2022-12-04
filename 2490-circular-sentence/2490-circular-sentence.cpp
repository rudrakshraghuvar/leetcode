class Solution {
public:
    bool isCircularSentence(string s) {
        vector<string> v;
        int idx = 0, l = s.size();
        
        for(int i = 0; i < l; i++) {
            if(s[i] == ' ') {
                v.push_back(s.substr(idx, i-idx));
                idx = i+1;
            }
        }
        v.push_back(s.substr(idx, l-idx));
        int n = v.size();
        
        if(n == 1) {
            string str = v[0];
            int sz = str.size();
            
            if(str[0] != str[sz-1])
                return false;
        }
        
        for(int i = 1; i < n; i++) {
            string str1 = v[i-1], str2 = v[i];
            int sz = str1.size();
            
            if(str1[sz-1] != str2[0])
                return false;
        }
        
        string str1 = v[0], str2 = v[n-1];
        int sz = str2.size();
        
        if(str1[0] != str2[sz-1])
            return false;
        
        return true;
    }
};