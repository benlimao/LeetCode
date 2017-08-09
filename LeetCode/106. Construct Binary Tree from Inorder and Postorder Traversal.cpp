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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size() == 0 || inorder.size() != postorder.size())
            return NULL;
        
        //从后序遍历找到根节点
        TreeNode* root = new TreeNode(postorder[postorder.size() - 1]);
        
        //从中序遍历获取左右子树的节点数量
        int leftNum, rightNum;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                leftNum = i;
                break;
            }
        }
        rightNum = inorder.size() - 1 - leftNum;
        
        //递归构建左右子树
        if(leftNum)
        {
            vector<int> leftIn(inorder.begin(), inorder.begin() + leftNum);
            vector<int> leftPost(postorder.begin(), postorder.begin() + leftNum);
            root->left = buildTree(leftIn, leftPost);
        }
        if(rightNum)
        {
            vector<int> rightIn(inorder.begin() + 1 + leftNum, inorder.end());
            vector<int> rightPost(postorder.begin() + leftNum, postorder.end() - 1);
            root->right = buildTree(rightIn, rightPost);
        }
        return root;
    }
};
