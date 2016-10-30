#include "Heap.hpp"

int main(void)
{
    int arr[7] = {9,8,12,11,14,13,15};

    MaxHeap<int> mh(arr, 7, 999);
    mh.print();

    mh.insert(10);
    mh.print();

    mh.insert(16);
    mh.print();

    mh.remove(0);
    mh.print();

    mh.remove(7);
    mh.print();

    int m = mh.extract_max();
    std::cout << m << "\n";
    mh.print();

    mh.change_priority(1, 20);
    mh.print();

    mh.heap_sort();
    mh.print();


    return 0;
}
