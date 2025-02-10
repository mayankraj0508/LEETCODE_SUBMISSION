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
    void helper(TreeNode*root,vector<int>ans1,vector<vector<int>>&ans,int sum){
        if(root==NULL){
            return;
        }
        if(root->left==NULL && root->right==NULL){
            if(sum==root->val){
                ans1.push_back(root->val);
                ans.push_back(ans1);
                return;
            }
            return;
        }
        ans1.push_back(root->val);
        sum = sum-root->val;
        helper(root->left,ans1,ans,sum);
        helper(root->right,ans1,ans,sum);



    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans1;
        vector<vector<int>>ans;
        int sum = targetSum;
        helper(root,ans1,ans,sum);
        return ans;
        
    }
};