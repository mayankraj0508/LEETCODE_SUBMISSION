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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode*data = new TreeNode(val);
        if(root==NULL){
            root = data;
        }
      

        if(val>root->val){
            if(root->right==NULL){
                root->right= data;
                return root;
            }

            insertIntoBST(root->right,val);

        }
        if(val<root->val){
            if(root->left==NULL){
                root->left = data;
                return root;
            }
            insertIntoBST(root->left,val);

        }
        return root;

        
    }
};