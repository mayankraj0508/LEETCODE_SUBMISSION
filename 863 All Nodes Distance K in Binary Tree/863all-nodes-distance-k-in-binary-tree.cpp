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
    void f(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&m,queue<TreeNode*>&q){
        q.push(root);
        while(q.size()>0){
           TreeNode*temp = q.front();
           q.pop();
           if(temp->left!=NULL){
            q.push(temp->left);
            m[temp->left] = temp;
           }
           if(temp->right!=NULL){
            q.push(temp->right);
            m[temp->right] = temp;
           }
        }
    }
    void f2(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&m,queue<TreeNode*>&q2,vector<bool>&visited,TreeNode*target,vector<int>&ans,int k){
        q2.push(target);
        int curr_level = 0;
        while(q2.size()){
            int sz = q2.size();
            if(curr_level==k){
                break;
            }
            for(int i =0; i<sz; i++){
                TreeNode*temp = q2.front();
                q2.pop();
                if(temp->left&&visited[temp->left->val]!=true){
                    q2.push(temp->left);
                    visited[temp->left->val] = true;
                }
                   if(temp->right&&visited[temp->right->val]!=true){
                    q2.push(temp->right);
                    visited[temp->right->val] = true;
                }
                if(m[temp]&&visited[m[temp]->val]!=true){
                    q2.push(m[temp]);
                    visited[m[temp]->val] = true;

                }
            }
            curr_level++;
        }
        while(q2.size()){
            TreeNode*curr = q2.front();
            q2.pop();
            if(curr->val!=target->val){
            ans.push_back(curr->val);
            }    
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*>m;
        queue<TreeNode*>q;
        vector<int>ans;
        if(k==0){
            return {target->val};
        }
        vector<bool>visited(501,false);
        f(root,m,q);
        queue<TreeNode*>q2;
        f2(root,m,q2,visited,target,ans,k);
        return ans;
    }
};