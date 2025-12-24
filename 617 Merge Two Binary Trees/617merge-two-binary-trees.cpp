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
void f(TreeNode* &root1, TreeNode* root2){
    if(root1 == NULL && root2 == NULL){
        return;
    }

    if(root2 != NULL){
        if(root1 == NULL){
            root1 = new TreeNode(root2->val); 
        }
        else{
            root1->val = root1->val + root2->val;
        }
    }

    if(root1 != NULL){
        f(root1->left, root2 ? root2->left : NULL);
        f(root1->right, root2 ? root2->right : NULL);
    }
}

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        f(root1,root2);
        return root1;
       

        
    }
};