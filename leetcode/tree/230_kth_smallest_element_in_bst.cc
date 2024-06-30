//Given a binary search tree, write a function kthsmallest 
//to find the kth smallest element in it

int kthsmallest(TreeNode* root, int k) {
    int cnt = 0;
    std::stack<TreeNode*> s;
    TreeNode* p = root;
    while (p || !s.empty()) {
        while (p) {
            s.push(p);
            p = p->left;
        }
        p = s.top();
        s.pop();
        ++cnt;
        if (cnt == k) {
            return p->val;
        }
        p = p->right;
    }
    return 0;
}

int kthsmallest(TreeNode* root, int& k) {
    return kthsmallestdfs(root, k);
}

int kthsmallestdfs(TreeNode* root, int& k) {
    if (!root) {
        return -1;
    }
    int val = kthsmallestdfs(root->left, k);
    if (k == 0) {
        return val;
    }
    if (--k == 0) {
        return root->val;
    }
    return kthsmallestdfs(root->right, k);
}

int kth_smallest(TreeNode* root, int k) {
    int cnt = count(root->left);
    if (k < cnt) {
        return kth_samllest(root->left, k);
    } else if (k > cnt + 1) {
        return kth_samllest(root->right, k - cnt - 1);
    }

    return root->val;
}

int count(TreeNode* node) {
    if (!node) {
        return 0;
    }
    return 1 + count(node->left) + count(node->right);
}

class Solution {
public:
    struct MyTreeNode {
        int val;
        int count;
        MyTreeNode* left;
        MyTreeNode* right;
        MyTreeNode(int x) : val(x), count(1), left(nullptr), right(nullptr) {}
    };

    MyTreeNode* build(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        MyTreeNode* node = new MyTreeNode(root->val);
        node->left = build(root->left);
        node->right = build(root->right);

        if (node->left) {
            node->count += node->left->count;
        }
        if (node->right) {
            node->count += node->right->count;
        }
        return node;
    }

    int kth_smallest(TreeNode* root, int k) {
        MyTreeNode* node = build(root);
        return helper(node, k);
    }

    int helper(MyTreeNode* node, int k) {
        if (node->left) {
            int cnt = node->left->count;
            if (k <= cnt) {
                return helper(node->left, k);
            } else if (k > cnt + 1) {
                return helper(node->right, k - 1 -cnt);
            }

            return node->val;
        } else {
            if (k == 1) {
                return node->val;
                return helper(node->right, k - 1);
            }
        }
    }
};

class Solution {
    std::vector<int> v;
public:
    void build(TreeNode* root) {
        if (!root) {
            return ;
        }
        build(root->left);
        v.push_back(root->val);
        build(root->right);
    }

    int kth_smallest(TreeNode* root, int k) {
        build(root);
        return v[k - 1];
    }
};
