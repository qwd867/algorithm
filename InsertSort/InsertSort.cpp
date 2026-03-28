#include <iostream>
#include <vector>

void InsertSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size() - 1; ++i)
    {
        for (int j = i + 1; j > 0; --j) // 遍历前面的有序序列，将当前数字交换直到找到合适的位置
        {
            if (arr[j] < arr[j - 1])
            {
                std::swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
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
    InsertSort(arr);
    PrintArr(arr);
    return 0;
}