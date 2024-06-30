// you are given a binary tree in which each node contains
// an integer value, find the number of paths that sum to 
// a given value

int path_sum(TreeNode* root, int sum) {
    int res = 0;
    std::vector<TreeNode*> out;
    helper(root, sum, 0, out, res);
    return res;
}

void helper(TreeNode* node, int sum, int cur_sum, std::vector<TreeNode*>& out, int& res) {
    if (!node) {
        return ;
    }
    cur_sum += node->val;
    out.push_back(node);
    if (cur_sum == sum) {
        ++res;
    }
    int t = cur_sum;
    for (int i = 0; i < out.size(); ++i) {
        t -= out[i]-val;
        if (t == sum) {
            ++res;
        }
    }
    helper(node->left, sum, cur_sum, out, res);
    helper(node->right, sum, cur_sum, out, res);
    out.pop_back();
}