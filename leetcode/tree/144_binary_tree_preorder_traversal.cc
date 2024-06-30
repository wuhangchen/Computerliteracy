//given a binary tree, return the preorder traversal of its nodes values

/*
1.把根节点push到栈中，
2.循环检擦是否为空，若不为空，则取出栈顶元素，保存其值，然后看其右子节点是否存在，若存在push到栈中，再看其左子节点，若存在，则push到栈中
*/
std::vector<int> preorder_traversal(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    std::stack<TreeNode*> s{{root}};
    while (!s.empty()) {
        TreeNode* t = s.top();
        s.pop();
        res.push_back(t->val);
        if (t->right) {
            s.push(t->right);
        }
        if (t->left) {
            s.push(t->left);
        }
    }
    return res;
}
/*
使用辅助节点p,辅助节点p点初始化为根节点，while循环的条件是栈不为空
或者辅助节点不为空，在循环中首先判断如果辅助节点p存在，那就将p加入栈中，
然后将p的节点值加入结果res中，此时p指向左子节点，否则如果p不存在的话，表明
没有左子节点，取出栈顶节点，将p指向栈顶节点的右子节点。
*/
std::vector<int> preorder_traversal(TreeNode* root) {
    std::vector<int> res;
    std::stack<TreeNode*> st;
    TreeNode* p = root;
    while (!st.empty() || p) {
        if (p) {
            st.push(p);
            res.push_back(p->val);
            p = p->left;
        } else {
            p = st.top();
            st.pop();
            p = p->right;
        }
    }
    return res;
}