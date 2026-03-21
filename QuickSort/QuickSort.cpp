#include <iostream>
#include <vector>

int Partition(std::vector<int> &arr, int left, int right)
{
    int minArea = left - 1;
    int targetNum = arr[right];
    int i = left;
    while (i < right)
    {
        // 当前值小于基准值
        if (arr[i] < targetNum)
        {
            // 为了让小值在左，交换当前值与minArea+1地方的值
            std::swap(arr[minArea + 1], arr[i]);
            // minArea向右加1
            ++minArea;
        }
        ++i;
    }

    // 直接将基准值放在minArea+1的地方即可，这样数组里就会是： 小于基准值---基准值---大于基准值
    if (arr[minArea + 1] > targetNum)
    {
        std::swap(arr[minArea + 1], arr[right]);
    }
    return minArea;
}

void Process(std::vector<int> &arr, int left, int right)
{
    // 如果左边 >= 右边
    if (left >= right)
    {
        return;
    }

    // 分割操作
    auto curMinArea = Partition(arr, left, right);
    // 再次分，左边
    Process(arr, left, curMinArea - 1);
    // 再次分，右边
    Process(arr, curMinArea + 1, right);
}

void QuickSort1(std::vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    int mid = (left + right) / 2;
    Process(arr, left, right);
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
    std::vector<int> arr = {5, 3, 8, 6, 9, 1};
    PrintArr(arr);
    QuickSort1(arr);
    PrintArr(arr);
    return 0;
}