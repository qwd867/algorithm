#include <iostream>
#include <vector>

void Merge(std::vector<int> &arr, int left, int right)
{
    std::vector<int> myArr = {};
    auto mid = (right + left) / 2;
    int leftIdx = left, rightIdx = mid + 1;

    while (leftIdx < mid + 1 && rightIdx < right + 1)
    {
        if (arr[leftIdx] <= arr[rightIdx])
        {
            myArr.push_back(arr[leftIdx]);
            ++leftIdx;
        }
        else
        {
            myArr.push_back(arr[rightIdx]);
            ++rightIdx;
        }
    }

    while (leftIdx < mid + 1)
    {
        myArr.push_back(arr[leftIdx]);
        ++leftIdx;
    }

    while (rightIdx < right + 1)
    {
        myArr.push_back(arr[rightIdx]);
        ++rightIdx;
    }

    for (int i = left; i < right + 1; ++i)
    {
        arr[i] = myArr[i - left];
    }
}

void Process(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    auto mid = (right + left) / 2;
    Process(arr, left, mid);
    Process(arr, mid + 1, right);
    Merge(arr, left, right);
}

void MergeSort(std::vector<int> &arr)
{
    Process(arr, 0, arr.size() - 1);
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
    MergeSort(arr);
    PrintArr(arr);
    return 0;
}