#ifndef TESTDATA_H
#define TESTDATA_H

#include<QStandardItemModel>
#include <QDebug>

typedef long long LL;


class testData
{
public:
    int N;
    LL *bubblesort_compare, *bubblesort_shift, *bubblesort_time;
    LL *straightinsertsort_compare, *straightinsertsort_shift, *straightinsertsort_time;
    LL *straightselectsort_compare, *straightselectsort_shift, *straightselectsort_time;
    LL *shellsort_compare, *shellsort_shift, *shellsort_time;
    LL *heapsort_compare, *heapsort_shift, *heapsort_time;
    LL *mergesort_compare, *mergesort_shift, *mergesort_time;
    LL *quicksort_compare, *quicksort_shift, *quicksort_time;

    int bubblesort_compare_avg, bubblesort_shift_avg, bubblesort_time_avg;
    int straightinsertsort_compare_avg, straightinsertsort_shift_avg, straightinsertsort_time_avg;
    int straightselectsort_compare_avg, straightselectsort_shift_avg, straightselectsort_time_avg;
    int shellsort_compare_avg, shellsort_shift_avg, shellsort_time_avg;
    int heapsort_compare_avg, heapsort_shift_avg, heapsort_time_avg;
    int mergesort_compare_avg, mergesort_shift_avg, mergesort_time_avg;
    int quicksort_compare_avg, quicksort_shift_avg, quicksort_time_avg;

    testData(int n)
    {
        N = n;
        bubblesort_compare = new LL[n], bubblesort_shift = new LL[n], bubblesort_time = new LL[n];
        straightinsertsort_compare = new LL[n], straightinsertsort_shift = new LL[n], straightinsertsort_time = new LL[n];
        straightselectsort_compare = new LL[n], straightselectsort_shift = new LL[n], straightselectsort_time = new LL[n];
        shellsort_compare = new LL[n], shellsort_shift = new LL[n], shellsort_time = new LL[n];
        heapsort_compare = new LL[n], heapsort_shift = new LL[n], heapsort_time = new LL[n];
        mergesort_compare = new LL[n], mergesort_shift = new LL[n], mergesort_time = new LL[n];
        quicksort_compare = new LL[n], quicksort_shift = new LL[n], quicksort_time = new LL[n];

        bubblesort_compare_avg = 0, bubblesort_shift_avg = 0, bubblesort_time_avg = 0;
        straightinsertsort_compare_avg = 0, straightinsertsort_shift_avg = 0, straightinsertsort_time_avg = 0;
        straightselectsort_compare_avg = 0, straightselectsort_shift_avg = 0, straightselectsort_time_avg = 0;
        shellsort_compare_avg = 0, shellsort_shift_avg = 0, shellsort_time_avg = 0;
        heapsort_compare_avg = 0, heapsort_shift_avg = 0, heapsort_time_avg = 0;
        mergesort_compare_avg = 0, mergesort_shift_avg = 0, mergesort_time_avg = 0;
        quicksort_compare_avg = 0, quicksort_shift_avg = 0, quicksort_time_avg = 0;
        for(int i = 0; i < n; i ++)
        {
            bubblesort_compare[i] = 0, bubblesort_shift[i] = 0, bubblesort_time[i] = 0;
            straightinsertsort_compare[i] = 0, straightinsertsort_shift[i] = 0, straightinsertsort_time[i] = 0;
            straightselectsort_compare[i] = 0, straightselectsort_shift[i] = 0, straightselectsort_time[i] = 0;
            shellsort_compare[i] = 0, shellsort_shift[i] = 0, shellsort_time[i] = 0;
            heapsort_compare[i] = 0, heapsort_shift[i] = 0, heapsort_time[i] = 0;
            mergesort_compare[i] = 0, mergesort_shift[i] = 0, mergesort_time[i] = 0;
            quicksort_compare[i] = 0, quicksort_shift[i] = 0, quicksort_time[i] = 0;
        }
    }
    testData()
    {
        N = 0;

        bubblesort_compare_avg = 0, bubblesort_shift_avg = 0, bubblesort_time_avg = 0;
        straightinsertsort_compare_avg = 0, straightinsertsort_shift_avg = 0, straightinsertsort_time_avg = 0;
        straightselectsort_compare_avg = 0, straightselectsort_shift_avg = 0, straightselectsort_time_avg = 0;
        shellsort_compare_avg = 0, shellsort_shift_avg = 0, shellsort_time_avg = 0;
        heapsort_compare_avg = 0, heapsort_shift_avg = 0, heapsort_time_avg = 0;
        mergesort_compare_avg = 0, mergesort_shift_avg = 0, mergesort_time_avg = 0;
        quicksort_compare_avg = 0, quicksort_shift_avg = 0, quicksort_time_avg = 0;
    }

    ~testData()
    {
        delete [] bubblesort_compare;
        delete [] bubblesort_shift;
        delete [] bubblesort_time;
        delete [] straightinsertsort_compare;
        delete [] straightinsertsort_shift;
        delete [] straightinsertsort_time;
        delete [] straightselectsort_compare;
        delete [] straightselectsort_shift;
        delete [] straightselectsort_time;
        delete [] shellsort_compare;
        delete [] shellsort_shift;
        delete [] shellsort_time;
        delete [] heapsort_compare;
        delete [] heapsort_shift;
        delete [] heapsort_time;
        delete [] mergesort_compare;
        delete [] mergesort_shift;
        delete [] mergesort_time;
        delete [] quicksort_compare;
        delete [] quicksort_shift;
        delete [] quicksort_time;
    }

    void calculateAvg();
    void show_Listview(QStandardItemModel *modle);
    void show_avg_QDebug();
    QString timeConversion(LL time);
    void Stest();
    void resetdata();


};


#endif // TESTDATA_H
