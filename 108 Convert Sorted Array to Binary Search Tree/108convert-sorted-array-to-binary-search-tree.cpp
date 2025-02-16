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
TreeNode*convert(int lo ,int hi,vector<int>&nums){
      if(lo>hi){
        return NULL;
    }
    int mid = lo + (hi-lo)/2;
    TreeNode*root = new TreeNode(nums[mid]);
    root->left = convert(lo,mid-1,nums);
    root->right = convert(mid+1,hi,nums);

    return root;
}

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        int lo = 0;
        int hi = n-1;
        int mid  = lo +(hi-lo)/2;
        TreeNode*root = new TreeNode(nums[mid]);
        return convert(lo,hi,nums);
       


        
    }
};