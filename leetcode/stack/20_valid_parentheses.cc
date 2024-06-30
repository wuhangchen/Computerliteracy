// given a string containing just the characters ,deterimin if the input string is valid 

bool is_valid(const string& s) {
    std::stack<char> parentheses;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '{') {
            parentheses.push(s[i]);
        } else {
            if (parentheaes.empty()) {
                return false;
            }
            if (s[i] == ')' && parentheses.top() != '(') {
                return false;
            }
            if (s[i] == '}' && parenthese.top() != '{') {
                return false;
            }
            if (s[i] == ']' && parenthese.top() != '[') {
                return false;
            }
            parentheses.pop();
        }
    }
    return parentheses.empty();
}
