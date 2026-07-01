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
    int count(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        int lh = leftheight(root);
        int rh = rightheight(root);
        if(lh==rh){
            return (1<<lh)-1;
        }

         return 1+count(root->left)+count(root->right);
    }
    int leftheight(TreeNode*root){
        int ht = 0;
        while(root){
            ht++;
            root=root->left;
        }
        return ht;
    }
      int rightheight(TreeNode*root){
        int ht = 0;
        while(root){
            ht++;
            root=root->right;
        }
        return ht;
    }
    int countNodes(TreeNode* root) {
        return count(root);
      

        
    }
};