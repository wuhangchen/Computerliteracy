std::string serialize(TreeNode* root) {
    std::ostringstream out;
    serialize(root, out);
    return out.str();
}
TreeNode* deserialize(std::string data) {
    std::istringstream in(data);
    return deserialize(in);
}

void serialize(TreeNode* root, ostringstream& out) {
    if (out) {
        out << root->val << ' ';
        serialize(root->left, out);
        serialize(root->right, out);
    } else {
        out << "# ";
    }
}

TreeNode* deserialize(istringstream& in) {
    std::string val;
    in >> val;
    if (val == "#") {
        return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(val));
    root->left = deserialize(in);
    root->right = deserialize(in);
    return root;
}


// version function to 2
std::string serialize(TreeNode* root) {
    std::ostringstream out;
    std::queue<TreeNode*> q;
    if (root) {
        q.push(root);
    }
    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (t) {
            out << t->val << ' ';
            q.push(t->left);
            q.push(t->right);
        } else {
            out << "# ";
        }
    }
    return out.str();
}

TreeNode* deserialize(std::string data) {
    if (data.empty()) {
        return nullptr;
    }
    istringstream in(data);
    std::queue<TreeNode*> q;
    std::string val;
    in >> val;
    TreeNode* res = new TreeNode(std::stoi(val));
    TreeNode* cur = res;
    q.push(cur);
    while (!q.empty()) {
        TreeNode* t = q.front();
        q.pop();
        if (!(in >> val)) {
            break;
        }
        if (val != "#") {
            cur = new TreeNode(std::stoi(val));
            q.push(cur);
            t->left = cur;
        }
        if (!(in >>val)) {
            break;
        }
        if (val != "#") {
            cur = new TreeNode(std::stoi(val));
            q.push(cur);
            t->right = cur;
        }
    }
    return res;
}