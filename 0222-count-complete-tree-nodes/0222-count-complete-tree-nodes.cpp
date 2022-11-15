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
    int leftH(TreeNode* root) {
        int cnt = 0;
        
        while(root) {
            root = root->left;
            cnt++;
        }
        
        return cnt;
    }
    
    int rightH(TreeNode* root) {
        int cnt = 0;
        
        while(root) {
            root = root->right;
            cnt++;
        }
        
        return cnt;
    }
    
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        
        int lh = leftH(root);
        int rh = rightH(root);
        
        if(lh == rh)
            return pow(2, rh)-1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};