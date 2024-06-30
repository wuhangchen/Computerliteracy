// given a collection of intervals ,
// merge all overlapping intervals

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    if (intervals.empty()) {
        return {};
    }
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> res{intervals[0]};
    for (int i = 1; i < intervals.size(); ++i) {
        if (res.back()[1] < intervals[i][0]) {
            res.push_back(intervals[i]);
        } else {
            res.back()[1] = std::max(res.back()[1], intervals[i][1]);
        }
    }
    return res;
}