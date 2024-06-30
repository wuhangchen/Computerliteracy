// one way to serialize a binary tree is to use pre-order trraversal,
// when we encounter a non-null node, we record the node of value,
// if it is a null node, we record using a sentinel value such a #

bool is_valid_serialization(std::string preorder) {
    std::istringstream in(preoder);
    std::vector<std::string> v;

    std::string t = "";
    int cnt = 0;
    while (getline(in, t, ',')) {
        v.push_back(t);
    }

    for (int i = 0; i < v.size(); ++i) {
        if (v[i] == "#") {
            if (cnt == 0) {
                return false;
            }
            --cnt;
        } else {
            ++cnt;
        }
    }
    return cnt == 0 && v.back() == "#";
}