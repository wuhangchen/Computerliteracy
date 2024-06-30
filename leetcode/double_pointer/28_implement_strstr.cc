// implement strstr 
// returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack

int strStr(std::string haystack, std::string needle) {
    if (needle.empty()) {
        return 0;
    }
    int m = haystack.size();
    int n = needle.size();
    if (m < n) {
        return -1;
    }
    
    for (int i = 0; i < = m - n; ++i) {
        int j = 0;
        for (j = 0; j < n; ++j) {
            if (haystack[i + j] != needle[j]) {
                break;
            }
        }
        if (j == n) {
            return i;
        }
    }
    return -1;

}
