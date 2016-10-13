#include "Array.hpp"

int main(void)
{
    try
    {
        Array<int> arr;
        for(int i = 0; i != 10; i++)
            arr.push(i);

        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call size()\n";
        std::cout << arr.size() << "\n";

        std::cout << "call capacity();\n";
        std::cout << arr.capacity() << "\n";

        std::cout << "call is_empty()\n";
        std::cout << arr.is_empty() << "\n";

        std::cout << "call at(5)\n";
        std::cout << arr.at(5) << "\n";

        std::cout << "call push(100)\n";
        arr.push(100);
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call insert(3, 99)\n";
        arr.insert(3, 99);
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call prepend(42)\n";
        arr.prepend(42);
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call pop()\n";
        int item = arr.pop();
        std::cout << "returned item: " << item << "\n";
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call delete_item(7)\n";
        arr.delete_item(7);
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call remove(100)\n";
        int index = arr.remove(100);
        std::cout << "returned index: " << index << "\n";
        for (std::size_t i = 0; i != arr.size(); i++)
            std::cout << arr[i] << " ";
        std::cout << "\n";

        std::cout << "call find(42)\n";
        std::cout << "return index: " << arr.find(42) << "\n";

        std::cout << "call size()\n";
        std::cout << arr.size() << "\n";

        std::cout << "call capacity();\n";
        std::cout << arr.capacity() << "\n";


        Array<int> arr2(20, 42);
        for (std::size_t i = 0; i != arr2.size(); i++)
            std::cout << arr2[i] << " ";
        std::cout << "\n";

            

    }
    catch (int e)
    {
        switch(e)
        {
            case 1:
                std::cerr << "error index\n"; 
            case 2:
                std::cerr << "empty array\n";
        }
    }
    return 0;
}
