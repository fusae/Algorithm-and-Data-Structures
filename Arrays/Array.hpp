#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>

template <typename T>
class Array
{
public:
    Array();
    Array(int n, T item);
    ~Array();

    T &operator[](int index);

    std::size_t size() {return m_size;}
    std::size_t capacity() {return m_capacity;}
    bool is_empty() {return m_size == 0;}
    T at(int index);
    void push(T item);
    void insert(int index, T item);
    void prepend(T item); // insert(0, item)
    T pop();
    void delete_item(int index);
    std::size_t remove(T item);
    int find(T item);

private:
    enum {default_capacity = 8};
    T *m_arr;
    std::size_t m_size;
    std::size_t m_capacity;

    void resize(std::size_t new_capacoty);
};

template <typename T>
Array<T>::Array()
{
    m_size = 0;
    m_capacity = default_capacity;
    m_arr = new T[m_capacity];
}

template <typename T>
Array<T>::Array(int n, T item)
{
    m_size = 0;
    m_capacity = default_capacity;
    m_arr = new T[m_capacity];
    for (int i = 0; i != n; i++)
        push(item);
}


template <typename T>
Array<T>::~Array()
{
    delete[] m_arr;
}

template <typename T>
T &Array<T>::operator[](int index)
{
    // check index
    if (index < 0 || index >= static_cast<int>(m_size))
        throw 1; // means error index

    return *(m_arr+index);
}

template <typename T>
T Array<T>::at(int index)
{
    // check index
    if (index < 0 || index >= static_cast<int>(m_size))
        throw 1;

    return *(m_arr+index);
}

template <typename T>
void Array<T>::push(T item)
{
    *(m_arr+m_size) = item;
    m_size++;
    if (m_size == m_capacity)
        resize(2*m_capacity);
}

template <typename T>
void Array<T>::insert(int index, T item)
{
    // check index
    if (index < 0 || index >= static_cast<int>(m_size))
        throw 1;

    for (int i = m_size; i > index; i--)
    {
        *(m_arr+i) = *(m_arr+(i-1));
    }
    *(m_arr+index) = item;
    m_size++;
}

template <typename T>
void Array<T>::prepend(T item) // insert(0, item)
{
    insert(0, item);
}

template <typename T>
T Array<T>::pop()
{
    if (is_empty())
        throw 2;    // empty array
    T item = *(m_arr+(m_size-1));
    m_size--;
    if (m_size * 4 <= m_capacity)
        resize(0.5*m_capacity);
    return item;
}

template <typename T>
void Array<T>::delete_item(int index)
{
    // check index
    if (index < 0 || index >= static_cast<int>(m_size))
        throw 1;

    if (index == static_cast<int>(m_size)-1)
    {
        pop();
        return;
    }

    for (std::size_t i = index; i < m_size-1; i++)
        *(m_arr+i) = *(m_arr+(i+1));
    m_size--;
}

template <typename T>
int Array<T>::find(T item)
{
    for (std::size_t i = 0; i < m_size; i++)
    {
        if (item == *(m_arr+i))
            return i;
    }
    return -1;
}

template <typename T>
std::size_t Array<T>::remove(T item)
{
    int index = find(item);
    while (index != -1)
    {
        delete_item(index);
        index = find(item);
    }
    return index;
}

template <typename T>
void Array<T>::resize(std::size_t new_capacoty)
{
    T *new_arr = new T[new_capacoty];
    for (std::size_t i = 0; i != m_size; i++)
    {
        *(new_arr+i) = *(m_arr+i);
    }
    delete[] m_arr;

    m_arr = new_arr;
    m_capacity = new_capacoty;

}



#endif
