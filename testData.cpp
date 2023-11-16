#include"testdata.h"

QString testData::timeConversion(LL time)
{
    return QString::number(time / 1000000) + "ms" + QString::number(time % 1000000 / 1000) + "μs " + QString::number(time % 1000) + "ns";
}


void testData::show_Listview(QStandardItemModel *modle)
{
    modle->setItem(0, 0, new QStandardItem(QString::number(bubblesort_compare_avg)));
    modle->setItem(0, 1, new QStandardItem(QString::number(bubblesort_shift_avg)));
    modle->setItem(0, 2, new QStandardItem(timeConversion(bubblesort_time_avg)));

    modle->setItem(1, 0, new QStandardItem(QString::number(straightinsertsort_compare_avg)));
    modle->setItem(1, 1, new QStandardItem(QString::number(straightinsertsort_shift_avg)));
    modle->setItem(1, 2, new QStandardItem(timeConversion(straightinsertsort_time_avg)));

    modle->setItem(2, 0, new QStandardItem(QString::number(straightselectsort_compare_avg)));
    modle->setItem(2, 1, new QStandardItem(QString::number(straightselectsort_shift_avg)));
    modle->setItem(2, 2, new QStandardItem(timeConversion(straightselectsort_time_avg)));

    modle->setItem(3, 0, new QStandardItem(QString::number(shellsort_compare_avg)));
    modle->setItem(3, 1, new QStandardItem(QString::number(shellsort_shift_avg)));
    modle->setItem(3, 2, new QStandardItem(timeConversion(shellsort_time_avg)));
    modle->setItem(4, 0, new QStandardItem(QString::number(heapsort_compare_avg)));
    modle->setItem(4, 1, new QStandardItem(QString::number(heapsort_shift_avg)));
    modle->setItem(4, 2, new QStandardItem(timeConversion(heapsort_time_avg)));
    modle->setItem(5, 0, new QStandardItem(QString::number(mergesort_compare_avg)));
    modle->setItem(5, 1, new QStandardItem(QString::number(mergesort_shift_avg)));
    modle->setItem(5, 2, new QStandardItem(timeConversion(mergesort_time_avg)));
    modle->setItem(6, 0, new QStandardItem(QString::number(quicksort_compare_avg)));
    modle->setItem(6, 1, new QStandardItem(QString::number(quicksort_shift_avg)));
    modle->setItem(6, 2, new QStandardItem(timeConversion(quicksort_time_avg)));
}

void testData::show_avg_QDebug()
{
    qDebug()<<"times: "<< N;
    qDebug()<<"--------------";
    qDebug()<<"bubblesort:"<<endl<<"compare: "<<bubblesort_compare_avg<<" shift: "<<bubblesort_shift_avg<<" time: "<<timeConversion(bubblesort_time_avg);
    qDebug()<<"straightinsertsort:"<<endl<<"compare: "<<straightinsertsort_compare_avg<<" shift: "<<straightinsertsort_shift_avg<<" time: "<<timeConversion(straightinsertsort_time_avg);
    qDebug()<<"straightselectsort:"<<endl<<"compare: "<<straightselectsort_compare_avg<<" shift: "<<straightselectsort_shift_avg<<" time: "<<timeConversion(straightselectsort_time_avg);
    qDebug()<<"shellsort:"<<endl<<"compare: "<<shellsort_compare_avg<<" shift: "<<shellsort_shift_avg<<" time: "<<timeConversion(shellsort_time_avg);
    qDebug()<<"heapsort:"<<endl<<"compare: "<<heapsort_compare_avg<<" shift: "<<heapsort_shift_avg<<" time: "<<timeConversion(heapsort_time_avg);
    qDebug()<<"mergesort:"<<endl<<"compare: "<<mergesort_compare_avg<<" shift: "<<mergesort_shift_avg<<" time: "<<timeConversion(mergesort_time_avg);
    qDebug()<<"quicksort:"<<endl<<"compare: "<<quicksort_compare_avg<<" shift: "<<quicksort_shift_avg<<" time: "<<timeConversion(quicksort_time_avg);

}

void testData::calculateAvg()
{
    for(int i = 0; i < N; i ++)
    {
        bubblesort_compare_avg += bubblesort_compare[i], bubblesort_shift_avg += bubblesort_shift[i], bubblesort_time_avg += bubblesort_time[i];

        straightinsertsort_compare_avg += straightinsertsort_compare[i], straightinsertsort_shift_avg += straightinsertsort_shift[i], straightinsertsort_time_avg += straightinsertsort_time[i];
        straightselectsort_compare_avg += straightselectsort_compare[i], straightselectsort_shift_avg += straightselectsort_shift[i], straightselectsort_time_avg += straightselectsort_time[i];

        shellsort_compare_avg += shellsort_compare[i], shellsort_shift_avg += shellsort_shift[i], shellsort_time_avg += shellsort_time[i];
        heapsort_compare_avg += heapsort_compare[i], heapsort_shift_avg += heapsort_shift[i], heapsort_time_avg += heapsort_time[i];
        mergesort_compare_avg += mergesort_compare[i], mergesort_shift_avg += mergesort_shift[i], mergesort_time_avg += mergesort_time[i];
        quicksort_compare_avg += quicksort_compare[i], quicksort_shift_avg += quicksort_shift[i], quicksort_time_avg += quicksort_time[i];
    }
    bubblesort_compare_avg /= N, bubblesort_shift_avg /= N, bubblesort_time_avg /= N;
    straightinsertsort_compare_avg /= N, straightinsertsort_shift_avg /= N, straightinsertsort_time_avg /= N;
    straightselectsort_compare_avg /= N, straightselectsort_shift_avg /= N, straightselectsort_time_avg /= N;
    shellsort_compare_avg /= N, shellsort_shift_avg /= N, shellsort_time_avg /= N;
    heapsort_compare_avg /= N, heapsort_shift_avg /= N, heapsort_time_avg /= N;
    mergesort_compare_avg /= N, mergesort_shift_avg /= N, mergesort_time_avg /= N;
    quicksort_compare_avg /= N, quicksort_shift_avg /= N, quicksort_time_avg /= N;
}


void testData::Stest()
{

}
