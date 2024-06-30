// given a binary tree, find its maximum depth 
// the maximum depth is the number of nodes along the longest path from the root 
// node down to the farthest leaf node 

int maximum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    reutrn 1 + max(maximum(root->left), maximum(root->right));
}

int maximum(TreeNode* root) {
    if (!root) {
        return 0;
    }
    int res = 0;
    queue<TreeNode*> q;
    while (!q.empty()) {
        ++res;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* t = q.front();
            q.pop();
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
    return res;
}