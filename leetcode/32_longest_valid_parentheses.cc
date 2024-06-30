// given a string containing just the characters , find the length of the longest valid parenthese substring


int longest_valid_parentheses(std::string s) {

    int res = 0; 
    int start = 0;
    std::stack<int> m ;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            m.push(i);
        } else {
            m.pop();
            res = m.empty() ? max(res, i - start + 1) : max(res, i - m.top());
        }
    }

    return res;
}
