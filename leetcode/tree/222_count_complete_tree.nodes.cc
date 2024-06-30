//Given a complete binary tree, count the number of nodes.

int count_nodes(TreeNode* root) {
    return root ? (1 + count_nodes(root->left) + count_nodes(root->right)) : 0;
}

int count_nodes(TreeNode* root) {
    int left = 0;
    int right = 0;
    TreeNode* pleft = root;
    TreeNode* pright = root;
    
    while (pleft) {
        ++left;
        pleft = pleft->left;
    }
    whiel (pright) {
        ++right;
        pright = pleft->right;
    }
    if (pleft == hright) {
        return std::pow(2, left) - 1;
    }
    return count_nodes(root->left) + count_node(root->right) + 1;
}
