// given a matrix of m * n elements . return all elements 
// of the matrix in spiral order

std::vector<int> spiral_order(std::vector<int>& matrix) {
    if (matrix.empty() || matrix[0].empty()) {
        return {};
    }
    int m = matrix.size();
    int n = matrix[0].size();
    int idx = 0;
    int i = 0;
    int j = 0;
    std::vector<int> res;
    std::vector<std::vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int k = 0;k < m*n; ++k) {
        res.push_back(matrix[i][j]);
        matrix[i][j] = 0;
        int x = i + dir[idx][0];
        int y = j + dir[idx][1];

        if (x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] == 0) {
            idx = (idx + 1) % 4;
            x = i + dirs[idx][0];
            y = j + dirs[idx][1];
        }
        i = x;
        j = y;
    }
    return res;
}