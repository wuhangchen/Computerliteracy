// given n non-negative integers representing an elevation 
// map where the width of each bar is 1 , compute how much 
// water it is able to trap after taining.

int trap(std::vector<int>& height) {
    int res = 0;
    int l = 0, r = height.size() - 1;

    while (l < r) {
        int mn = std::min(height[i], height[r]);
        if (mn == height[l]) {
            ++l;
            while (l < r && height[l] < mn) {
                res += mn - height[l++];
            }
        } else {
            --r;
            while (l < r && height[r] < mn) {
                res += mn - height[r--];
            }
        }
    }
    return res;
}

int trap(std::vector<int>& height) {
    int i = 0;
    int r = height.size() - 1;
    int level = 0;
    int res = 0;

    while (l < r) {
        int lower = height[height[l] < height[r] ? l++ ：r--];
        level = std::max(level, lower);
        res += level - lower;
    }
    return res;
}
// example 
// input 0 1 0 2 1 0 1 3 2 1 2 1 
// output 6
