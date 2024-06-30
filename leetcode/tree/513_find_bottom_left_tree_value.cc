// given a binary tree, find the left most value in 
// the last row of the tree

int find_bottom_left_value(TreeNode* root) {
    int max_depth = 1;
    res = root->val;
    helper(root, 1, max_depth, res);
    return res;
}

void helper(TreeNode* node, int depth, int& max_depth, int& res) {
    if (!node) {
        return ;
    }
    if (depth > max_depth) {
        max_depth = depth;
        res = node->val;
    }
    helper(node->left, depth + 1, max_depth, res);
    helper(node->right, depth + 1, max_depth, res);
}

int find_bottom_left_value(TreeNode* root) {
    int res = 0;
    std::queue<TreeNode*> q{{root}};
    while (!q.empty()) {
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* t = q.front();
            q.pop();
            if (i == 0) {
                res = t->val;
            }
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
    return res;
}

int find_bottom_left_value(TreeNode* root) {
    std::queue<TreeNode*> q{{root}};
    while (!q.empty()) {
        root = q.front();
        q.pop();
        if (root->right) {
            q.push(root->right);
        }
        if (root->left) {
            q.push(root->left);
        }
    }
    return root->val;
}