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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;  
        preorderTraversal(root, preorder);
        return preorder;     
    }
    void preorderTraversal(TreeNode* root, vector<int>& preorder) {
        if(root == NULL)
            return;
        preorder.push_back(root->val);
        if(root->left)
            preorderTraversal(root->left, preorder);
        if(root->right)
            preorderTraversal(root->right, preorder);     
    }
};
