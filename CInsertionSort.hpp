#pragma once
#include "CSort.hpp"

template <typename T>
class CInsertionSort : public CSort<T>
{
    public:
        virtual ~CInsertionSort(){};
        virtual T* sort(T* arr, long size) override;
        T* operator()(T* arr, long size);
};

template <typename T>
T* CInsertionSort<T>::sort(T* arr, long size)
{

    for (long j = 1; j < size; j++)
    {
        T key = arr[j];
        long i = j -1;

        while((i >= 0) && (arr[i] > key))
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i+1] = key;
    }

    return arr;
}

template <typename T>
T* CInsertionSort<T>::operator()(T* arr, long size)
{
    this->startTimer();
    this->sort(arr, size);
    this->endTimer();

    std::stringstream ss;
    ss << GREEN << "  ---INSERTION SORT DONE---\n" << RED <<"---Time Elapsed: " << this->getDuration().count() << " ms---\n\n" << RESET;
    std::cout << ss.str();
    
    return arr;
}