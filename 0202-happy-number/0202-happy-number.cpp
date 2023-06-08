class Solution {
public:
    bool isHappy(int n) {
        int r = 0;
        
        while(true) {
            r += (n % 10)*(n % 10);
            n = n/10;
            
            if(n == 0) {
                if(r == 1)
                    return true;
                if(r == 4)
                    return false;
                n = r;
                r = 0;
            }
        }
        return true;
    }
};