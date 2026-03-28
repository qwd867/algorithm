#include "SortHelper.h"
#include <iostream>

void SortHelper::PrintArr(const std::vector<int> &arr)
{
    for (const auto &num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}