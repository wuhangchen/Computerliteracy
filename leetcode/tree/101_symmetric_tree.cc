// given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center)

bool is_symmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    return is_symmetric(root->left, root->right);
}
bool is_symmetric(TreeNode* left, TreeNode* right) {
    if (!left && !right) {
        return true;
    }
    if (left && !right || !left && right || left->val != right->val) {
        return false;
    }
    return is_symmetric(left->left, right->right) && is_symmetric(left->right, right->left);
}


bool is_symmetric(TreeNode* root) {
    if (!root) {
        return true;
    }
    std::queue<TreeNode*> q1,q2;
    q1.push(root->left);
    q2.push(root->right);

    while (!q1.empty() && !q2.empty()) {
        TreeNode* node1 = q1.front();
        TreeNode* node2 = q2.front();
        q1.pop();
        q2.pop();
        if ((node1 && !node2) || (!node1 && node2)) {
            return false;
        }
        if (node1) {
            if (node1->val != node2->val) {
                return false;
            }
            q1.push(node1->left);
            q1.push(node1->right);
            q2.push(node2->right);
            q2.push(node2->left);
        }
    }
    return true;
}