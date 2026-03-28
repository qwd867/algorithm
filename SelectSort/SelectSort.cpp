#include <iostream>
#include <vector>

void SelectSort(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); ++i)
    {
        // 用于记录最小值
        int minValIdx = i;
        for (int j = i + 1; j < arr.size(); ++j) // 遍历仍然无序的序列
        {
            if (arr[j] < arr[minValIdx])
            {
                minValIdx = j;
            }
        }
        std::swap(arr[minValIdx], arr[i]); // 将最小值放到前面的有序序列里面
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
    SelectSort(arr);
    PrintArr(arr);
    return 0;
}