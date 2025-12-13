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
    void f(TreeNode*root,int start,queue<TreeNode*>&q,unordered_map<TreeNode*,TreeNode*>&m,TreeNode*&target){
        q.push(root);
        while(q.size()>0){
            int sz = q.size();
            for(int i =0; i<sz; i++){
                TreeNode*temp = q.front();
                if(temp->val==start){
                    target = temp;
                }
                q.pop();
                if(temp->left){
                    q.push(temp->left);
                    m[temp->left] = temp;
                }
                if(temp->right){
                    q.push(temp->right);
                    m[temp->right] = temp;
                }

            }
        }
    }
    void f2(TreeNode*&
    target,queue<TreeNode*>&q2,unordered_map<TreeNode*,TreeNode*>&m,unordered_map<TreeNode*,bool>&visited,int &ans){
        if(target!=NULL){
        q2.push(target);
        visited[target] = true;
        }
        
        while(q2.size()){
            int sz = q2.size();
            for(int i=0; i<sz; i++){
                TreeNode*temp = q2.front();
                q2.pop();
                if(temp==NULL){
                    continue;
                }
                if(temp->left!=NULL&&visited.find(temp->left)==visited.end()){
                    q2.push(temp->left);
                    visited[temp->left] = true;
                }
                 if(temp->right&&visited.find(temp->right)==visited.end()){
                    q2.push(temp->right);
                    visited[temp->right] = true;
                }
                if(m.find(temp)!=m.end()&&visited.find(m[temp])==visited.end()){
                    q2.push(m[temp]);
                    visited[m[temp]] = true;
                }
            }
            ans++;
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        queue<TreeNode*>q;
        queue<TreeNode*>q2;
        unordered_map<TreeNode*,TreeNode*>m;
        unordered_map<TreeNode*,bool>visited;
        int ans = -1;
        TreeNode*target = NULL;
        f(root,start,q,m,target);
        f2(target,q2,m,visited,ans);
        return ans;

    
        
    }
};