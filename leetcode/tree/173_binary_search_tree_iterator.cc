//implement an iterator over a binary search tree, your 
//iterator will be initialized with the root node of a bst

class BstIterator {
public: 
    BstIterator(TreeNode* root) {
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    bool has_next() {
        return !s.empty();
    }

    int next() {
        TreeNode* n = s.top();
        s.pop(); 
        int res = n->val;
        if (n->right) {
            n = n->right;
            while (n) {
                s.push(n);
                n = n->left;
            }
        }
        return res;
    }
private:
    std::stack<TreeNode*> s;
}