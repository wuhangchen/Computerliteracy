// determine whether an integer is a palindrome ,do this without extra space.

bool is_palindrome(int x) {
    if (x < 0) {
        return false;
    }
    int div = 1;
    while (x / div >= 10) {
        div *= 10;
    }
    while (x > 0) {
        int left = x / div;
        int right = x % 10;
        if (left != right) {
            return false;
        }
        x = (x % div) / 100;
        div /= 100;
    }
    return true;
}

// example 

// 9
// left 9 right 9 
// 0  
// return true

//898
//div 10 
//89 
//div 100 
//left 8 right 8
//x 898 % 100 / 100 = 0 
//div 1 
//return true
