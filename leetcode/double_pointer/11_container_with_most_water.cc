int max_area(std::vector<int>& height) {
    int res = 0;
    int i = 0;
    int j = height.size() - 1;

    while (i < j) {
        res = std::max(res, std::min(height[i], height[j] * (j - i)));
        height[i] < height[j] ? ++i : --j;
    }
    return res;
}
