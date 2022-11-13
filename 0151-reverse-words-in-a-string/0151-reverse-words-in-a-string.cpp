class Solution {
public:
    string trim(string s) {
        int n = s.length(), i = 0, j = n-1;
        while(i < n && s[i] == ' ')
            i++;
        while(j >= 0 && s[j] == ' ')
            j--;
        
        return s.substr(i, j-i+1);
    }
    
    string reverseWords(string s) {
        s = trim(s);
        int l = s.length();
        string ans = "";
        int j = l;
        
        for(int i = l-1; i >= 0; i--) {
            if(s[i] == ' ') {
                ans += s.substr(i+1, j-i);
                j = i-1;
            }
            else if(i == 0 && s[i] != ' ')
                ans += s.substr(i, j+1);
            
            if(i != 0 and s[i-1] != ' ' && s[i] == ' ')
                ans += " ";
        }
        
        return ans;
    }
};