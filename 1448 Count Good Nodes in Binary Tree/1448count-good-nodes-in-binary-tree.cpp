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
    void f(TreeNode*root,int &count,int mx){
        if(root==NULL){
            return ;
        }
        if(root->val>=mx){
            count++;
            mx = root->val;
        }
        f(root->left,count,mx);
        f(root->right,count,mx);
    }
    int goodNodes(TreeNode* root) {
        int count = 0;
        int mx = INT_MIN;
        f(root,count,mx);
        return count;
        
    }
};