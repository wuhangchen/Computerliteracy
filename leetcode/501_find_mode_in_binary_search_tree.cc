// given a binary search tree with duplicate, find all the 
// modes(the most frequently occurred element) in the given 
// bst

std::vector<int> find_mode(TreeNode* root) {
    std::vector<int> res;
    int mx = 0;
    std::unordered_map<int, int> m;
    inorder(root, m, mx);
    for (auto a : m) {
        if (a.second == mx) {
            res.push_back(a.first);
        }
    }
    return res;
}

void inorder(TreeNode* node, std::unordered_map<int, int>& m, int& mx) {
    if (!node) {
        return ;
    }
    inorder(node->left, m, mx);
    mx = std::max(mx, ++m[node->val]);
    inorder(node->right, m, mx);
}


std::vector<int> find_mode(TreeNode* root) {
    if (!root) {
        return {};
    }
    std::vector<int> res;
    TreeNode* p = root;
    std::stack<TreeNode*> s;
    std::unordered_map<int, int> m;
    int mx = 0;
    while (!s.empty() || p) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();s.pop();
        mx = std::max(mx, ++m[p->val]);
        p = p->right;
    }

    for (auto a : m) {
        if (s.second == mx) {
            res.push_back(a.first);
        }
    }
    return res;
}