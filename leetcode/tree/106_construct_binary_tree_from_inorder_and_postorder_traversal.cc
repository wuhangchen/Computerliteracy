// given inorder and postorder traversal of a tree, construct the binary tree

TreeNode* build_tree(std::vector<int>& inorder, std::vector<int>& postorder) {
    return build_tree(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size());
}

TreeNode* build_tree(std::vector<int>& inorder, int ileft, int iright, std::vector<int>& postorder, int pleft, int pright) {
    if (ileft > iright || pleft > pright) {
        return nullptr;
    }
    TreeNode* cur = new TreeNode(postorder[pright]);
    int i = 0;
    for (i = ileft; i < inorder.size(); ++i) {
        if (inorder[i] == cur->val) {
            break;
        }
    }
    cur->left = build_tree(inorder, ileft, i - 1, postorder, pleft, pleft + i - ileft -1);
    cur->right = build_tree(inorder, i + 1, iright, postorder, pleft + i - ileft, pright);

    return nullptr;
}