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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        postTraversal(root, postorder);
        return postorder;     
    }
    void postTraversal(TreeNode* root, vector<int>& postorder) {
        if(root == NULL)
            return;
        if(root->left)
            postTraversal(root->left, postorder);
        if(root->right)
            postTraversal(root->right, postorder);
        postorder.push_back(root->val);
    }
};
