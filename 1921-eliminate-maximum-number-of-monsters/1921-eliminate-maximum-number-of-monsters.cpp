class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n = dist.size();
        vector<int> temp(n);
        
        for(int i = 0; i < n; i++)
            temp[i] = ceil((float)dist[i]/speed[i]);
        
        sort(temp.begin(), temp.end());
        
        int i;
        
        for(i = 0; i < n; i++) {
            if(temp[i] < i+1)
                break;
        }
        
        if(i == 0)
            return 1;
        return i;
    }
};