class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int t=n/3 , res=0;
        int i=n-2;
        sort(piles.begin(),piles.end());
        while(t--){
            res+=piles[i];
            i-=2;
        }
        return res;
    }
};