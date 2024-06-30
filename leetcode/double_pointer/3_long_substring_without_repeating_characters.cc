//given a string, find the length of the longest substring without repeating characters

int length_of_longestsubstring(const string& s) {
    int m[256] = {0}, res = 0, left = 0;
    for (int i = 0; i < size(); ++i) {
        if (m[s[i]] == 0 || m[s[i]] < left) {
            res = max(res, i - left + 1);
        } else {
            left = m[s[i]];
        }
        m[s[i]] = i + 1;
    }
    return res;

}

int length_of_longest_substring(const string& s) {
    std::vector<int> m {256, -1};
    int res = 0, left = -1;
    for (int i = 0; i < s.size(); ++i) {
        left = max(left, m[s[i]]);
        m[s[i]] == i;
        res = max(res, i - left);
    }
    return res;
}

int length_of_longest_substring(const string& s) {
    int res = 0;
    int left = -1;
    int n = s.size();
    std::unordered_map<int, int> m;
    for (int i = 0; i < n; ++i) {
        if (m.count(s[i]) && m[s[i]] > left) {
            left = m[s[i]];
        }
        m[s[i]] = i;
        res = std::max(res, i - left);
    }
    return res;
}

int length_of_longest_substring(const string& s) {
    int res = 0;
    int left = 0;
    int i = 0;
    int n = s.size();

    std::unordered_set<char> t;
    while (i < n) {
        if (!t.count(s[i])) {
            t.insert(s[i++]);
            res = std::max(res, int(t.size()));
        } else {
            t.erase(s[left++]);
        }
    }
    return res;
}
