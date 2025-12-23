/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
//     vector<int>path1;
//     vector<int>path2;
//    bool path(vector<int>& paths,TreeNode* root, int target) {
//     if (root == NULL) return false;

//     // Add current node to path
//     paths.push_back(root->val);

//     // Check if current node is the target
//     if (root->val == target) return true;

//     // Recur for left and right subtree
//     if (path(paths, root->left,target) || path(paths,root->right, target))
//         return true;
//         paths.pop_back();
//         return false;
//    }
   
    bool find(TreeNode*root,TreeNode*target){
        if(root==NULL){
            return false;
        }
        if(root==target){
            return true;
        }
        return find(root->left,target)||find(root->right,target);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // vector<int>paths;
        // bool an = path(paths,root,q->val);
        // for(int i=0; i<paths.size(); i++){
        //     cout<<paths[i]<<" ";
            
        // }
        // return NULL;
        if(root==p||root==q){
            return root;
        }
        if(find(root->left,p)&&find(root->right,q)){
            return root;
        }
          if(find(root->left,q)&&find(root->right,p)){
            return root;
        }
        if(!find(root->left,p)&&find(root->right,q)){
            return lowestCommonAncestor(root->right, p, q);
        }
       
         if(find(root->left,p)&&!find(root->right,q)){
            return lowestCommonAncestor(root->left,  p,  q);
        }
          return root;
        
    }
};