class Solution {
public:
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        int n = score.size(), m = score[0].size();
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                if(score[i][k] < score[j][k])
                    swap(score[i], score[j]);
            }
        }
        
        return score;
    }
};