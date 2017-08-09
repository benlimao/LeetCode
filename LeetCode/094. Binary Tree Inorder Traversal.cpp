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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        inorderTraversal(root, inorder);
        return inorder;
    }
    void inorderTraversal(TreeNode* root, vector<int>& inorder)
    {
        if(root == NULL)
            return;
        if(root->left)
            inorderTraversal(root->left, inorder);
        inorder.push_back(root->val);
        if(root->right)
            inorderTraversal(root->right, inorder);
    }
};
