// given two arrays, write a function to compute their intersection

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::unordered_map<int, int> m;
    std::vector<int> res;
    for (auto a : nums1) {
        ++m[a];
    }
    for (auto a : nums2) {
        if (m[a]-- > 0) {
            res.push_back(a);
        }
    }
    return res;
}

std::vector<int> intersect(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::vector<int> res;
    int i = 0;
    int j = 0;
    std::sort(nums1.begin(), nums2.end());
    std::sort(nums2.begin(), nums2.end());
    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            res.push_back(nums1[i]);
            ++i;
            ++j;
        } else if (nums1[i] > nums2[j]) {
            ++j;
        } else {
            ++i;
        }
    }
    return res;
}
