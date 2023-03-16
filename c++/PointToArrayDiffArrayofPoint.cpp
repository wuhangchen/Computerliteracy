#include<iostream>
#include<string>
using namespace std;

void test() {
    char *str[] = {"welcome", "to", "fortemedia", "nanjing",};
    char **p = str + 1;
    str[0] = (*p++) + 2;
    str[1] = *(p + 1);
    str[2] = p[1] + 3;
    str[3] = p[0] + (str[3] - str[1]);

    for (std::string iter : str) {
        std::cout << iter << std::endl;
    }
    return ;
}

int main()
{
    test();
    return 0;
}
