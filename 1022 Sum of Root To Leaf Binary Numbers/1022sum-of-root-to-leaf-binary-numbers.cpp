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
    int an(vector<int>&temp){
        int ans = 0;
        int n = temp.size();
        int i =0;
        while(n>0&&i<temp.size()){
            int x = temp[i]<<(n-1);
            ans = ans+x; 
            i++;
            n--;

        }
        return ans;
    }
    void f(TreeNode*&root,vector<int>temp,vector<vector<int>>&ans){
        if(root==NULL){
            return;
        }
        if(root->left==NULL&&root->right==NULL){
            temp.push_back(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return ;
        }

      temp.push_back(root->val);
      f(root->left,temp,ans);
      f(root->right,temp,ans);
      temp.pop_back();

    }
    int sumRootToLeaf(TreeNode* root) {
        vector<vector<int>>ans;
        vector<int>temp;
        f(root,temp,ans);
        int sum = 0;
        for(int i =0; i<ans.size(); i++){
            sum = sum+an(ans[i]);
        }
        return sum;
    }
};