class Solution {
public:
    int divide(int dividend, int divisor) {
        while(dividend % divisor == 0)
            dividend /= divisor;
        
        return dividend;
    }
    
    bool isUgly(int n) {
        if(n <= 0) 
            return false;
        
        for(auto primefactor : {2,3,5})
            n = divide(n, primefactor);
        
        return n == 1;
    }
};