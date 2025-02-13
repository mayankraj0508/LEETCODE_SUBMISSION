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
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool flag ;
        int sum = targetSum;
        
        if(root==NULL){
            return false;
        }
        if(root->left==NULL && root->right==NULL){
            if(root->val==sum){
                return true;
            }
            
            
        }
        sum = sum-root->val;
        return hasPathSum(root->left,sum)||hasPathSum(root->right,sum);

        
        
    }
};