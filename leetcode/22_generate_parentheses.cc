// given n pairs parentheses, write a function to geneare all combinations of well-formed parentheses.

std::vector<std::string> generate_parenthesis(const int n) {
    std::vector<string> res;
    generate_parenthesis_dfs(n, n, "", res);
    return res;
}

void generate_parenthesis_dfs(int left, int right, std::string out, std::vector<std::string> &res) {
    if (left > right) {
        return ;
    }
    if (left == 0 && right == 0) {
        res.push_back(out);
    } else {
        if (left > 0) generate_parenthesis_dfs(left - 1, right, out + '(', res);
        if (right > 0) generate_parenthesis_dfs(left, right - 1, out + ')', res);
    }
}
