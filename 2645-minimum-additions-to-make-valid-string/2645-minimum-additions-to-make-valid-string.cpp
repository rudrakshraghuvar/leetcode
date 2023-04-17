class Solution {
public:
    int addMinimum(string w) {
        int i = 0, j = 'd';
        
        for(auto c : w) {
            i += c <= j;
            j = c; 
        }
        
        return 3*i - w.size();
    }
};