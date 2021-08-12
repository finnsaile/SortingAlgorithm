#pragma once
#include "CSort.hpp"
#include <vector>

template <typename T>
class CMergeSort : public CSort<T>
{
    public:
        virtual ~CMergeSort(){};
        virtual T* sort(T* arr, long size) override;
        T* sort(T* arr, long l, long r);
        void merge (T* arr, long l, long m, long r);
        T* operator()(T* arr, long size);    
};

template <typename T>
T* CMergeSort<T>::sort(T* arr, long size)
{
    return this->sort(arr, 0, size);
}

template <typename T>
T* CMergeSort<T>::sort(T* arr, long l, long r)
{
    if(l < (r-1))
    {
        long m = (l + r) / 2;

        this->sort(arr, l, m);
        this->sort(arr, m, r);

        this->merge(arr, l, m, r);
    }
    return arr;
}   

template <typename T>
void CMergeSort<T>::merge(T* arr, long l, long m, long r)
{
    long n1 = m - l;
    long n2 = r - m;
    std::vector<T> llist;
    std::vector<T> rlist;

    for (long i = 0; i < n1; i++)
    {
        llist.push_back(arr[l + i]);
    }
    for (long j = 0; j < n2; j++)
    {
        rlist.push_back(arr[m + j]);
    }

    long i = 0, j = 0, k = l;
    while (k < r)
    {
        if((i < n1) && (j < n2))
        {
            if(llist[i] < rlist[j])
            {
                arr[k] = llist[i];
                i++;
                k++;
            }
            else
            {
                arr[k] = rlist[j];
                j++;
                k++;
            }
        }
        else
        {
            while (i < n1)
            {
                arr[k] = llist[i];
                i++;
                k++;
            }
            while ( j < n2)
            {
                arr[k] = rlist[j];
                j++;
                k++;
            }
        }
    }
}

template <typename T>
T* CMergeSort<T>::operator()(T* arr, long size)
{
    this->startTimer();
    this->sort(arr, 0, size);
    this->endTimer();

    std::stringstream ss; 
    ss << GREEN << "    ---MERGE SORT DONE---\n" << RED <<"---Time Elapsed: " << this->getDuration().count() << " ms--- \n\n" << RESET;
    std::cout << ss.str();

    return arr;
}
