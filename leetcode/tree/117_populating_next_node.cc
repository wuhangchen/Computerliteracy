Node* connect(Node* root) {
    if (!root) {
        return nullptr;
    }
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            Node* t = q.front();
            q.pop();
            if (i < len - 1) {
                t->next = q.front();
            }
            if (t->left) {
                q.push(t->left);
            }
            if (t->right) {
                q.push(t->right);
            }
        }
    }
    return root;
}