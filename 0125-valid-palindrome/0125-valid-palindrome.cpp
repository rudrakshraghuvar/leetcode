class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        
        for(auto c : s) {
            if(c >= 'A' && c <= 'Z')
                str += c+32;
            else if(c >= 'a' and c <= 'z')
                str += c;
            else if(c >= '0' && c <= '9')
                str += c;
        }
        
        int i = 0, j = str.size()-1;
        
        while(i < j) {
            if(str[i++] != str[j--])
                return false;
        }
        
        return true;
    }
};