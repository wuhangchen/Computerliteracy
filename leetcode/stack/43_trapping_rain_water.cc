// given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to 
// trap after raining 


int trap(std::vector<int>& height) {
    int res = 0;
    int mx = 0;
    int n = height.size();

    std::vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        dp[i] = mx;
        mx = std::max(mx, height[i]);
    }

    mx = 0;
    for(int i = n - 1; i >= 0; --i) {
        dp[i] = std::min(dp[i], mx);
        mx = std::max(mx, height[i]);
        if (dp[i] > height[i]) {
            res += dp[i] - height[i];
        }
    }
    return res;
}

int trap(std::vector<int>& height) {
    int res = 0, l = 0, r = height.size() - 1;
    while(l < r) {
        int mn = std::min(height[l], height[r]);
        if (mn == height[l]) {
            ++l;
            while (l < r && height[l] < mn) {
                res += mn - height[l++];
            }
        } else {
            --r;
            while (l < r && height[r] < mn) {
                res += mn -hegith[r--];
            }
        }
    }
    return res; 
}
