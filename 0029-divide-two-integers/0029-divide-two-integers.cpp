class Solution {
public:
    int divide(int dividend, int divisor) {
        long long int q = 1LL*dividend/divisor;
        
        if(q < INT_MIN)
            return INT_MIN;
        else if(q > INT_MAX)
            return INT_MAX;
        return q;
    }
};