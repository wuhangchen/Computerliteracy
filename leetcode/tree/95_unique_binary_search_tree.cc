// given an integer n , generate all structrally unique bst that 
// store value 1...n 

std::vector<TreeNode*> generate_trees(int n) {
    if (n == 0) {
        return {};
    }
    return *generate_trees_dfs(1, n);
} 
std::vector<TreeNode*>* generate_trees_dfs(int start, int end) {
    std::vector<TreeNode*> *sub_tree = new std::vector<TreeNode*>();
    if (start > end) {
        sub_tree->push_back(nullptr);
    } else {
        for (int i = start, i <= end; ++i) {
            std::vector<TreeNode*> *left_subtree = generate_trees_dfs(start, i - 1);
            std::vector<TreeNode*> *right_subtree = generate_trees_dfs(i + 1, end);

            for (int j = 0; j < left_subtree->size(); ++j) {
                for (int k = 0; k < right_subtree->size(); ++k) {
                    TreeNode* node = new TreeNode(i);
                    node->left = (*left_subtree)[j]
                    node->right = (*right_subtree)[k];
                    sub_tree->push_back(node);
                }
            }
        }
    }
    return sub_tree;
}