// Given an array nums and a value val, remove all instances of 
// that value in-place and return the new length
// do not allocate extra space for another array , you must do this 
// by modifying the input array in-place whith O(1) extra memory

namespace wuhangchen
{
class RemoveElement {
public:
    int remove_element(std::vector<int>& nums, int val) {
        int res = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != val) {
                nums[res++] = nums[i];
            }
        }
    }
};
} // namespace wuhangchen