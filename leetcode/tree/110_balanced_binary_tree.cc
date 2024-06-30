// given a binary tree, determin if it is height-balanced 

bool is_balanced(TreeNode* root) {
    if (!root) {
        return true;
    }
    if (std::abs(get_depth(root->left) - get_depth(root->right)) > 1) {
        return false;
    }
    return is_balanced(root->left) && 
        is_balanced(root->right);
}
int get_depth(TreeNode* root) {
    if (!root) {
        return 0;
    }
    return 1 + std::max(get_depth(root->left), get_depth(root->right));
}