class Solution {
public:
    int strStr(string h, string n) {
        int hs = h.size(), ns = n.size();
        
        for(int i = 0; i <= abs(hs-ns); i++) {
            for(int j = 0; j < ns; j++) {
                if(h[i+j] != n[j])
                    break;
                if(j == ns-1)
                    return i;
            }
        }
        return -1;
    }
};