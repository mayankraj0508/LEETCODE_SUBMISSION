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
    TreeNode* f(TreeNode*root,unordered_set<int>&s,vector<TreeNode*>&ans){
        if(root==NULL){
            return NULL ;
        }
       root->left =  f(root->left,s,ans);
       root->right =   f(root->right,s,ans);
         if(s.find(root->val)!=s.end()){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;

         }
         return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        unordered_set<int>s;
        for(int i=0; i<del.size(); i++){
            s.insert(del[i]);
        }
        vector<TreeNode*>ans;
        TreeNode*node = f(root,s,ans);
        if(node){
            ans.push_back(node);
            return ans;
        }
        return ans;
    }
};