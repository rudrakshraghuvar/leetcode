class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int k = 1000;
        vector<int> freq(2*k + 1);
        
        for(auto a : arr)
            freq[a + k]++;
        
        sort(freq.begin(), freq.end());
        
        for(int i = 0; i < 2*k; i++)
            if(freq[i] and freq[i] == freq[i+1])
                return false;
        
        return true;
    }
};