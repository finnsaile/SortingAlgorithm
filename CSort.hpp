#pragma once
#include <iostream>
#include <chrono>
#include <string>
#include <sstream>

#define BLACK "\u001b[30m"
#define RED "\u001b[31m"
#define GREEN "\u001b[32m"
#define YELLOW "\u001b[33m"
#define BLUE "\u001b[34m"
#define MAGENTA "\u001b[35m"
#define CYAN "\u001b[36m"
#define WHITE "\u001b[37m"
#define RESET "\u001b[0m"

template <typename T>
class CSort 
{
    public:
        virtual ~CSort(){};
        virtual T* sort(T* arr, long size) = 0;   
        void swap(T& pos1, T& pos2);
        void startTimer();
        auto endTimer();
        auto getDuration();
    private:
        std::chrono::duration<double, std::milli> duration_;
        std::chrono::time_point<std::chrono::high_resolution_clock> start_, end_;
};

template <typename T>
void CSort<T>::swap(T& pos1, T& pos2)
{
    T temp = pos1;
    pos1 = pos2;
    pos2 = temp;
}

template <typename T>
void CSort<T>::startTimer()
{
    start_ = std::chrono::high_resolution_clock::now();
}

template <typename T>
auto CSort<T>::endTimer()
{
    end_ = std::chrono::high_resolution_clock::now();
    return duration_ = end_ - start_;
}

template <typename T>
auto CSort<T>::getDuration()
{
    return duration_;
}