#include <iostream>
#include <vector>

// 大根堆
void Heapify(std::vector<int> &arr, int index, int heapSize)
{
    int left = 2 * index + 1;
    while (left < heapSize) // 判断下面还有没有孩子
    {
        int right = left + 1; // 判断有没有右孩子
        int largeChildIdx = 0;
        if (right < heapSize) // 如果有右孩子
        {
            largeChildIdx = arr[left] > arr[right] ? left : right; // 判读左右孩子谁大
        }
        else // 如果没有右孩子
        {
            largeChildIdx = left; // 左孩子最大
        }

        // 判断当前index和最大的那个孩子谁打
        if (arr[largeChildIdx] > arr[index]) // 孩子大
        {
            std::swap(arr[largeChildIdx], arr[index]);
            index = largeChildIdx;
            left = 2 * index + 1; // 新的左孩子
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
    std::vector<int> arr = {1, 4, 6, 8, 3, 8, 4, 7, 2, 7, 4, 3, 2};
    PrintArr(arr);
    for (int i = arr.size() - 1; i >= 0; --i)
    {
        Heapify(arr, i, arr.size());
    }
    PrintArr(arr);
    return 0;
}