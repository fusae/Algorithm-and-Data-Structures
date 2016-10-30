#ifndef HEAP_HPP
#define HEAP_HPP

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
class MaxHeap
{
private:
    std::vector<T> vec_;    // 0 based vector
    T infinite_;

    // return index
    std::size_t parent(std::size_t i)   {if (i > 0) return (i-1)/2;}
    std::size_t left_child(std::size_t i)   {if (i >= 0) return 2*i+1;}
    std::size_t right_child(std::size_t i)  {if (i >= 0) return 2*i+2;}

    bool is_empty() {return vec_.size() > 0;}
    std::size_t get_size()  {return vec_.size();}
    int get_max()   {if (!is_empty())   return vec_[0];}

    void sift_up(std::size_t i);
    void sift_down(std::size_t i, std::size_t size);
    void build_heap();


public:

    MaxHeap(const T* arr, std::size_t length, T infinite);    // an array
    MaxHeap(const std::vector<T>& vec, T infinite);           // a vector

    void insert(const T& p);
    T extract_max();
    void remove(std::size_t i);
    void change_priority(std::size_t i, const T& p);
    void heap_sort();
    void print();


};

template <typename T>
void MaxHeap<T>::sift_up(std::size_t i)
{
    while (i > 0 && vec_[parent(i)] < vec_[i])
    {
        std::swap(vec_[parent(i)], vec_[i]);
        i = parent(i);
    }
}

template <typename T>
void MaxHeap<T>::sift_down(std::size_t i, std::size_t size)
{
    std::size_t max_index = i;

    std::size_t left = left_child(i);
    if (left < size && vec_[left] > vec_[max_index])
        max_index = left;

    std::size_t right = right_child(i);
    if (right < size && vec_[right] > vec_[max_index])
        max_index = right;

    if (i != max_index)
    {
        std::swap(vec_[i], vec_[max_index]);
        sift_down(max_index, size);
    }
}

template <typename T>
void MaxHeap<T>::build_heap()
{
    for (int i = (vec_.size()-2) / 2; i >= 0; i--)
        sift_down(i, vec_.size());
}

template <typename T>
MaxHeap<T>::MaxHeap(const T* arr, std::size_t length, T infinite): infinite_(infinite)
{
    for (std::size_t i = 0; i != length; i++)
        vec_.push_back(*(arr+i));
    
    build_heap();
}

template <typename T>
MaxHeap<T>::MaxHeap(const std::vector<T>& vec, T infinite): infinite_(infinite)
{
    vec_ = vec; // copy
    build_heap();
}

template <typename T>
void MaxHeap<T>::insert(const T& p)
{
    vec_.push_back(p);
    sift_up(vec_.size()-1);
}

template <typename T>
T MaxHeap<T>::extract_max()
{
    T result = vec_[0]; // root
    vec_[0] = vec_[vec_.size()-1];
    vec_.pop_back();
    sift_down(0, vec_.size());
    return result;
}

template <typename T>
void MaxHeap<T>::remove(std::size_t i)
{
    if (i >= 0 && i < vec_.size())
    {
        vec_[i] = infinite_;
        sift_up(i);
        extract_max();
    }
    else
    {
        std::cerr << "invalid index\n";
    }
}

template <typename T>
void MaxHeap<T>::change_priority(std::size_t i, const T& p)
{
    if (i >= 0 && i < vec_.size())
    {
        T oldp = vec_[i];
        vec_[i] = p;
        if (p > oldp)   sift_up(i);
        else    sift_down(i, vec_.size());
    }
    else
    {
        std::cerr << "invalid index\n";
    }

}

template <typename T>
void MaxHeap<T>::heap_sort()
{
//    build_heap();

    int size = vec_.size() - 1;
    for (std::size_t i = 1; i != vec_.size(); i++)
    {
        std::swap(vec_[0], vec_[size]);
        size--;
        sift_down(0, size);
    }
}

template <typename T>
void MaxHeap<T>::print()
{
    for (auto it = vec_.cbegin(); it != vec_.cend(); ++it)
        std::cout << *it << " ";
    std::cout << "\n";
}

#endif
