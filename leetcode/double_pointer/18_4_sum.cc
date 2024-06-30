// given an array s of n integers ,are there elements a, b, c, and d in S such that a + b + c + d = target ? find all unique quadruplets in the
// find all unique quadruplets in the array which gives the sum of target 

std::vector<std::vector<int>> four_sum(std::vector<int>& nums, int target) {
    std::set<std::vector<int>> res;
    std::sort(nums.begin(), nums.end());

    for (int i = 0; i < int(nums.size() - 3); ++i) {
        for (int j = i + 1; j < int(nums.size() - 2); ++j) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            int left = j + 1;
            int right = nums.size() -1;
            while (left < right) {
                int sum  = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    std::vector<int> out{nums[i], nums[j], nums[left], nums[right]};
                    res.insert(out);
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
    }
    return std::vector<std::vector<int>>{res.begin(), res.end()};
}
