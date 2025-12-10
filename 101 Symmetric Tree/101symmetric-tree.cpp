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
//    void pre2(TreeNode*root,vector<int>&second){
//       if(root==NULL){
//         second.push_back(INT_MAX);
//         return ;
//       }
//       second.push_back(root->val);
//       pre2(root->right,second);
//       pre2(root->left,second);
       
//    }
//    void  pre(TreeNode*root,vector<int>&first){
//       if(root==NULL){
//         first.push_back(INT_MAX);
//         return ;
//       }
//       first.push_back(root->val);
//       pre(root->left,first);
//       pre(root->right,first);
//    }
    bool f(TreeNode*left,TreeNode*right){
        if(left==NULL||right==NULL){
           return  left==right;
        }
        if(left->val!=right->val){
        return false;
        }
        return f(left->left,right->right)&&f(left->right,right->left);
    }
    bool isSymmetric(TreeNode* root) {
        // vector<int>first;
        // pre(root->left,first);
        // vector<int>second;
        // pre2(root->right,second);
        // int k = min(first.size(),second.size());
        // if(first.size()!=second.size()){
        //     return false;
        // }
        // for(int i =0; i<k; i++){
        //     if(first[i]!=second[i]){
        //         return false;
        //     }
        // }
        // return true;
       if(root==NULL){
        return true;
       } 
       return f(root->left,root->right);
        
    }
};