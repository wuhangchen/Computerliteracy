// given an unsorted array of integers , find the length of the longest consecutive 
// elements sequence 
// your algorithm should run in O(n) complexity

int longest_consecutive(std::vector<int>& nums) {
    int res = 0;
    std::unordered_set<int> s(nums.begin(), nums.end());

    for (auto val : nums) {
        if (!s.count(val)) {
            continue;
        }
        s.erase(val);
        int pre = val - 1;
        int next = val + 1;
        while (s.count(pre)) {
            s.erase(pre--);
        }
        while (s.count(next)) {
            s.erase(next++);
        }
        res = std::max(res, next - pre - 1);
    }
    return res;
}