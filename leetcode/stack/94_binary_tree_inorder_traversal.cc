// given a binary tree, return the inorder traversal of its nodes value

std::vector<int> inorder_traversal(TreeNode* root) {
    std::vector<int> res;
    inorder(root, res);
    return res;
}

void inorder(TreeNode* root, std::vector<int>& res) {
    if (!root) {
        return ;
    }
    if (root->left) {
        inorder(root->left, res);
    }
    res.push_back(root->val);
    if (root->right) {
        inorder(root->right, res);
    }
}


std::vector<int> inorder_traversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> s;
    TreeNode *p = root;
    while (p || !s.empty()) {
        while(p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        res.push_back(p->val);
        p = p->right;
    }
    return res;
}

std::vector<int> inorder_traversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while (!s.empty() || p) {
        if (p) {
            s.push(p);
            p = p->left;
        } else {
            TreeNode *t = s.top();
            s.pop();
            res.push_back(t->val);
            p = t->right;
        }
    }
    return res;
}
