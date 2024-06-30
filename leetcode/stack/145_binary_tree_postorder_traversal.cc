// given a binary tree, return the postorder traversal of its node val

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
    std::vector<int> res;
    if (root == nullptr) {
        return res;
    }
    postorder(root, v);
    return res;
}

void postorder(TreeNode* root, std::vector<int>& res) {
    if (root->left) {
        postorder(root->left, res);
    }
    if (root->right) {
        postorder(root->right, res);
    }
    res.push_back(root->val);
}