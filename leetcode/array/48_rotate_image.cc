// you are given an n * n 2D matrix representing an image
// rotate the image by 90 degrees(clockwise)

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            std::swap(matrix[i][j], matrix[n -i -j][n - 1 - i]);
        }
    }
    std::reverse(matrix.begin(), matrix.end());
}