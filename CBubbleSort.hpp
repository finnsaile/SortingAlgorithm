#pragma once
#include "CSort.hpp"

template <typename T>
class CBubbleSort : public CSort<T>
{
    public:
        virtual ~CBubbleSort(){};
        virtual T* sort(T* arr, long size) override;
        T* operator()(T* arr, long size);
};

template <typename T>
T* CBubbleSort<T>::sort(T* arr, long size)
{

    for(long i = 0; i < size - 1; i++)
    {
        for (long j = size - 1;  j > i; j--)
        {
            if (arr[j] < arr[j-1])
                this->swap(arr[j], arr[j-1]);
        }
    }
    return arr;
}

template <typename T>
T* CBubbleSort<T>::operator()(T* arr, long size)
{
    this->startTimer();
    this->sort(arr,size);
    this->endTimer();

    std::stringstream ss; 
    ss << GREEN << "   ---BUBBLE SORT DONE---\n" << RED <<"---Time Elapsed: " << this->getDuration().count() << " ms---\n\n" << RESET;
    std::cout << ss.str();

    return arr;
}
