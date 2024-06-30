//given a binary tree and a sum, find all root-to-leaf paths where each paths 
//where each path's sum equals the given sum

std::vector<std::vector<int> > path_sum(TreeNode* root, int sum) {
    std::vector<std::vector<int> > res;
    std::vector<int> out;
    helper(root, sum, out, res);
    return res;
}

void helper(TreeNode* node, int sum, std::vector<int>& out, std::vector<std::vector<int> >& res) {
    if (!node) {
        return ;
    }
    out.push_back(node->val);
    if (sum == node->val && !node->left && !node->right) {
        res.push_back(out);
    }
    helper(node->left, sum - node->val, out, res);
    helper(node->right, sum - node->val, out, res);
    out.pop_back();
}