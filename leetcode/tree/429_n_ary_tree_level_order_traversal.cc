std::vector<std::vector<int>> level_order(Node* root) {
    if (!root) {
        return {};
    }
    std::vector<std::vector<int> > res;
    std::queue<Node*> q{{root}};
    while (!q.empty()) {
        std::vector<int> out;
        for (int i = q.size(); i > 0; --i) {
            auto t = q.front();
            q.pop();
            out.push_back(t->val);
            if (!t->children.empty()) {
                for (auto a : t->children) {
                    q.push(a);
                }
            }
        }
        res.push_back(out);
    }
    return res;
}

std::vector<std::vector<int> > level_order(Node* root) {
    std::vector<std::vector<int> > res;
    helper(root, 0, res);
    return res;
}

void helper(Node* node, int level, std::vector<std::vector<int>>& res) {
    if (!node) {
        return ;
    }
    if (res.size() <= level) {
        res.resize(res.size() + 1);
    }
    res[level].push_back(node->val);
    for (auto a : node->children) {
        helper(a, level + 1, res);
    }
}