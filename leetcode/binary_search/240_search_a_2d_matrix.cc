// write an efficient algorithm that searches for a value in an m*n matrix, this matrix has the following properties.


bool search_matrix(std::vector<std::vector<int> >& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    } 
    if (target < matrix[0][0] || target > matrix.back().back()) {
        return false;
    }

    int x = matrix.size() - 1;
    int y = 0;

    while (true) {
        if (matrix[x][y] > target) {
            --x;
        } else if (matrix[x][y] < target) {
            ++y;
        } else {
            return true;
        }

        if (x < 0 || y > matrix[0].size()) {
            break;
        }
    }
    return false;
}
