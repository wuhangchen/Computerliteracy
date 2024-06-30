// given a binary tree, return the botten-up level order traversal of its nodes values, 
// from the left to right, level by level from leaf to road.

std::vector<std::vector<int> > level_order_buttom(TreeNode* root) {
    std::vector<std::vector<int> > res;
    if (root == nullptr) {
        return res;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()) {
        std::vector<int> onelevel;
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            onelevel.push_back(node->val);
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
        res.insert(res.begin(), onelevel);
    }
    return res;
}

std::vector<std::vector<int> > level_order_buttom(TreeNode* node) {
    std::vector<std::vector<int> > res;
    level_order(root, 0, res);
    return std::vector<std::vector<int> >(res.rbegin(), res.rend());
}

void level_order(TreeNode* root, int level, std::vector<std::vector<int> >& res) {
    if (!root) {
        return ;
    }
    if (res.size() == level) {
        res.push_back({});
    }
    res[level].push_back(root->val);
    if (root->left) {
        level_order(root->left, level + 1, res);
    }
    if (root->right) {
        level_order(root->right, level + 1, res);
    }
}