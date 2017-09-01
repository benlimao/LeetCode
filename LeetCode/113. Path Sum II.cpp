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
    vector<vector<int>> paths;
    vector<int> path;
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return paths;
    }
    void dfs(TreeNode* root, int rest)
    {
        if(!root)
            return;
        path.push_back(root->val);
        if(rest - root->val == 0 && !root->left && !root->right)
            paths.push_back(path);
        else
        {
            if(root->left)
                dfs(root->left, rest - root->val);
            if(root->right)
                dfs(root->right, rest - root->val);
        }
        path.pop_back();
    }
};
