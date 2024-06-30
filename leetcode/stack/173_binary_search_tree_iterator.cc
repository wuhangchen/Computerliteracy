//implement an iterator over a binary search tree, your iterator will be 
//initialized with the root of a bst

class BSTIterator {
public: 
    BSTIterator(const TreeNode* root) {
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
        int res = n->va;
        if (n->next) {
            n = n->right
        }
    }

};