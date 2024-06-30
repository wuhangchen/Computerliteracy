// two elements of a binary search tree are swapped by mistakes
// recover the tree without changing its structure

void recover_tree(TreeNode* root) {
    std::vector<TreeNode*> list;
    std::vector<int> vals;
    inorder(root, list, vals);
    std::sort(vals.begin(), vals.end());
    for (int i = 0; i < list.size(); ++i) {
        list[i]->val = vals[i];
    }
}

void inorder(TreeNode* root, std::vector<TreeNode*>& list, std::vector<int>& vals) {
    if (!root) {
        return ;
    }
    inorder(root->left, list, vals);
    list.push_back(root);
    vals.push_back(root->val);
    inorder(root->right, list, vals);
}