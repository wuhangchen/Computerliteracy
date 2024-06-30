//Given a binary tree, find its minimum depth.
//The minimum depth is the number of nodes along the shortest path from 
//the root node down to the nearest leaf node.

int min_depth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int depth = 1;
    std::queue<TreeNode*> q;
    if (root) {
        q.push(root);
    }
    while (!q.empty()) {
        for (int i = 0; i < q.size(); ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (!node->left && !node->right) {
                return depth;
            }
            if (node->left) {
                q.push(root->left);
            }
            if (node->right) {
                q.push(root->right);
            }
        }
        ++depth;
    }
    return -1;
}


int min_depth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int left = min_depth(root->left);
    int right = min_depth(root->right);

    return (left && right) ? 1 + min(left, right) : 1 + left + right;
}

int min_depth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int res = 0;
    std::queue<TreeNode*> q{root};
    while (!q.empty()) {
        ++res;
        for (int i = q.size(); i > 0; --i) {
            auto t = q.front();
            q.pop();
            if (!t->left && !t->right) {
                return res;
            }
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
    return -1;
}