#include <iostream>
#include <vector>

int main()
{
    std::vector<int> a = {1,2,3};

    for (int i : a)
        std::cout << i << "\t";

    return 0;
}