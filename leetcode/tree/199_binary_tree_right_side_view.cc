//given a binary tree, image yourself standing on the 
//right side of it, return the values of the nodes you 
//can see ordered from top to bottom;

std::vector<int> right_side_view(TreeNode* root) {
    std::vector<int> res;
    if (！root) {
        return res;
    }
    std::queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        res.push_back(q.back()->val);
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front();
            q.pop();
            if (node->left) {
                q.push(node->left);
            }
            if (node->right) {
                q.push(node->right);
            }
        }
    }
    return res;
}