
/*
Min Root Heap is a very difficult implementation in c++
Especially handling of new input data to it.
*/

#include <iostream>
#include <conio.h>

using namespace std;

void min_heap(int *a, int m, int n)
{
    int j, t;
    t = a[m];
    j = 2 * m;
    while (j <= n)
    {
        if (j < n && a[j + 1] < a[j])
            j = j + 1;

        if (t < a[j])
            break;
        else if (t >= a[j])
        {
            a[j / 2] = a[j];
            j = 2 * j;
        }
    }
    a[j / 2] = t;
    return;
}

void build_minheap(int *a, int n)
{
    int k;
    for (k = n / 2; k >= 1; k--)
    {
        min_heap(a, k, n);
    }
}