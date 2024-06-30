// implement atoi to convert a string to an integer .


int my_stoi(const string& str) {
    if (str.empty()) {
        return 0;
    }
    int sign = 1, base = 0, i = 0, n = str.size();
    while(i < n && str[i] == ' ') {
       ++i; 
    }
    if (str[i] == '+' || str[i] == '-') {
        sign = (str[i++] == '+') ? 1 : -1;
    }

    while (i < n && str[i] >= '0' && str[i] <= '9') {
        if (base > INT_MAX / 10 || (base == INT_MAX / 10 && str[i] - '0' > 7)) {
            return (sign == 1) ? INT_MAX : INT_MIN;
        }
        base = 10 * base + (str[i++] - '0');
    }

    return base * sign;
}
