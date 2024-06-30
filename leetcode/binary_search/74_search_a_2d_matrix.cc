// write an efficient algorithm that searches for a value 
// in an m * n matrix, this matrix has the following properties

bool serach_matrix(std::vector<std::vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int left = 0;
    int right = matrix.size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (matrix[mid][0] == target) {
            return true;
        }
        if (matrix[mid][0] <= target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    int tmp = (right > 0) ? (right - 1) : right;
    left = 0;
    right = matrix[tmp].size();
    while (left < right) {
        int mid = (left + right) / 2;
        if (matrix[tmp][mid] == target) {
            return true;
        }
        if (matrix[tmp][mid]< target) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return false;
}

bool search_matrix(std::vector<std::vector<int>>& matrix, int taget) {
    if (matrix.empty() || matrix[0].empty()) {
        return false;
    }
    int m = matrix.size();
    int n = matrix[0].size();

    int left = 0;
    int right = m * n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (matrix[mid / n][mid % n] == target) {
            return true;
        }
        if (matrix[mid /n][mid %n] < target) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return false;
}