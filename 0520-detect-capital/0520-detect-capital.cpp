class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        int c1 = 0, c2 = 0;
        
        for(int i = 0; i < n; i++) {
            if(islower(word[i]))
                c1++;
            else if(isupper(word[i]))
                c2++;
        }
        
        if(c1 == n)
            return true;
        else if(c2 == n)
            return true;
        else if(c2 == 1 and isupper(word[0]))
            return true;
        return false;
    }
};