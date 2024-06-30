// given an unsorted array of integers, find the length of longest incresing subsequence.

int length_of_lis(std::vector<int>& nums) {
    if (nums.empty()) {
        return 0;
    }
    std::vector<int> ends{nums[0]};
    for (auto a : nums) {
        if (a < ends[0]) {
            ends[0] = a;
        } else if (a > ends.back()) {
            ends.push_back(a);
        } else {
            int left = 0;
            int right = ends.size();
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (end[mid] < a) {
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }
            ends[right] = a;
        }
    }
    return ends.size();
}
