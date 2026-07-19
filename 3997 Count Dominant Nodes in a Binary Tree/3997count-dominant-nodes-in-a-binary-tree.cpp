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
     vector<int>ans ;
    int f(TreeNode*root){
        if(root==NULL){
            return INT_MIN;
        }
 
        int left = f(root->left);
        int right = f(root->right);
        int mx = max(left,right);
        if(root->val>=mx){
            ans.push_back(root->val);
        }
        return max(root->val,mx);
    }

    int countDominantNodes(TreeNode* root) {
         int a = f(root);
        return ans.size();
        
        
    }
};