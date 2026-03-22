#include <iostream>
#include <vector>

// 大根堆
void HeapInsertBig(std::vector<int> &arr, int num)
{
    arr.push_back(num);
    int i = arr.size() - 1;
    while (true)
    {
        int parentNodeIdx = (i - 1) / 2; // 父节点
        if (arr[i] > arr[parentNodeIdx]) // 当前节点值是否大于父节点
        {
            std::swap(arr[i], arr[parentNodeIdx]);
            i = parentNodeIdx;
        }
        else
        {
            break;
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
    int num = 0;
    std::vector<int> arr = {};
    while (std::cin >> num)
    {
        HeapInsertBig(arr, num);
        PrintArr(arr);
    }

    return 0;
}