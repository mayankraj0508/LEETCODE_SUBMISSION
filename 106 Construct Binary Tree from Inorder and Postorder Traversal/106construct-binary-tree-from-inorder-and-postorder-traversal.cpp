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
        TreeNode*f2(vector<int>&inorder,vector<int>&postorder){
        unordered_map<int,int>inmap;
        for(int i =0; i<inorder.size(); i++){
            inmap[inorder[i]] = i;
        }
       TreeNode*root = f(inorder,postorder,0,postorder.size()-1,0,inorder.size()-1,inmap);
        return root;
    }
    TreeNode*f(vector<int>&inorder, vector<int>&postorder,int poststart, int postend, int instart,int inend,unordered_map<int,int>&inmap){
        if(poststart>postend ||instart>inend){
            return NULL;
        }
        TreeNode*root =new TreeNode(postorder[postend]);
        int idx = inmap[postorder[postend]];
        int numleft = idx-instart;
        root->left = f(inorder,postorder,poststart,poststart+numleft-1,instart,idx-1,inmap);
        root->right= f(inorder,postorder,poststart+numleft,postend-1,idx+1,inend,inmap);
        return root;
        
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return f2(inorder,postorder);
        
    }
};