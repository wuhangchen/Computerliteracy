// given a binary tree, containing digits from 0-9 only,
// each root-to-leaf path could represent a number.

int sum_numbers(TreeNode* root) {
    return sum_numbers(root, 0);
}

int sum_numbers(TreeNode* root, int sum) {
    if (!root) {
        return 0;
    }
    sum = sum * 10 + root->val;
    if (!root->left && !root->right) {
        return sum;
    }
    return sum_numbers(root->left, sum) + sum_numbers(root->right, sum);
}


int sum_numbers(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int res = 0;
    std::stack<TreeNode*> st{{root}};
    while (!st.empty()) {
        TreeNode* t = st.top();
        st.pop();
        if (!t->left && !t->right) {
            res += t->val;
        }
        if (t->left) {
            t->right->val += t->val * 10;
            st.push(t->right);
        }
        if (t->left) {
            t->left->val += t->val *10;
            st.push(t->left);
        }
    }
    return res;
}