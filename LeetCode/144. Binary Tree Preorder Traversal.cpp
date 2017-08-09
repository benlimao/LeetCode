/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> preorder;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL)
            return preorder;  
        preTraversal(root);
        return preorder;     
    }
    void preTraversal(TreeNode* root) {
        preorder.push_back(root->val);
        if(root->left)
            preorderTraversal(root->left);
        if(root->right)
            preorderTraversal(root->right);     
    }
};
