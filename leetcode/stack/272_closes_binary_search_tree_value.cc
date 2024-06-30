// given a no empty binary search tree and a target value , find k values int the 
// bst that are closest that are closest to the target 

std::vector<int> closest_kvalue(TreeNode* root, double target, int k) {
    std::vector<int> res;
    inorder(root, target, k, res);
    return res;
}

void inorder(TreeNode* root, double target, int k, std::vector<int>& res) {
    if (!root) {
        return;
    }
    inorder(root->left, target, k, res);
    if (res.size() < k) {
        res.push_back(root->val);
    } else if (std::abs(root->val - target) < std::abs(res[0] - target)) {
        res.erase(res.begin());
        res.push_back(root->val);
    } else {
        return ;
    }
    inorder(root->right, target, k, res);
}

std::vector<int> closest_kvalue(TreeNode* root, double target, int k) {
    std::vector<int> res;
    stack<TreeNode*> s;
    TreeNode* p = root;
    while (p || !s.empty()) {
        if (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        if (res.size() < k) {
            res.push_back(p->val);
        } else if (std::abs(p->val - target) < std::abs(res[0] - target)) {
            res.erase(res.begin());
            res.push_back(p->val);
        } else {
            break;
        }
        p = p->right;
    }
    return res;
}