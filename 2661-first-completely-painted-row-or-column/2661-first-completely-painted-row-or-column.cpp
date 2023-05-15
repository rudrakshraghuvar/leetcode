class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> mp1, mp2;
        int r = mat.size(), c = mat[0].size();
        
        for(int i = 0; i < r; i++) {
            for(int j = 0; j < c; j++) {
                mp1[mat[i][j]] = i;
                mp2[mat[i][j]] = j;
            }
        }
        
        vector<int> a(r, 0), b(c, 0);
        for(int i = 0; i < arr.size(); i++) {
            a[mp1[arr[i]]]++;
            b[mp2[arr[i]]]++;
            if(r == c) {
                if(a[mp1[arr[i]]] == r)
                    return i;
                if(b[mp2[arr[i]]] == c)
                    return i;
            }
            else {
                if(a[mp1[arr[i]]] == c)
                    return i;
                if(b[mp2[arr[i]]] == r)
                    return i;
            }
        }
        
        return 0;
    }
};