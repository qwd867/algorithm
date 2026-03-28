#include <iostream>
#include <vector>

// parentNode = (child -1 ) /2
// child = 2 * parentNode + 1

void HeapDeleteFirstElement(std::vector<int> &arr)
{
    arr[0] = arr[arr.size() - 1];
    int heapSize = arr.size() - 2;
    int i = 0;
    while (true)
    {
        auto leftChild = 2 * i + 1;
        auto rightChild = 2 * i + 2;
        if (leftChild >= heapSize || rightChild >= heapSize)
        {
            break;
        }

        if (arr[leftChild] >= arr[rightChild])
        {
            if (arr[i] < arr[leftChild])
            {
                std::swap(arr[i], arr[leftChild]);
                i = leftChild;
            }
            else
            {
                break;
            }
        }
        else
        {
            if (arr[i] < arr[rightChild])
            {
                std::swap(arr[i], arr[rightChild]);
                i = rightChild;
            }
            else
            {
                break;
            }
        }
    }
    arr.resize(heapSize + 1);
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
    std::vector<int> arr = {9, 7, 7, 6, 3, 4, 5};
    PrintArr(arr);
    HeapDeleteFirstElement(arr);
    PrintArr(arr);
}