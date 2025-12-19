class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return NULL;

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        } 
        else if (key > root->val) {
            root->right = deleteNode(root->right, key);
        } 
        else {
            // 0 or 1 child
            if (!root->left) return root->right;
            if (!root->right) return root->left;

            // 2 children
            TreeNode* succ = root->right;
            while (succ->left) succ = succ->left;

            root->val = succ->val;
            root->right = deleteNode(root->right, succ->val);
        }
        return root;
    }
};
