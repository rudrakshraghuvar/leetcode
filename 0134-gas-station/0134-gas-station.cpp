class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum = 0;
        int totalsum = 0;
        int idx = 0;
        int n = cost.size();
        
        for(int i = 0; i < n; i++) {
            totalsum += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if(sum < 0) {
                sum = 0;
                idx = i + 1;
            }
        }
        
        return totalsum < 0 ? -1 : idx;
    }
};