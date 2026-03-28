cmake_minimum_required(VERSION 3.10)
project(Algorithm)

# C++ 标准
set(CMAKE_CXX_STANDARD 11)

# 把 SortHelper 编译成静态库（所有排序都能复用）
add_library(SortHelper STATIC
    SortHelper/SortHelper.cpp
)

# 包含头文件路径
include_directories(SortHelper)

# ========== 编译每个排序程序 ==========
# 选择排序
add_executable(SelectSort SelectSort/SelectSort.cpp)
target_link_libraries(SelectSort SortHelper)

# 冒泡排序（你有其他排序就照抄这两行）
add_executable(BubbleSort BubbleSort/BubbleSort.cpp)
target_link_libraries(BubbleSort SortHelper)