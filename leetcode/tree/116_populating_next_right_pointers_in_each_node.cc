// you are given a perfect binary where all leves are on the 
// same level, and every parent has two children , the binary tree has the following
// defination

Node* connect(Node* root) {
    if (!root) {
        return nullptr;
    }
    if (root->left) {
        root->left->next = root->right;
    }
    if (root->right) {
        root->right->next = root->right ? root->next->left : nullptr;
    }
    connect(root->left);
    connect(root->right);
    return root;
}

Node* connect(Node* root) {
    if (!root) {
        return NULL;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            Node* t = q.front();
            q.pop();
            if (i < size - 1) {
                t->next = q.front();
            }
            if (t->left) q.push(t->left);
            if (t->right) q.push(t->right);
        }
    }
    reutrn root; 
}