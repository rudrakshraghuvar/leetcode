class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int vec[100005][2]={0};
		for(vector<int>& v:matches){
			vec[v[0]][0]++;
			vec[v[1]][1]++;
		}
		vector<vector<int>> ret(2);
		for(int i=0;i<100005;i++){
			if(vec[i][0]>0&&vec[i][1]==0){
				ret[0].push_back(i);
			}
			if(vec[i][1]==1){
				ret[1].push_back(i);
			}

		}
		return ret;
    }
};