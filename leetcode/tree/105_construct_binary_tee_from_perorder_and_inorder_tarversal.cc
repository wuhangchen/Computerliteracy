// given preorder and inorder traversal of a tree, construct the binary tree

TreeNode* build_tree(std::vector<int>& preorder, std::vector<int>& inorder) {
    return build_tree(preorder, 0, preorder.size() - 1, inorder, 0, preorder.size() - 1);
}

TreeNode* build_tree(std::vector<int>& preorder, int pleft, int pright, 
                    std::vector<int>& inorder, int ileft, int iright) {
    if (pleft > pright || ileft > iright) {
        return nullptr;
    }
    int i = 0;
    for (i = ileft, i <= iright; ++i) {
        if (preorder[pleft] == inorder[i]) {
            break;
        }
    }

    TreeNode* cur = new TreeNode(preorder[pleft]);
    cur->left = build_tree(preorder, pleft + 1, pleft + i - ileft, inorder, ileft, i - 1);
    cur->right = build_tree(preorder, pleft + i -ileft + 1, pright, inorder, i + 1, iright);
};


func build_tree(preorder []int , inorder []int) *TreeNode {
    var root *TreeNode

    if len(preorder) == 0 {
        return root;
    }

    root = new (TreeNode)
    root.val = preorder[0];

    var i int
    for i = 0; i < len(inorder); ++i {
        if inorder[i] == root.val {
            break
        }
    }

    root.left = build_tree(preorder[1:1 + i], inorder[:i])
    root.right = build_tree(preorder[1 + i :], inorder[i + 1:])
}