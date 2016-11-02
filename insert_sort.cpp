#include <iostream>
#include <utility>

void insert_sort(int* a, int length)
{
    for (int i = 1; i != length; i++)
    {
        for (int j = i; j != 0; j--)
        {
            if (a[j] < a[j-1])
                std::swap(a[j], a[j-1]);
        }
    }
}

int main(void)
{
    int a[8] = {9,13,24,64,7,23,34,47};

    insert_sort(a, 8);

    for (int i = 0; i != 8; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    return 0;
}
