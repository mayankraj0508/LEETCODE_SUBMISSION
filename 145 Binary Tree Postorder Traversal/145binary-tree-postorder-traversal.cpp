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
    vector<int>f(TreeNode*root){
        stack<TreeNode*>st;
        st.push(root);
        vector<int>ans;
        
        while(st.size()>0){
           TreeNode*t  = st.top();
           if(t!=NULL)
           ans.push_back(t->val);
           st.pop();
           if(t!=NULL&&t->left!=NULL){
            st.push(t->left);
           }
           if(t!=NULL&&t->right!=NULL){
            st.push(t->right);
           }
        }
        reverse(ans.begin(),ans.end());
        return ans;

    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans = f(root);
        return ans;
        
    }
};