#include <iostream>
#include <vector>
#include <queue>
#include <cmath>

void HeapSortLessK(std::vector<int> &arr, size_t k)
{
    std::priority_queue<int> pQueue;
    int index = 0;
    for (; index <= std::min(arr.size(), k); ++index)
    {
        pQueue.push(arr[index]);
    }
    int i = 0;
    for (; index < arr.size(); ++index, ++i)
    {
        arr[i] = pQueue.top();
        pQueue.pop();
        pQueue.push(arr[index]);
    }

    while (!pQueue.empty())
    {
        arr[i++] = pQueue.top();
        pQueue.pop();
    }
}

void PrintArr(const std::vector<int> &arr)
{
    for (const auto &num : arr)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> arr = {1,2,0,3,6,4,5,9,8};
    PrintArr(arr);
    HeapSortLessK(arr, arr.size() + 2);
    PrintArr(arr);
}