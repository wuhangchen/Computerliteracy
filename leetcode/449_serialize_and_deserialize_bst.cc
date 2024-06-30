
std::string serialize(TreeNode* root) {
    std::ostringstream os;
    serialize(root, os);
    return os.str();
}

TreeNode* deserialize(std::string data) {
    std::istringstream is(data);
    return deserialize(is);
}

void serialize(TreeNode* root, std::ostringstream& os) {
    if (!root) {
        os << "# ";
    } else {
        os << root->val << " ";
        serialize(root->left, os);
        serialize(root->right, os);
    }
}

TreeNode* deserialize(istringstream& is) {
    std::string val = "";
    is >> val;
    if (val == "#") {
        return nullptr;
    }
    TreeNode* node = new TreeNode(std::stoi(val));
    node->left = deserialize(is);
    node->right = deserialize(is);
    return node;
}