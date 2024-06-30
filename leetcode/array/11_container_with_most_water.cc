// given n non-negative integrers ,such that the container contains the most water

// 思路：容器装水量的算法是找出左右2个边缘中较小的那个乘以2个边缘的距离

namespace wuhangchen {
class ContainerWithMostWater {
public:
int max_area(const std::vector<int>& height) {
    int res = 0, i = 0, j = height.size() - 1;
    while(i < j) {
        res = max(res, min(height[i], height[j] * (j - i)));
        height[i] < height[j] ? ++i : --j;
    }
    return res;
}
int max_area_two(const std::vector<int>& height) {
    int res = 0;
    int i = 0, j = height.size() - 1;

    while (i < j) {
        int h = std::min(height[i], height[j]);
        res = std::max(res, h * (j - i));
        while (i < j && h == height[i]) {
            ++i;
        } 
        while (i < j && h == height[j]) {
            --j;
        }
    }
    return res;
}
};
}
