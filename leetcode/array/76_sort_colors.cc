// sort colors 

void sort_colors(std::vector<int>& nums) {
    std::vector<int> colors(3);
    for (auto num : nums) {
        ++colors[num];
    }
    for (int i = 0, cur = 0; i < 3; ++i) {
        for (int j = 0; j < colors[i]; ++j) {
            nums[cur++] = i;
        }
    }
}