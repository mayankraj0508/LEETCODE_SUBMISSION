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
int n;
    void f(TreeNode*root,int lev,vector<int>&v){
        if(root==NULL){
            return ;
        }
        if(v.size()>n){
            return ;
        }
        if(v[lev]==-1){
            v[lev] = root->val;
        }
        f(root->right,lev+1,v);
        f(root->left,lev+1,v);
    }
    int level(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return 1+max(level(root->left),level(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
       n = level(root);
        vector<int>v(n,-1);
        f(root,0,v);
        return v;
        
        
    }
};