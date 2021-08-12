#pragma once
#include "CSort.hpp"

template <typename T>
class CSelectionSort : public CSort<T>
{
    public:
        virtual ~CSelectionSort(){};
        virtual T* sort(T* arr, long size) override;
        T* operator()(T* arr, long size);
};

template <typename T>
T* CSelectionSort<T>::sort(T* arr, long size)
{
    for (long i = 0; i < (size-1); i++)
    {
        long min_pos = i;
        for(long j = i; j < size; j++)
        {
            if (arr[min_pos] > arr[j])
            {
                min_pos = j;
            }
        }
        this->swap(arr[i], arr[min_pos]);
    }
    return arr;
}

template <typename T>
T* CSelectionSort<T>::operator()(T* arr, long size)
{
    this->startTimer();
    this->sort(arr, size);
    this->endTimer();

    std::stringstream ss; 
    ss << GREEN << "  ---SELECTION SORT DONE---\n" << RED <<"---Time Elapsed: " << this->getDuration().count() << " ms---\n\n" << RESET;
    std::cout << ss.str();
    
    return arr;
}