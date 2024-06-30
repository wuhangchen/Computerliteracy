//given a binary tree, return all root-to-leaf paths

std::vector<string> binaryTreePaths(TreeNode* root) {
    std::vector<std::string> res;
    if (root) {
        helper(root, "", res);
    }
    return res;
}

void helper(TreeNode* node, std::string out, std::vector<std::string>& res) {
    if (!node->left && !node->right) {
        res.push_back(out + std::to_string(node->val));
    }
    if (node->left) {
        helper(node->left, out + std::to_string(node->val) + "->", res);
    }
    if (node->right) {
        helper(node->right, out + std::to_string(node->val) + "->", res);
    }
}