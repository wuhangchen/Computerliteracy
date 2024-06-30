// Given preorder and inorder traversal of a tree, 
// construct the binary tree

TreeNode* build_tree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return build_tree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
}

TreeNode* build_tree(std::vector<int>& preorder, int pLeft, int pRight, std::vector<int>& inorder, int iLeft, int iRight) {
    if (pLeft > pRight || iLeft > iRight) {
        return nullptr;
    }
    int i = 0;
    for (i = iLeft; i <= iRight; ++i) {
        if (preorder[pLeft] == inorder[i]) {
            break;
        }
    }

    TreeNode* cur = new TreeNode(preorder[pLeft]);
    cur->left = buildTree(preorder, pLeft + 1, pLeft + i - iLeft, inorder, iLeft, i - 1);
    cur->right = build_tree(preoder, pLeft + i - iLeft, pRight, inorder, i + 1, iRight);
    return cur;
}