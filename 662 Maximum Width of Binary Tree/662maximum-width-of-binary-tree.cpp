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
    long long  ans  = 1;
    int f(TreeNode*root){
        if(root==NULL){
            return 0;
        }
        return 1+max(f(root->left),f(root->right));
    }
    #define pp pair<TreeNode*,long long >
    void bfs(TreeNode*root, int level){
        queue<pp>q;
        q.push({root,0});
        int x = 0;
       long long  mn = LLONG_MAX;;
        long long  mx = 0;
        while(q.size() && x<level){
            long long first  = q.front().second;

           
            int sz = q.size();
             
            ans  = max(ans,mx-mn+1);
            mn  = LLONG_MAX;
            mx =0;
            for(int i =0; i<sz; i++){
                TreeNode*temp = q.front().first;
                long long  idx= q.front().second;
                idx = idx-first;
                q.pop();
                if(temp->left){
                    mn = min(mn,(long long)2*idx);
                    mx = max(mx,(long long)2*idx);
                    q.push({temp->left,(long long)2*idx});
                }
                    if(temp->right){
                    mn = min(mn,(long long)2*idx+1);
                    mx = max(mx,(long long)2*idx+1);
                    q.push({temp->right,(long long)2*idx+1});
                }
            }
            x++;
        }
    

    }
    int widthOfBinaryTree(TreeNode* root) {
        int level  = f(root);
        bfs(root,level);     
        return ans ; 
    }
};