// write a function that reverse a string, the input string is given as an array of characters char[].
// Do not allocate extra space for another array , you must do this by modifying the input array in-place 
// with o(1) extra memory 

void reverse_string(std::vector<char>& s) {
    int left = 0;
    int right = (int)s.size() - 1;
    while (left < right) {
        char t = s[left];
        s[left++] = s[right];
        s[right--] = t;
    }
}

void reserve_string(std::vector<char>& s) {
    int left = 0;
    int right = (int)s.size() - 1;

    while(left < right) {
        std::swap(s[left++], s[right--]);
    }
}
