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
    void f(TreeNode*root,int &sum,int lo,int hi){
        if(root==NULL){
            return ;
        }
        if(root->val>=lo&&root->val<=hi){
           sum = sum+root->val;
        }
        f(root->left,sum,lo,hi);
        f(root->right,sum,lo,hi);
    }
    int rangeSumBST(TreeNode* root, int lo, int hi) {
        int sum = 0;
        f(root,sum,lo,hi);
        return sum;
        
    }
};