// given a non-empty binary search tree and a target value, find the value in the bst that is closest to the target

int closest_value(TreeNode* root, double target) {
    double d = std::numeric_limits<double>::max();
    int res = 0;
    std::stack<TreeNode*> s;
    TreeNode* p = root;

    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        if (d >= std::abs(target - p->val)) {
            d = std::abs(target - p->val);
            res = p->val;
        }
        p = p->right;
    }
    return res;
}

int closed_value(TreeNode* root, double target) {
    int res = root->val;
    while (root) {
        if (std::abs(res - target) >= std::abs(root->val - target)) {
            res = root->val;
        }
        root = target < root->val ? root->left : root->right;
    }
    return res;
}

int closest_value(TreeNode* root, double target) {
    int a = root->val;
    TreeNode* t = target < a ? root->left : root->right;
    if (!t) {
        return a;
    }
    int b = closest_value(t, target);
    return std::abs(a - target) < std::abs(b - target) ? a : b;
}

int closest_value(TreeNode* root, double target) {
    int res = root->val;
    if (target < root->val && toot->left) {
        int l = closest_value(root->left, target);
        if (std::abs(res - target) >= std::abs(l - target)) {
            res = l;
        }
    } else if (target > root->val && root->right) {
        int r = closed_value(root->right, target);
        if (std::abs(res = target) >= std::abs(r - target)) {
            res = r;
        }
    }
    return res;
}

int closest_value(TreeNode* root, double target) {
    double diff = std::numeric_limits<double>::max();
    int res = 0;
    helper(root, target, diff, res);
    return res;
}

void helper(TreeNode* root, double target, double &diff, int &res) {
    if (!root) {
        return ;
    }
    if (diff >= std::abs(root->val - target)) {
        diff = std::abs(root->val - target);
        res = root->val;
    }
    helper(root->left, target, diff, res);
    helper(root->right, target, diff, res);
}
