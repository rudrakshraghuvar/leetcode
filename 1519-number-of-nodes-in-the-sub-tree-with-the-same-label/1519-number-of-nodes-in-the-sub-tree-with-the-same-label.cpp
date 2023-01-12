// class Solution {
// public:
//     vector<int> dfs(int node, int parent, vector<vector<int>>& adj, string s,
//                     vector<int>& ans) {        
//         vector<int> nodeCounts(26);
//         nodeCounts[s[node] - 'a'] = 1;

//         for (auto& child : adj[node]) {
//             if (child == parent) continue;
//             vector<int> childCounts = dfs(child, node, adj, s, ans);
            
//             for (int i = 0; i < 26; i++) {
//                 nodeCounts[i] += childCounts[i];
//             }
//         }

//         ans[node] = nodeCounts[s[node] - 'a'];
//         return nodeCounts;
//     }

//     vector<int> countSubTrees(int n, vector<vector<int>>& edges, string s) {
//         vector<vector<int>> adj(n);
//         for (auto& edge : edges) {
//             adj[edge[0]].push_back(edge[1]);
//             adj[edge[1]].push_back(edge[0]);
//         }
        
//         vector<int> ans(n, 0);
//         dfs(0, -1, adj, s, ans);
        
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, unordered_set<int>> adj;
        for (auto& edge : edges) {
            adj[edge[0]].insert(edge[1]);
            adj[edge[1]].insert(edge[0]);
        }

        vector<vector<int>> counts(n, vector<int>(26));
        queue<int> q;

        for (int node = 0; node < n; ++node) {
            counts[node][labels[node] - 'a'] = 1;
            if (node != 0 && adj[node].size() == 1) {
                q.push(node);
            }
        }

        while (q.size()) {
            int curr = q.front();
            q.pop();

            int parent = *adj[curr].begin();
            adj[parent].erase(curr);

            for (int i = 0; i < 26; ++i) {
                counts[parent][i] += counts[curr][i];
            }

            if (parent != 0 && adj[parent].size() == 1) {
                q.push(parent);
            }
        }

        vector<int> ans(n);
        for (int node = 0; node < n; ++node) {
            ans[node] = counts[node][labels[node] - 'a'];
        }

        return ans;
    }
};