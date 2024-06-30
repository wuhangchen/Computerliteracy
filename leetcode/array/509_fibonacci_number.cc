
int fib(int N) {
    if (N <= 1) {
        return N;
    }
    return fib(N - 1) + fib(N - 2);
}

int fib(int N) {
    if (N <= 1) {
        return N;
    }
    std::vector<int> dp(N + 1);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i <= N; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[N];
}