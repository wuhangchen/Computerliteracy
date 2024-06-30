//find the sum of all left leaves in a given binary tree

int sum_of_left_leaves(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 0;
    }
    int res = 0;
    helper(root->left, true, res);
    helper(root->right, false, res);
    return res;
}
void helper(TreeNode* node, bool left, int& res) {
    if (!node) {
        return ;
    }
    if (!node->left && !node->right && left) {
        res += node->val;
    }
    helper(node->left, true, res);
    helper(node->right, false, res);
}

int sum_of_left_leaves(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 0;
    }
    int res = 0;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (t->left && !t->left->left && !t->left>right) {
            res += t->left->val;
        }
        if (t->left) {
            q.push(t->left);
        }
        if (t->right) {
            q.push(t->right);
        }
    }
    return res;
}

int sum_of_left_leaves(TreeNode* root) {
    if (!root || (!root->left && !root->right)) {
        return 0;
    }
    int res = 0;
    std::stack<TreeNode*> s;
    s.push(root);
    while(!s.empty()) {
        TreeNode* t = s.top();
        s.pop();
        if (t->left && !t->left->left && !t->left->right) {
            res += t->left->val;
        }
        if (t->left) {
            s.push(t->left);
        }
        if (t->right) {
            s.push(t->right);
        }
    }
    return res;
}