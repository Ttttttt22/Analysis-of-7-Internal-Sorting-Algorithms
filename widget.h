#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QButtonGroup>
#include <QStandardItemModel>
#include <QStringListModel>
#include "testdata.h"
#include <QMessageBox>

typedef long long LL;

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_startPushButton_clicked();

    void on_resetPushButton_clicked();

private:
    Ui::Widget *ui;
    QButtonGroup *checkBoxGroup;
    QStandardItemModel *model;
    //QStringListModel *listModel;

//    LL bubblesort_compare = 0, bubblesort_shift = 0, bubblesort_time = 0;
//    LL straightinsertsort_compare = 0, straightinsertsort_shift = 0, straightinsertsort_time = 0;
//    LL straightselectsort_compare = 0, straightselectsort_shift = 0, straightselectsort_time = 0;
//    LL shellsort_compare = 0, shellsort_shift = 0, shellsort_time= 0;
//    LL heapsort_compare = 0, heapsort_shift = 0, heapsort_time = 0;
//    LL mergesort_compare = 0, mergesort_shift = 0, mergesort_time = 0;
//    LL quicksort_compare = 0, quicksort_shift = 0, quicksort_time = 0;

    int *array, *backup;
    testData *tdata;


};
#endif // WIDGET_H
