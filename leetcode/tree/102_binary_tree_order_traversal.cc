// given a binary tree, return the level order traversal of it node values, from left to right
// right, level by level 

std::vector<std::vector<int> > level_order(TreeNode* root) {
    std::vector<std::vector<int> > res;
    if (root == nullptr) {
        return res;
    }
    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        std::vector<int> one_level;
        int size = one_level.size();

        for (int i =0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            one_level.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
            res.push_back(one_level);
        }
    }
    return res;
}

std::vector<std::vector<int> > level_order(TreeNode* root) {
    std::vector<std::vector<int> > res;
    level_order(root, 0, res);
    return res;
}

void level_order(TreeNode* root, int level, std::vector<std::vector<int> >& res) {
    if (!root) {
        return;
    }
    if (res.size() == level) {
        res.push_back({});
    }

    res[level].push_back(root->val);
    if (root->left) {
        level_order(root->left, level_order + 1, res);
    }
    if (root->right) {
        level_order(root->right, level + 1， res);
    }
}