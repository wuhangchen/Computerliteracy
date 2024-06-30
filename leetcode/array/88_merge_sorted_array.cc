// Given two sorted integer arrays nums 1 and nums 2 ,merge nums2 into 
// nums1 as one sorted array

void merge(std::vector<int>& nums1, int m , std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums[j]) {
            nums1[k--] = nums1[i--];
        } else {
            nums1[k--] = nums[j--];
        }
    }
    while (j >= 0) {
        nums1[k--] = nums2[j--];
    }
}

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
    int i = m - 1;
    int j = n - 1;
    int k = m + n - 1;

    while (j >= 0) {
        nums1[k--] = (i >= 0 && nums1[i] > nums2[j]) ? nums1[i--] : nums2[j--];
    }
}