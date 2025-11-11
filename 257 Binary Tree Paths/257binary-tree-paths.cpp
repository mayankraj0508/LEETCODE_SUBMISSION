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
   vector<string>ant;
    void f(string ans,TreeNode*root){
        if(root==NULL){
            return ;
        }
      string t = to_string(root->val);
      ans = ans+t;
      ans.push_back('-');
      ans.push_back('>');
        if(root->left==NULL &&root->right==NULL){
            ans.pop_back();
            ans.pop_back();
            ant.push_back(ans);
            ans.clear();
            return ;

        }
      
        
      f(ans,root->left);
      f(ans,root->right);
        
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string ans = "";
        f(ans,root);
        return ant;
        
    }
};