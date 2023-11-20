#ifndef SORT_H
#define SORT_H

#include <iostream>
#include <Windows.h>
#include <chrono>
#include <QDebug>

using namespace std;
using namespace std::chrono;

typedef long long LL;

template <class Type>
void bubblesort(Type R[], int size, LL &compare, LL &shift, LL &time)
{
    //qDebug()<<"bubblesort():"<<endl<<"compare: "<<compare<<" shift: "<<shift<<" time: "<<time;
    auto start = steady_clock::now();//精确到纳秒
    int i, j;
    bool flag = true;
    for(i = 1; i < size && flag; i ++)
    {
        flag = false;
        for(j = 0; j < size - i; j ++)
        {
            compare ++;
            if(R[j + 1] < R[j])
            {
                shift += 3;
                swap(R[j + 1], R[j]);
                flag = true;
            }
        }
    }
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
    //qDebug()<<"bubblesort():"<<endl<<"compare: "<<compare<<" shift: "<<shift<<" time: "<<time;

}

template <class Type>
void straightselectsort(Type R[], int size, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();

    int pos, min, j;
    for(pos = 0; pos < size - 1; pos ++)
    {
        min = pos;
        for(j = pos + 1; j < size; j ++)
        {
            compare ++;
            if(R[j] < R[min]) min = j;
            if(pos != min)
            {
                shift +=3;
                swap(R[pos], R[min]);
            }

        }
    }
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}

template <class Type>
void straightinsertsort(Type R[], int size, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();
    int pos, j;
    Type tmp;
    for(pos = 1; pos < size; pos ++)
    {
        tmp = R[pos];
        shift ++;
        for(j = pos - 1; j >= 0 && tmp < R[j]; j --)
        {
            R[j + 1] = R[j];
            shift ++;
            compare ++;
        }
        compare ++;
        R[j + 1] = tmp;
        shift ++;
    }
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}

template <class Type>
void siftdown(Type R[], int pos, int size, LL &compare, LL &shift)
{
    int child;
    Type tmp = R[pos];
    for( ; pos * 2 + 1 < size; pos = child)
    {
        child = pos * 2 + 1;
        compare ++;
        if(child != size - 1 && R[child + 1] > R[child])
        {
            child ++;
        }
        compare ++;
        if(R[child] > tmp)
        {
            R[pos] = R[child];
            shift ++;
        }
        else break;
    }
    R[pos] = tmp;
    shift ++;
}

template <class Type>
void heapsort(Type R[], int size, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();
    int i;
    for(i = size / 2 - 1; i >= 0; i --)
    {
        siftdown(R, i, size, compare, shift);
    }
    for(i = size - 1; i > 0; i --)
    {
        swap(R[0], R[i]);
        shift +=3;
        siftdown(R, 0, i, compare, shift);
    }
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}

template <class Type>
void shellsort (Type R[], int size, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();
    int gap, pos, j;
    Type tmp;
    for(gap = size / 2; gap > 0; gap /= 2)
        for(pos = gap; pos < size; pos ++)
        {
            tmp = R[pos];
            shift ++;
            for(j = pos - gap; j >= 0 && R[j] > tmp; j -= gap)
            {
                R[j + gap] = R[j];
                shift ++;
                compare ++;
            }
            compare ++;
            R[j + gap] = tmp;
            shift ++;
        }
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}

template <class Type>
void merge(Type R[], int left, int right, LL &compare, LL &shift)
{
    Type tmp[right - left + 1];
    if(left >= right) return;

    Type mid = left + right >> 1;
    merge(R, left, mid, compare, shift);
    merge(R, mid + 1, right, compare, shift);

    int k = 0;
    int i = left, j = mid + 1;
    while(i <= mid && j <= right)
    {
        compare ++;
        if(R[i] <= R[j]) tmp[k ++] = R[i ++];
        else tmp[k ++] = R[j ++];
        shift ++;
    }
    while(i <= mid)
    {
        tmp[k ++] = R[i ++];
        shift ++;
    }
    while(j <= right)
    {
        tmp[k ++] = R[j ++];
        shift ++;
    }

    for(int i = left, j = 0; i <= right; i ++, j ++)
    {
        R[i] = tmp[j];
        shift ++;
    }

}

template <class Type>
void mergesort(Type R[], int left, int right, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();
    merge(R, left, right - 1, compare, shift);
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}


template <class Type>
void quick(int left, int right, Type R[], LL &compare, LL &shift)
{
    if(left >= right ) return;
    int i = left, j = right - 1;
    Type base = R[left];
    while(i < j)
    {
        while(R[j] >= base && i < j)
        {
            compare ++;
            j --;
        }
        compare ++;
        while(R[i] <= base && i < j)
        {
            compare ++;
            i ++;
        }
        compare ++;
        if(i < j)
        {
            swap(R[i], R[j]);
            shift +=3;
        }
    }
    swap(R[left], R[i]);
    shift +=3;
    quick(left, i, R, compare, shift);
    quick(i + 1, right, R, compare, shift);
}

template <class Type>
void quicksort(Type R[], int left, int right, LL &compare, LL &shift, LL &time)
{
    auto start = steady_clock::now();
    quick(left, right, R, compare, shift);
    auto end = steady_clock::now();
    auto t = duration_cast<microseconds>(end - start);
    //time += t.count();
    time = t.count();
}

#endif // SORT_H
