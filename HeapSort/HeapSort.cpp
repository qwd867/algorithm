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

void HeapSort(std::vector<int> &arr)
{
    int heapSize = 0;
    std::vector<int> heapArr = {};
    for (size_t i = 0; i < arr.size(); ++i)
    {
        HeapInsertBig(heapArr, arr[i]);
    }
    heapSize = heapArr.size();
    std::swap(heapArr[0], heapArr[heapSize - 1]);

    while (heapSize > 0)
    {
        --heapSize;
        Heapify(heapArr, 0, heapSize);
        std::swap(heapArr[0], heapArr[heapSize - 1]);
    }
    arr = heapArr;
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
    std::vector<int> arr = {1, 0, 9, 4, 7, 2, 3, 5, 7, 6};
    PrintArr(arr);
    HeapSort(arr);
    PrintArr(arr);
}