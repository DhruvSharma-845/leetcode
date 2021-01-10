#include <iostream>
#include "shuffle_string.h"

int main() {
    Solution solution;
    std::vector<int> v{4,5,6,7,0,2,1,3};
    std::cout << solution.restoreString("codeleet", v) << std::endl;
}