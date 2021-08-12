#include <iostream>
#include <random>
#include <thread>
#include <vector>
#include "CSelectionSort.hpp"
#include "CInsertionSort.hpp"
#include "CBubbleSort.hpp"
#include "CMergeSort.hpp"
#include "CQuickSort.hpp"

template <typename T> void printArray(T* arr, size_t N);

int main()
{
    srand (time(NULL));

    CInsertionSort<int> insSorter;
    CSelectionSort<int> selSorter;
    CBubbleSort<int> bubSorter;
    CMergeSort<int> merSorter;
    CQuickSort<int> quiSorter;

    long N = 10000;
    std::vector<int*> arr = 
    {
        new int[N],
        new int[N],
        new int[N],
        new int[N],
        new int[N]
    };

    for (size_t i = 0; i < N; i++)
    {
        for (int *a : arr)
            a[i] = rand() % N + 1;    
    }

    std::thread insSort(insSorter, arr[0], N);
    std::thread selSort(selSorter, arr[1], N);
    std::thread bubSort(bubSorter, arr[2], N);
    std::thread merSort(merSorter, arr[3], N);
    std::thread quiSort(quiSorter, arr[4], N);
    
    insSort.join();
    selSort.join();
    bubSort.join();
    merSort.join();
    quiSort.join();

    for (int* a : arr)
        delete[] a;

    return 0;
}

template <typename T>
void printArray(T* arr, size_t N)
{
    std::cout << "[" << arr[0];
    for(size_t i = 1; i < N; i++)
    {
        std::cout << ", " << arr[i]; 
    }
    std::cout << "]\n" << std::endl;
}