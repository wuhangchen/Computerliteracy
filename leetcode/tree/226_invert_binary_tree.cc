// invert a binary tree

TreeNode* invert_tree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    auto temp = root->left;
    root->left = invert_tree(root->right);
    root->right = invert_tree(temp);
    return root;
}

TreeNode* invert_tree(TreeNode* root) {
    if (!root) {
        return nullptr;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        TreeNode* temp = node->left;
        node->left = node->right;
        node->right = temp;
        if (node->left) {
            q.push(node->left);
        }
        if (node->right) {
            q.push(node->right);
        }
    }
    return root;
}