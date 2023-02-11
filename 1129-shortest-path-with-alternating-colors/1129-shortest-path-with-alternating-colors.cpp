class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        vector<pair<int, int>> adj[n+1];
        
        for(auto vec : redEdges)
            adj[vec[0]].push_back({vec[1], 1});
        for(auto vec : blueEdges)
            adj[vec[0]].push_back({vec[1], 2});
        queue<vector<int>> q;
        q.push({0, 0, -1});
        
        while(!q.empty()) {
            auto currVec = q.front();
            q.pop();
            int currv = currVec[0], edgeColor = currVec[2];
            if(res[currv] == -1)
                res[currv] = currVec[1];
            
            for(auto &childPair : adj[currv]) {
                int childV = childPair.first, edgeColorofChild = childPair.second;
                if(childV != -1 && (edgeColor == -1 || edgeColor != edgeColorofChild)) {
                    q.push({childV, currVec[1] + 1, edgeColorofChild});
                    childPair.first = -1;
                }
            }
        }
        return res;
    }
};