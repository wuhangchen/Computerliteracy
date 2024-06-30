// your ara given an array of positive integers nums.
// count and print the number of (contiguous) subarrays where the product of all elements in the subarray 
// is less than k.

int num_subarray_product_less_than_k(std::vector<int>& nums, int k) {
    if (k <= 1) {
        return 0;
    }
    int res = 0;
    int prod = 1;
    int left = 0;
    for (int i = 0; i < nums.size(); ++i) {
        prod *= nums[i];
        while (left <= i && prod >= k) {
            prod /= nums[left++];
        }
        res += i - left + i;
    }
    return res;
}
