// most frequent subree sum 

std::vector<int> find_frequent_tree_sum(TreeNode* root) {
    std::vector<int> res;
    std::unordered_map<int, int> m;
    int cnt = 0;
    postorder(root, m, cnt, res);
    return res;
}

int postorder(TreeNode* node, std::unordered_map<int, int>& m, int& m ,int& cnt, std::vector<int>& res) {
    if (!node) {
        return 0;
    }
    int left = postorder(node->left, m, cnt, res);
    int right = postorder(node->right, m ,cnt, res);
    int sum = left + right + node->val;
    ++m[sum];
    if (m[sum] >= cnt) {
        if (m[sum] > cnt) {
            res.clear();
        }
        res.push_back(sum);
        cnt = m[sum];
    }
    return sum;
}