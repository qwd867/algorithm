#include <vector>
#include <iostream>

void BubbleSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        for (int j = 1; j < arr.size() - i; ++j)
        {
            if (arr[j - 1] > arr[j])
            {
                std::swap(arr[j - 1], arr[j]);
            }
        }
    }
}

void PrintArr(std::vector<int> &arr)
{
    for (const auto &num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {8, 4, 65, 7, 8, 3, 6, 6, 87, 3, 7, 23, 6, 3};
    PrintArr(arr);
    BubbleSort(arr);
    PrintArr(arr);
    return 0;
}