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
     void f(TreeNode*root,int &sum){
        if(root==NULL){
            return ;
        }
        if(root->left&&root->left->left){
            if(root->val%2==0){
                sum = sum+root->left->left->val;
            }
        }
         if(root->left&&root->left->right){
            if(root->val%2==0){
                sum = sum+root->left->right->val;
            }
        }
         if(root->right&&root->right->right){
            if(root->val%2==0){
                sum = sum+root->right->right->val;
            }
        }
          if(root->right&&root->right->left){
            if(root->val%2==0){
                sum = sum+root->right->left->val;
            }
        }
        f(root->left,sum);
        f(root->right,sum);
     }
    int sumEvenGrandparent(TreeNode* root) {
        int sum = 0;
        f(root,sum);
        return sum;
        
    }
};