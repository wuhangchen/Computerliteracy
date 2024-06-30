//given a binary search tree, find the lowest common
//ancestor of two given nodes in the bst

TreeNode* lowestCommonAncestor(TreeNode* root, 
                            TreeNode* p,
                            TreeNode* q) {
    if (!root) {
        return nullptr;
    }
    if (root->val > max(p->val, q->val)) {
        return lowestCommonAncestor(root->left, p, q);
    } else if (root->val < min(p->val, q->val)) {
        return lowestCommonAncestor(root->right, p, q);
    } else {
        return root;
    }
}

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (true) {
        if (root->val > max(p->val, q->val)) {
            root = root->left;
        } else if (root->val < min(p->val, q->val)) {
            root = root->right;
        } else {
            break;
        }
    }
    return root;
}