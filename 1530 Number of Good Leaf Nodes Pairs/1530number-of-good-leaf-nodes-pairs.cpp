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
    void mapping(unordered_map<TreeNode*,TreeNode*>&m,TreeNode*root){
        if(root==NULL){
            return ;
        }
        if(root->left){
            m[root->left] = root;
        }
        if(root->right){
            m[root->right]= root;
        }
        mapping(m,root->left);
        mapping(m,root->right);
    }
    void leafnodes(TreeNode*root,set<TreeNode*>&leaf){
        if(root==NULL){
            return ;
        }
        if(root->left==NULL&&root->right==NULL){
            leaf.insert(root);
        }
        leafnodes(root->left,leaf);
        leafnodes(root->right,leaf);
    }
    int counts(TreeNode*lf,unordered_map<TreeNode*,TreeNode*>&m,int distance){
        unordered_map<TreeNode*,bool>visited;
        queue<TreeNode*>q;
        visited[lf] = true;
        q.push(lf);
        int dist=-1; 
        int count = 0;
        while(q.size()){
            int sz = q.size();
            dist++;
            for(int i =0 ;i<sz; i++){
                TreeNode*temp = q.front();
               
                if(temp&&temp->left==NULL&&temp->right==NULL){
                    if(temp!=lf&&dist<=distance){
                        count++;
                    }
                }
                 if(dist>distance){
                    break;
                }
                q.pop();
                
                if(temp->left!=NULL&& visited.find(temp->left)==visited.end()){
                    q.push(temp->left);
                    visited[temp->left] = true;
                }
                if(temp->right!=NULL&& visited.find(temp->right)==visited.end()){
                    q.push(temp->right);
                     visited[temp->right] = true;
                }
                if(  m[temp]!=NULL  && visited.find(m[temp])==visited.end()){
                    q.push(m[temp]);
                    visited[m[temp]] = true;
                }

            }
            if(dist>distance){
                break;
            }
        }
      return count;
    }
    int countPairs(TreeNode* root, int distance) {
        unordered_map<TreeNode*,TreeNode*>m;
        m[root] = NULL;
        mapping(m,root);
        set<TreeNode*>leaf;
        leafnodes(root,leaf);
        int count = 0;
        for(auto x:leaf){
         count = count+counts(x,m,distance);

        }
        if(count==1){
            return 1;
        }
        return count/2;


        
    }
};