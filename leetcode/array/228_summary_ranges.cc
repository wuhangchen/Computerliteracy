// given a sorted integer array without duplicates, return the summary of its ranges

std::vector<std::string> summary_ranges(std::vector<int>& nums) {
    std::vector<std::string> res;
    int i = 0; 
    int n = nums.size();

    while (i < n) {
        int j = 1;
        while (i + j < n && nums[i + j] - nums[i] == j) {
            ++j;
        }
        res.push_back(j <= 1 ? std::to_string(nums[i]) : std::to_string(nums[i] + "->" + std::to_string(nums[i + j -1])));
        i += j;
    }
    return res;
}