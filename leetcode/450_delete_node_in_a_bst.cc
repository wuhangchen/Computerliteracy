// given a root node referenc of a bst and a key, delete the node 
// with the given key in the bst, return the root node
// reference of the bst

TreeNode* delete_node(TreeNode* root, int key) {
    if (!root) {
        return nullptr;
    }

    if (root->val > key) {
        root->left = delete_node(root->left, key);
    } else if (root->val < key) {
        root->right = delete_node(root->right, key);
    } else {
        if (!root->left || !root->right) {
            root = (root->left) ? root->left : root->right;
        } else {
            TreeNode* cur = root->right;
            while (cur->left) {
                cur = cur->left;
            }
            root->val = cur->val;
            root->right = delete_node(root->right, cur->val);
        }
    }
    return root;
}