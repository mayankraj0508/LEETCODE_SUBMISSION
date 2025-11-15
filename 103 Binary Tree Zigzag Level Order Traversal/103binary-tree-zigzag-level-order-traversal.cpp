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
  int find(TreeNode*root){
    if(root==NULL){
        return 0;
    }
    return 1+max(find(root->left),find(root->right));
  }
  void optimised(TreeNode*root,vector<vector<int>>&ans){
    queue<TreeNode*>q;
    q.push(root);
    int count =  0;
    while(q.size()>0){
        int sz  = q.size();
        vector<int>v;
        for(int i =0;i<sz; i++){
           TreeNode*temp = q.front();
           q.pop();
           if(temp!=NULL)
           v.push_back(temp->val);
           if(temp!=NULL&&temp->left!=NULL){
              q.push(temp->left);
           }
           if(temp!=NULL&&temp->right!=NULL){
               q.push(temp->right);
           }
           
        }
        if(v.size()!=0){
           count++;
           if(count%2==0){
            reverse(v.begin(),v.end());
            
           }
           ans.push_back(v);
        }
    }     
  }
   void f(TreeNode*root,int i,int target,vector<int>&v){
    if(root==NULL){
        return ;
   }
    if(i==target){
        v.push_back(root->val);
        return ;
    }
    f(root->left,i+1,target,v);
    f(root->right,i+1,target,v);
   }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        int n = find(root);
        optimised(root,ans);
        return ans;
        // for(int i =1; i<=n; i++){
        //     vector<int>v;
        //     f(root,1,i,v);
        //     if(i%2==0){
        //         reverse(v.begin(),v.end());
        //         ans.push_back(v);
        //     }
        //     else{
        //         ans.push_back(v);
        //     }
            
        // }
        // return ans;
    
        
    }
};