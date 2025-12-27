/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;
    Node() {}
    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void f(Node*root,vector<vector<int>>&ans,int lev){
         if(root==NULL){
            return ;
         }  
        if (lev == ans.size()) {
    ans.push_back({});
}

         ans[lev].push_back({root->val});
         lev++;
         for(auto chu:root->children){
         
            f(chu,ans,lev);
         }
    }
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>>ans;
        f(root,ans,0); 
        return ans;
    }
};