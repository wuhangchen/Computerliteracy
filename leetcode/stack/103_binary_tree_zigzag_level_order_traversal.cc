
std::vector<std::vector<int>> zigzag_level_order(TreeNode* root) {
    std::vector<std::vector<int>> res;
    if (!root) {
        return res;
    }

    std::stack<TreeNode*> s1;
    std::stack<TreeNode*> s2;

    s1.push(root);
    std::vector<int> out;
    while (!s1.empty() || s2.empty()) {
        while (!s1.empty()) {
            TreeNode* cur = s1.top();
            s1.pop();
            out.push_back(cur->val);
            if (cur->left) {
                s2.push(cur->left);
            }
            if (cur->right) {
                s2.push(cur->right);
            }
        }
        if (!out.empty()) {
            res.push_back(out);
        }
        out.clear();
        
        while (!s2.empty()) {
            TreeNode* cur = s2.top();
            s2.top();
            out.push_back(cur->val);
            if (cur->right) {
                s1.push_back(cur->right);
            } 
            if (cur->left) {
                s2.push_back(cur->left);
            }
        }
        if (!out.empty()) {
            res.push_back(out);
        }
        out.clear();
    }
}
