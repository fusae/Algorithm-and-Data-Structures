#include <iostream>
#include <algorithm>

void BubbleSort(int *a, int length)
{
    for (int i = 0; i != length; i++)
    {
        for (int j = 0; j != length-1-i; j++)
        {
            if (a[j] > a[j+1])
                std::swap(a[j], a[j+1]);
        }
    }
}

int main(void)
{
    int a[6] = {5,4,6,2,3,5};

    BubbleSort(a, 6);

    for (int i = 0; i != 6; i++)
        std::cout << a[i] << " ";
    std::cout << "\n";

    return 0;
}
