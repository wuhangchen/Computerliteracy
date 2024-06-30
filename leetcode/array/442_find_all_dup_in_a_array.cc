// given an array of integers. some elements appear twice and 
// others appear once , find all the elements that appear twice in this 
// array 

std::vector<int> find_dup(std::vector<int>& nums) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        int idx = std::abs(nums[i]) - 1;
        if (nums[idx] < 0) {
            res.push_back(idx + 1);
        }
        nums[idx] = - nums[idx];
    }
    return res;
}

std::vector<int> find_dup(std::vector<int>& nums) {
    std::vector<int> res;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != nums[nums[i] - 1]) {
            std::swap(nums[i], nums[nums[i] - 1]);
            --i;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] != i + 1) {
            res.push_back(nums[i]);
        }
    }
    return res;
}