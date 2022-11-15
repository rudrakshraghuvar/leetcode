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
    vector<vector<int>> verticalTraversal(TreeNode* root) { 
        queue<pair<int, TreeNode*>> q;
        q.push({0, root});
        map <int, vector<int>> mp;
        
        while(!q.empty()) {
            int s=q.size();
            multiset<pair<int,int>> st;
            while(s--)
            {
                TreeNode *node = q.front().second;
                int pos = q.front().first;
                
                st.insert({pos,node->val});
                q.pop();
            
                if(node->left)
                    q.push({pos-1, node->left});
                if(node->right)
                    q.push({pos+1, node->right});   
            }
            for (auto x:st)
                mp[x.first].push_back(x.second);

          
        }
        
        vector<vector<int>> ans;
        for(auto m : mp)
            ans.push_back(mp[m.first]);
        
        return ans;
    }
};