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
   int lev =0;
   void f22(vector<vector<int>>&ans , TreeNode*root,int idx){
    if(root==NULL||idx==lev){
        return ;

    }
    ans[idx].push_back(root->val);
    int k = idx+1;
    f22(ans,root->left,k);
    f22(ans,root->right,k);
   }
    int level(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return 1+max(level(root->left),level(root->right));
    }
    void f(vector<vector<int>>&ans,TreeNode*root){
         queue<TreeNode*>q;
         q.push(root);
         while(q.size()>0){
            int sz = q.size();
            vector<int>tem;
           for(int i=0;i<sz; i++){
               TreeNode*temp = q.front();
               q.pop();
               if(temp!=NULL){
               tem.push_back(temp->val);
               }
               if(temp!=NULL&&temp->left!=NULL) q.push(temp->left);
               if(temp!=NULL&&temp->right!=NULL) q.push(temp->right);

           }
           if(tem.size()>0){
             ans.push_back(tem); 
           }
  
            
         }
    }
    vector<vector<int>> levelOrder(TreeNode* root) {
        int n = level(root);
        lev  = n;
        cout<<lev;
        vector<vector<int>>ans(lev);
         f22(ans,root,0);
        return ans;
        
    }
};