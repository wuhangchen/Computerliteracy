// given a set of non overlapping intervals, insert a new 
// interval into the intervals (merge if necessary) 
// you may assume that the interval were initially sorted 
// according to their start time 

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& new_interval) {
    std::vector<std::vector<int>> res;
    int n = intervals.size();
    int cur = 0;

    while (cur < n && intervals[cur][1] < new_interval[0]) {
        res.push_back(intervals[cur++]);
    }

    while (cur < n && intervals[cur][0] <= new_interval[1]) {
        new_interval[0] = std::min(new_interval[0], intervals[cur][0]);
        new_interval[1] = std::max(new_interval[1], intervals[cur][1]);
        ++cur;
    }
    res.push_back(new_interval);
    while (cur < n) {
        res.push_back(interval[cur++]);
    }
    return res;
}
