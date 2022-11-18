/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int minSwapsToSort(vector<int> arr) {
        int n = arr.size();
        pair<int, int> arrPos[n];
        
        for (int i = 0; i < n; i++) {
            arrPos[i].first = arr[i];
            arrPos[i].second = i;
        }

        sort(arrPos, arrPos + n);
        vector<bool> vis(n, false);
        
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i] || arrPos[i].second == i)
                continue;

            int cycle_size = 0;
            int j = i;
            while (!vis[j]) {
                vis[j] = 1;
                j = arrPos[j].second;
                cycle_size++;
            }
            
            ans += (cycle_size - 1);
        }

        return ans;
    }
    
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> arr;
        int ans = 0;
        
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            
            if(node != NULL) {
                arr.push_back(node->val);
                if(node -> left)
                    q.push(node->left);
                if(node -> right)
                    q.push(node->right);
            }
            else {
                ans += minSwapsToSort(arr);
                arr.resize(0);
                if(q.size() > 0)
                    q.push(NULL);
            }
        }
        
        return ans;
    }
};