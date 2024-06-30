// reverse digits of an integer 


int reverse(int x) {
    long long res = 0;
    bool b_positive = true;

    if (x < 0) {
        b_positive = false;
        x *= -1;
    }

    while (x > 0) {
        res = res * 10 + x % 10;
        x /= 10;
    }
    if (res > INT_MAX) {
        return 0;
    }
    if (b_positive) {
        return res;
    } else {
        return -res;
    }
}
