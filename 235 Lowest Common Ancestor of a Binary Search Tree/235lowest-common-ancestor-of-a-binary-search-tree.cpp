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
    bool check(TreeNode*root,TreeNode*p,TreeNode*q){
        if(p->val>root->val&&q->val<root->val||q->val>root->val&&p->val<root->val){
            return true;
        }
       return false;
    }
    TreeNode*f(TreeNode*root,TreeNode*p,TreeNode*q){
        if(check(root,p,q)){
            return root;
        }
        if(root==p||root==q){
           return root;
        }
        else{
            if(root->val<p->val){
               return  f(root->right,p,q);
            }
             else{
               return  f(root->left,p,q);
            }

        }

    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root,p,q);
    
        
    }
};