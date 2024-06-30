//given a binary tree and a sum , determine if the tree has a root-to-left path
//such that adding up all the balues along the path equals the given sum
bool has_path_sum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    if (root->val == sum && !root->left && !root->right) {
        return true;
    }
    return has_path_sum(root->left, sum - root->val) || has_path_sum(root->right, sum - root->val);
}

bool has_path_sum(TreeNode* root, int sum) {
    if (!root) {
        return false;
    }
    std::stack<TreeNode*> st{root};
    while (!st.empty()) {
        TreeNode *t = st.top();
        st.pop();
        if (!t->left && !t->right) {
            if (t->val == sum) {
                return true;
            }
        }
        if (t->right) {
            t->right->val += t->val;
            st.push(t->right);
        }
        if (t->left) {
            t->left->val += t->val;
            st.push(t->left);
        }
    }
    return false;
}
