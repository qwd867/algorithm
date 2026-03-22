#include <iostream>
#include <vector>

#pragma region QuickSort1
int Partition(std::vector<int> &arr, int left, int right)
{
    int smallerArea = left - 1;
    int targetNum = arr[right];
    int i = left;
    while (i < right)
    {
        // 当前值小于基准值
        if (arr[i] < targetNum)
        {
            // 为了让小值在左，交换当前值与smallerArea+1地方的值
            std::swap(arr[smallerArea + 1], arr[i]);
            // smallerArea向右加1
            ++smallerArea;
        }
        ++i;
    }

    // 直接将基准值放在smallerArea+1的地方即可，这样数组里就会是： 小于基准值---基准值---大于基准值
    std::swap(arr[smallerArea + 1], arr[right]);
    return smallerArea;
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
    Process(arr, left, curMinArea);
    // 再次分，右边
    Process(arr, curMinArea + 1, right);
}

void QuickSort1(std::vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    Process(arr, left, right);
}
#pragma endregion

#pragma region QuickSort2
std::vector<int> Partition2(std::vector<int> &arr, int left, int right)
{
    int smallerArea = left - 1;
    int biggerArea = right;
    int targetNum = arr[right];
    int i = left;
    while (i < biggerArea)
    {
        // 当前值小于基准值
        if (arr[i] < targetNum)
        {
            // 为了让小值在左，交换当前值与smallerArea+1地方的值
            std::swap(arr[smallerArea + 1], arr[i]);
            // smallerArea向右加1
            ++smallerArea;
            ++i;
        }
        else if (arr[i] > targetNum)
        {
            // 为了让大值在右，交换当前值与biggerArea - 1地方的值
            std::swap(arr[biggerArea - 1], arr[i]);
            // biggerArea向左加1
            --biggerArea;
        }
        else
        {
            ++i;
        }
    }

    // 直接将基准值放在i的地方即可，这样数组里就会是： 小于基准值---等于基准值---大于基准值
    std::swap(arr[i], arr[right]);
    return {smallerArea, biggerArea};
}

void Process2(std::vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }

    auto vec = Partition2(arr, left, right);
    auto smallerArea = vec[0];
    auto biggerArea = vec[1];
    Process2(arr, left, smallerArea);
    Process2(arr, biggerArea, right);
}

void QuickSort2(std::vector<int> &arr)
{
    int left = 0;
    int right = arr.size() - 1;
    Process2(arr, left, right);
}
#pragma endregion

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
    // 测试用例1：基础测试
    std::vector<int> arr1 = {5, 3, 8, 6, 9, 1};
    std::cout << "Test 1 (基础): ";
    PrintArr(arr1);
    QuickSort2(arr1);
    PrintArr(arr1);
    
    // 测试用例2：全相同
    std::vector<int> arr2 = {5, 5, 5, 5};
    std::cout << "Test 2 (全相同): ";
    PrintArr(arr2);
    QuickSort2(arr2);
    PrintArr(arr2);
    
    // 测试用例3：已排序
    std::vector<int> arr3 = {1, 2, 3, 4, 5};
    std::cout << "Test 3 (已排序): ";
    PrintArr(arr3);
    QuickSort2(arr3);
    PrintArr(arr3);
    
    // 测试用例4：逆序
    std::vector<int> arr4 = {5, 4, 3, 2, 1};
    std::cout << "Test 4 (逆序): ";
    PrintArr(arr4);
    QuickSort2(arr4);
    PrintArr(arr4);
    
    // 测试用例5：单个元素
    std::vector<int> arr5 = {42};
    std::cout << "Test 5 (单元素): ";
    PrintArr(arr5);
    QuickSort2(arr5);
    PrintArr(arr5);
    
    // 测试用例6：两个元素
    std::vector<int> arr6 = {2, 1};
    std::cout << "Test 6 (两元素): ";
    PrintArr(arr6);
    QuickSort2(arr6);
    PrintArr(arr6);
    
    // 测试用例7：包含负数
    std::vector<int> arr7 = {-5, 3, -1, 0, 8, -10};
    std::cout << "Test 7 (负数): ";
    PrintArr(arr7);
    QuickSort2(arr7);
    PrintArr(arr7);
    
    // 测试用例8：大量重复元素
    std::vector<int> arr8 = {3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5, 8, 9, 7, 9};
    std::cout << "Test 8 (大量重复): ";
    PrintArr(arr8);
    QuickSort2(arr8);
    PrintArr(arr8);
    
    // 测试用例9：大数组
    std::vector<int> arr9 = {64, 34, 25, 12, 22, 11, 90, 88, 45, 50, 23, 21, 78, 32, 67, 15};
    std::cout << "Test 9 (大数组): ";
    PrintArr(arr9);
    QuickSort2(arr9);
    PrintArr(arr9);
    
    // 测试用例10：几乎排序（大部分元素已排序）
    std::vector<int> arr10 = {1, 2, 3, 7, 5, 6, 4, 8, 9, 10};
    std::cout << "Test 10 (几乎排序): ";
    PrintArr(arr10);
    QuickSort2(arr10);
    PrintArr(arr10);
    
    // 测试用例11：锯齿形（交替大小）
    std::vector<int> arr11 = {1, 9, 2, 8, 3, 7, 4, 6, 5};
    std::cout << "Test 11 (锯齿形): ";
    PrintArr(arr11);
    QuickSort2(arr11);
    PrintArr(arr11);
    
    // 测试用例12：只有两个不同的值
    std::vector<int> arr12 = {1, 2, 1, 1, 2, 2, 1, 2, 1};
    std::cout << "Test 12 (两值重复): ";
    PrintArr(arr12);
    QuickSort2(arr12);
    PrintArr(arr12);
    
    // 测试用例13：包含0和负数的最大跨度
    std::vector<int> arr13 = {100, -50, 0, 75, -25, 50, -100, 25};
    std::cout << "Test 13 (大跨度): ";
    PrintArr(arr13);
    QuickSort2(arr13);
    PrintArr(arr13);
    
    // 测试用例14：前半段重复，后半段不同
    std::vector<int> arr14 = {5, 5, 5, 5, 3, 2, 4, 1};
    std::cout << "Test 14 (前重复): ";
    PrintArr(arr14);
    QuickSort2(arr14);
    PrintArr(arr14);
    
    // 测试用例15：后半段重复，前半段不同
    std::vector<int> arr15 = {8, 3, 7, 2, 1, 5, 5, 5, 5};
    std::cout << "Test 15 (后重复): ";
    PrintArr(arr15);
    QuickSort2(arr15);
    PrintArr(arr15);
    
    return 0;
}