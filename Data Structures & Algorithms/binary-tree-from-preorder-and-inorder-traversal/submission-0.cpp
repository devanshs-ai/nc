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
    TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend){
        if(prestart>preend || instart>inend){
            return nullptr;
        }

        int rootValue = preorder[prestart];
        TreeNode*root = new TreeNode(rootValue);
        
        int rootindex = instart;
        while(inorder[rootindex]!=rootValue){
            rootindex++;
        }

        int leftsize = rootindex-instart;

        root->left = build(preorder, prestart+1, prestart+leftsize, inorder, instart, rootindex-1);

        root->right = build(preorder, prestart+leftsize+1, preend, inorder, rootindex+1, inend);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(
                preorder,
                0,
                preorder.size() - 1,
                inorder,
                0,
                inorder.size() - 1
            );
    }
};
