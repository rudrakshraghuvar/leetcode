class Solution {
public:
    int titleToNumber(string ct) {
        int s = ct.size()-1, res = 0;
        
        for(int i = 0; i < ct.size(); i++)
            res += pow(26, s--)*(ct[i] - 'A' + 1);
        
        return res;
    }
};