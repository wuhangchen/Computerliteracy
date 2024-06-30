// combination sum II 
// Given a collection of candidate numbers (candidates) 
// and a target number (target). find all unique combinations 
// in candidates where the candidate numbers sum to target

std::vector<std::vector<int> > combination_sum2(std::vector<int>& nums, int target) {
    std::vector<std::vector<int> > res;
    std::vector<int> out;
    std::sort(nums.begin(), nums.end());
    helper(nums, target, 0, out, res);
    return res;
}

void helper(std::vector<int>& num, int taget, int start, std::vector<int>& out, std::vector<std::vector<int>>& res) {
    if (target < 0) {
        return ;
    }
    if (target == 0) {
        res.push_back(out);
        return;
    }
    for (int i = start; i < num.size(); ++i) {
        if (i > start && nums[i] == nums[i - 1]) {
            continue;
        }
        out.push_back(nums[i]);
        helper(num, target - num[i], i + 1, out, res);
        out.pop_back();
    }
}