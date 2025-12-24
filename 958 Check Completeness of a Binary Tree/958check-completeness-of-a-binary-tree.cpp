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
    void f(TreeNode*root,queue<TreeNode*>&q,bool flag,bool &ans){
        q.push(root);
        flag = false;
        while(q.size()>0){
            int sz = q.size();
            for(int i =0; i<sz; i++){
            TreeNode*temp = q.front();
            q.pop();
            if(flag==true&&temp!=NULL){
               ans = false;
               break;
            }
            if(temp==NULL){
                flag = true;  
            }
            if(temp){
                q.push(temp->left);
            }
            if(temp){
                q.push(temp->right);
            }
            }
            if(ans==false){
                break;
            }
        }
    }


    bool isCompleteTree(TreeNode* root) {
       
     bool ans = true;
     bool flag;
     queue<TreeNode*>q;
     f(root,q,flag,ans);
     return ans;

        
    }
};