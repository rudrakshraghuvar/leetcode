class Solution {
public:
    int largestPrime(int num) {
        for (int i = num-1; i > 0; i--) {
            if (num%i==0)
            return i;
        }
        
        return 0;
    }
    
    bool isprime(int num) {
        for (int i = num-1; i > 1; i--) {
            if (num%i == 0)
            return false;
        }
        
        return true;
    }
    
    int minSteps(int n) {
        if(n == 1) 
            return 0;
        if (n == 2) 
            return 2;
        if(n % 2 != 0 && isprime(n)) 
            return n;
        else if (n%2) {
            int lp=largestPrime(n);
            return minSteps(lp)+n/lp;
        }
        
        if(n % 2 == 0)
            return 2+minSteps(n/2);
        
        return 0;
    }
};