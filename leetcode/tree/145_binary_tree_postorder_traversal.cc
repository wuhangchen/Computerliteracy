//given a binary tree, return the postorder traversal of its nodes values

std::vector<int> postorder_traversal(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::stack<TreeNode*> s{{root}};
    TreeNode* head = root;
    while (!s.empty()) {
        TreeNode* t = s.top();
        if (!t->left && !t->right) || t->left == head || t->right == head) {
            res.push_back(t->val);
            s.pop();
            head = t;
        } else {
            if (t->right) {
                s.push(t->right);
            }
            if (t->left) {
                s.push(t->left);
            }
        }
    }
    return res;
}

std::vector<int> postorder_traversal(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    while (!s.empty()) {
        TreeNode* t = s.top();
        s.pop();
        res.insert(res.begin(), s.pop());
        if (t->left) {
            s.push(t->left);
        }
        if (t->right) {
            s.push(t->right);
        }
    }
    return res;
}

std::vector<int> postorder_traversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            res.insert(res.begin(), p->val);
            p = p->right;
        } else {
            TreeNode* t = s.top();
            s.pop();
            p = t->left;
        }
    }
    return res;
}