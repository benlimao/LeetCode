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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() == 0 || preorder.size() != inorder.size())
            return NULL;
        
        //从前序遍历找到根节点
        TreeNode* root = new TreeNode(preorder[0]);
        
        //找到根节点在中序遍历中的位置(左子树和右子树的节点数量)
        int leftNum, rightNum;
        for(int i = 0; i < inorder.size(); i++)
        {
            if(inorder[i] == root->val)
            {
                leftNum = i;
                break;
            }
        }
        rightNum = inorder.size() - leftNum - 1;
        
        //递归构建左右子树
        if(leftNum)
        {
            vector<int> leftPre(preorder.begin() + 1, preorder.begin() + 1 + leftNum);
            vector<int> leftIn(inorder.begin(), inorder.begin() + leftNum);
            root->left = buildTree(leftPre, leftIn);
        }
        if(rightNum)
        {
            vector<int> rightPre(preorder.begin() + 1 + leftNum, preorder.end());
            vector<int> rightIn(inorder.begin() + 1 + leftNum, inorder.end());
            root->right = buildTree(rightPre, rightIn);
        }
        return root;
    }
};
