#ifndef SORTTEST_H
#define SORTTEST_H

#include <iostream>
#include <ctime>
#include <random>

using namespace std;

int getrand(int lvalue, int rvalue)
{
    return (rand() % (rvalue - lvalue + 1) ) + lvalue;
}

template <class Type>
void getrandarry_new(Type R[], int N, int lvalue, int rvalue)
{
    default_random_engine e;
    uniform_int_distribution<int> u(lvalue,rvalue);
    e.seed(time(0));
    for(int i = 0; i < N; i ++)
        R[i] = u(e);
}

template <class Type>
void getrandarry_old(Type R[], int N, int lvalue, int rvalue)
{
    for(int i = 0; i < N; i ++)
        R[i] = getrand(lvalue,rvalue);
}

template <class Type>
void getSequentialArry(Type R[], int N)
{
    for(int i = 0; i < N; i ++)
        R[i] = N - i;
}

template <class Type>
void copyarray(Type array[], Type backup[], int N)
{
    for(int i = 0; i < N; i ++)
    {
        array[i] = backup[i];
    }
}

#endif // SORTTEST_H
