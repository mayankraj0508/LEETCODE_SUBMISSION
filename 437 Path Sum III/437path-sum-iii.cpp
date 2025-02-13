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
    void helper(TreeNode*root,long long sum,int &count){
        if(root==NULL){
            return;
        }
        if(root->val==sum){
            count++;
            
        }
        sum = sum-root->val;
        helper(root->left,sum,count);
        helper(root->right,sum,count);

    }
    int pathSum(TreeNode* root, int targetSum) {
        if(root==NULL){
            return 0;
        }
        int count = 0;
        helper(root,targetSum,count);//root se path kon ho skta h wo nikallo fir uskke lefty thrn right
        count  = count + pathSum(root->left,targetSum)+pathSum(root->right,targetSum);
        return count;
        
    }
};