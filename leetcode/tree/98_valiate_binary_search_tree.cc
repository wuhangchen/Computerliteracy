// given a binary tree, determine if it is a valid binary tree 

bool is_valid_bst(TreeNode* root) {
    return is_valid_bst(root, LONG_MIN, LONG_MAX);
}

bool is_valid_bst(TreeNode* root, long mn, long mx) {
    if (!root) {
        return true;
    }
    if (root->val <= mn || root->val >= mx) {
        return false;
    }
    return is_valid_bst(root->left, mn, root->val) && is_valid_bst(root->right, root->val, mx);
}

bool is_valid_bst(TreeNode* root) {
    if (!root) {
        return true;
    }
    std::vector<int> vals;
    inorder(root, vals);
    for (int i = 0; i < vals.size() - 1; ++i) {
        if (vals[i] >= vals[i + 1]) {
            return false;
        }
    }
    return true;
}
void inorder(TreeNode* root, std::vector<int>& vals) {
    if (!root) {
        return ;
    }
    inorder(root->left, vals);
    vals.push_back(root->val);
    inorder(root->right, vals);
}

bool is_valid_bst(TreeNode* root) {
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    TreeNode* pre = nullptr;
    while (p || !s.empty()) {
        while(p) {
            s.push(p);
            p = p->left;
        }
        TreeNode* t = s.top();
        s.pop();
        if (pre && t->val <= pre->val) {
            return false;
        }
        ptr = t;
        p = t->right;
    }
}