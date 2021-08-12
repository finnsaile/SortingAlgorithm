#pragma once
#include "CSort.hpp"

template <typename T>
class CQuickSort : public CSort<T>
{
    public:
        virtual ~CQuickSort(){};
        virtual T* sort(T* arr, long size) override;
        T* sort(T* arr, long l, long r);
        long partition (T* arr, long l, long r);
        T* operator()(T* arr, long size);  
};

template <typename T>
T* CQuickSort<T>::sort(T* arr, long size)
{
    return this->sort(arr, 0, size);
}

template <typename T>
T* CQuickSort<T>::sort(T* arr, long l, long r)
{
    if(l < (r-1))
    {
        long m = partition(arr, l, r);

        this->sort(arr, l, m);
        this->sort(arr, m + 1, r);
    }
    return arr;
}   

template <typename T>
long CQuickSort<T>::partition(T* arr, long l, long r)
{
    T& x = arr[r - 1];
    long i = l;
    long j = r - 1;

    while (i < j)
    {
        while ((i < j) && (arr[i] <= x))
        {
            i++;
        }
        
        while ((i < j) && (x <= arr[j]))
        {
            j--;
        }

        if (i < j)
        {
            this->swap(arr[i], arr[j]);
        }     
    }

    this->swap(arr[i], arr[r - 1]);
    return i;
}

template <typename T>
T* CQuickSort<T>::operator()(T* arr, long size)
{
    this->startTimer();
    this->sort(arr, 0, size);
    this->endTimer();

    std::stringstream ss; 
    ss << GREEN << "    ---QUICK SORT DONE---\n" << RED <<"---Time Elapsed: " << this->getDuration().count() << " ms---\n\n" << RESET;
    std::cout << ss.str();

    return arr;
}
