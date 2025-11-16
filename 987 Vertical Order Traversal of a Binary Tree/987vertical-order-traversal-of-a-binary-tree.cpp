class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // column -> list of (row, value)
        map<int, vector<pair<int, int>>> mp;

        // queue for BFS: node, row, col
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});  // root at row=0, col=0

        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            TreeNode* node = it.first;
            int row = it.second.first;
            int col = it.second.second;

            mp[col].push_back({row, node->val});

            if (node->left)
                q.push({node->left, {row + 1, col - 1}});

            if (node->right)
                q.push({node->right, {row + 1, col + 1}});
        }

        // final answer
        vector<vector<int>> ans;

        for (auto &colEntry : mp) {
            auto &nodes = colEntry.second;

            // sort: first by row, then by value
            sort(nodes.begin(), nodes.end());

            vector<int> colValues;
            for (auto &p : nodes)
                colValues.push_back(p.second);

            ans.push_back(colValues);
        }

        return ans;
    }
};
