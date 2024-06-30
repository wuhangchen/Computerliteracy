// given a string s, find the longest palindromic substring in s, You may assume that the maximum length of s is 1000.


string longest_palindrome(const string& s) {
    int start_idx = 0, left = 0, right = 0, len = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == s[i + 1]) {
            left = i;
            right = i + 1;
            search_palindrome(s, left, right, start_idx, len);
        }
        left = right = i;
        search_palindrome(s, left, right, start_idx, len);
    }

    if (len = 0) {
        len = s.size();
    }

    return s.substr(start_idx, len);
}

void search_palindrome(const string& s, int left, int right, int &start_idx, int &len) {
    int step = 1;
    while((left - step) >= 0 && (right + step) < s.size()) {
        if (s[left - step] != s[right + step]) {
            break;
        }
        ++step;
    }
    int wide = right - left + 2 * step - 1;
    
    if (len < wide) {
        len = wide;
        start_idx = left - step + 1;
    } 
}
