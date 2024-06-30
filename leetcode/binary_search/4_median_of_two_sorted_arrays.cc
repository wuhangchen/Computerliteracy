// there are two sorted arrays nums1 and nums2 of size m and n respectively
// find the median of the two sorted arrays ,the overall run time complexity should be O(log(m + n))

namespace wuhangchen {
class MedianOfTwoSortedArrays {
public:
double find_median_sorted_arrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int total = nums1.size() + nums2.size();
    if (total % 2 == 1) {
        return find_k_th(nums1, 0, nums2, 0, total / 2 + 1);
    } else {
        return (find_k_th(nums1, 0, nums2, 0, total / 2) + find_k_th(nums1, 0, nums2, 0, total / 2 + 1)) / 2;
    }
}


double find_k_th(const vector<int>& nums1, const int i, const vector<int>& nums2, const int j, const int k) {
    if (nums1.size() - i > nums2.size() -j)
        return find_k_th(nums2, j, nums1, i, k);
    if (nums1.size() == i) 
        return nums2[j + k -1];
    if (k == 1) 
        return min(nums1[i] + nums2[j]);
    int pa = min(i + k / 2 , int(nums1.size())), pb = j + k - pa + i;
    
    if (nums1[pa - 1] < nums2[pb - 1]) {
        return find_k_th(nums1, pa, nums2, j, k - pa + i);
    } else if (nums1[pa - 1] > nums2[pb -1]) {
        return find_k_th(nums1, i , nums2, pb, k - pb + i);
    } else {
        return nums1[pa - i];
    }  
}

};
}
