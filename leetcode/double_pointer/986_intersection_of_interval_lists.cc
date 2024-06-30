// given two lists consisting of some closed intervals, each interval list is pairwise disjoint and has 
// been sorted 
// returns the intersection of these two interval lists

std::vector<std::vector<int>> interval_intersection(std::vector<std::vector<int>>& A, 
        std::vector<std::vector<int>>& B) {
    int sz1 = A.size();
    int sz2 = B.size();
    int i = 0;
    int j = 0;
    std::vector<std::vector<int>> res;

    while (i < sz1 && j < sz2) {
        if (A[i][0] > B[j][1]) {
            ++j;
        } else if (A[i][1] < B[j][0]) {
            ++i;
        } else {
            res.push_back({std::max(A[i][0], B[j][0]), std::min(A[i][1], B[j][1])});
            if (A[i][1] < B[j][1]) {
                ++i;
            } else if (A[i][1] == B[j][1]){
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
    }
    return res;
}
