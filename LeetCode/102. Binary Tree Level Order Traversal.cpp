/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 //1.前序遍历
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        oneLevelOrder(root, 0, res);
        return res;
    }
    void oneLevelOrder(TreeNode *root, int depth, vector<vector<int>>& res)
    {
        if(root == NULL)
            return;
        if(res.size() == depth)
            res.push_back(vector<int>());
        res[depth].push_back(root->val);
        if(root->left)
            oneLevelOrder(root->left, depth+1, res);
        if(root->right)
            oneLevelOrder(root->right, depth+1, res);
    }
};

//2.队列
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> >  res;
        if (root == NULL) 
            return res;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> tmp;
        while(!q.empty()) 
        {
            TreeNode* t = q.front();
            q.pop();
            if (t==NULL)
            {
                res.push_back(tmp);
                tmp.resize(0);
                if (q.size() > 0)
                    q.push(NULL);
            } 
            else 
            {
                tmp.push_back(t->val);
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
        }
        return res;
    }
};
