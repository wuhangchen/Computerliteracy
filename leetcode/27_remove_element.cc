// remove element 
// given an array and n value, remove all instances of that value in place and return the new length
// do not allocate extra space for another array,you must do this in place with constant memory.
// the order of elements can be changes, it does not matter what you leave beyond the new length;

int remove_element(std::vector<int>& nums, int val) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if(nums[i] != val) {
            nums[res++] = nums[i];
        }
    }
    return res;
}
