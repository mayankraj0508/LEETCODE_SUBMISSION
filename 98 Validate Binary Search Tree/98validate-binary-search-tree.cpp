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
     long long  MAXX(TreeNode*root){
        if(root==NULL){
            return LLONG_MIN;
        }
        return max((long long)root->val,MAXX(root->right));
    }
      long long  MINN(TreeNode*root){
        if(root==NULL){
            return LLONG_MAX;
        }
        return min((long long)root->val,MINN(root->left));
    }
    bool isValidBST(TreeNode* root) {
                if(root==NULL){
            return true;
        }
       else if(root->left==NULL && root->right==NULL){
        return true;

       }
        long long a = MAXX(root->left);
        long long b= MINN(root->right);
        if(a>=(long long)root->val){
            return false;
        }
        else if(b<=(long long)root->val){
            return false;
        }
        else{
            return (isValidBST(root->left)&& isValidBST(root->right));
        }

        
    }
};