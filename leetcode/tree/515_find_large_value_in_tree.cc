
std::vector<int> largest_values(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            TreeNode* t = q.front();
            q.pop();
            mx = std::max(mx, t->val);
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
        res.push_back(mx);
    }
    return res;
}