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
    int maxheight = 0;
    int dfs(TreeNode*root){
        if(root==nullptr){
            return 0;
        }
        int maxleft = dfs(root->left);
        int maxright = dfs(root->right);
        maxheight = max(maxheight, maxleft+maxright);

        return 1 + max(maxleft, maxright);

    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = dfs(root);
        return maxheight;
    }
};
