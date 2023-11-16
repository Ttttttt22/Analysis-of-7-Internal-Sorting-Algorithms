#include "widget.h"
#include "ui_widget.h"
#include "sort.h"
#include "sortTest.h"
#include "testdata.h"
#include <QDebug>
#include<string.h>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    checkBoxGroup = new QButtonGroup(this);
    checkBoxGroup->addButton(this->ui->getrandarry_newCheckBox, 1);
    checkBoxGroup->addButton(this->ui->getrandarry_oldCheckBox, 2);
    checkBoxGroup->addButton(this->ui->getSequentialArryCheckBox, 3);
    ui->getrandarry_newCheckBox->setCheckState(Qt::Checked);//数组生成，强制三选一

    ui->ResultTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    //ui->ResultTableView->horizontalHeader()->setStyleSheet("QHeaderView::section{background:skyblue;color: black;}");
    //ui->ResultTableView->resizeColumnsToContents();
    //ui->ResultTableView->resizeRowsToContents();

    //ui->ResultTableView->resize(490, 240);

    model = new QStandardItemModel;

    ui->ResultTableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    model->setColumnCount(3);
    this->ui->ResultTableView->setModel(model);
    this->model->setHorizontalHeaderItem(0, new QStandardItem("compare"));
    this->model->setHorizontalHeaderItem(1, new QStandardItem("shift"));
    this->model->setHorizontalHeaderItem(2, new QStandardItem("time"));

    this->ui->ResultTableView->setColumnWidth(0, 100);    //设置列的宽度
    this->ui->ResultTableView->setColumnWidth(1, 100);
    this->ui->ResultTableView->setColumnWidth(2, 100);
    this->ui->ResultTableView->setColumnWidth(3, 100);

    model->setRowCount(7);
    model->setHeaderData(0,Qt::Vertical, "bubble");
    model->setHeaderData(1,Qt::Vertical, "straightinsert");
    model->setHeaderData(2,Qt::Vertical, "straightselect");
    model->setHeaderData(3,Qt::Vertical, "shell");
    model->setHeaderData(4,Qt::Vertical, "heap");
    model->setHeaderData(5,Qt::Vertical, "merge");
    model->setHeaderData(6,Qt::Vertical, "quick");

    ui->ResultPlainTextEdit->setReadOnly(true);

}

void Widget::on_startPushButton_clicked()
{
    qDebug()<<"startPushButtonClicked";
    int lvalue = this->ui->lvalueSpinBox->text().toInt();
    int rvalue = this->ui->rvalueSpinBox->text().toInt();
    int time = this->ui->timeSpinBox->text().toInt();
    int N = this->ui->AmountSpinBox->text().toInt();
    QMessageBox msgbox(this);
    if(rvalue < lvalue)
    {
        msgbox.setText("rvalue smaller than lvalue");
        msgbox.exec();
        return;
    }
    if(time < 1)
    {
        msgbox.setText("time can not be zero");
        msgbox.exec();
        return;
    }
    if(N < 1)
    {
        msgbox.setText("amount can not be zero");
        msgbox.exec();
        return;
    }
//    msgbox.setText(this->ui->lvalueSpinBox->text());
//    msgbox.exec();


    this->ui->ResultTableView->clearSpans();
    this->ui->ResultPlainTextEdit->clear();
    delete [] array;
    delete [] backup;
    delete tdata;
    if(tdata)
        tdata->~testData();


    array = new int [N];
    backup = new int [N];


    tdata = new testData(time);
    //tdata->show_QDebug();

    qDebug()<<"lvalue: "<<lvalue<<" rvalue:"<<rvalue<<" time:"<<time<<" switch:"<<this->checkBoxGroup->checkedId()<<" N:"<<N;

    for(int i = 0; i < time; i ++)
    {
        switch (this->checkBoxGroup->checkedId()) {
        case 1:
            getrandarry_new(backup, N, lvalue, rvalue);
            break;
        case 2:
            getrandarry_old(backup, N, lvalue, rvalue);
            break;
        case 3:
            getSequentialArry(backup, N);
            break;
        default:
            break;
        }
        QString s = nullptr;
        for(int j = 0; j < N; j++)
            s += QString::number(backup[j]) + " ";
        s += '\n';
        ui->ResultPlainTextEdit->appendPlainText(s);

        copyarray(array, backup, N);
        bubblesort(array, N, tdata->bubblesort_compare[i], tdata->bubblesort_shift[i], tdata->bubblesort_time[i]);
        copyarray(array, backup, N);
        straightinsertsort(array, N, tdata->straightinsertsort_compare[i], tdata->straightinsertsort_shift[i], tdata->straightinsertsort_time[i]);
        copyarray(array, backup, N);
        straightselectsort(array, N, tdata->straightselectsort_compare[i], tdata->straightselectsort_shift[i], tdata->straightselectsort_time[i]);
        copyarray(array, backup, N);
        shellsort(array, N, tdata->shellsort_compare[i], tdata->shellsort_shift[i], tdata->shellsort_time[i]);
        copyarray(array, backup, N);
        heapsort(array, N, tdata->heapsort_compare[i], tdata->heapsort_shift[i], tdata->heapsort_time[i]);
        copyarray(array, backup, N);
        mergesort(array, 0, N, tdata->mergesort_compare[i], tdata->mergesort_shift[i], tdata->mergesort_time[i]);
        copyarray(array, backup, N);
        quicksort(array, 0, N, tdata->quicksort_compare[i], tdata->quicksort_shift[i], tdata->quicksort_time[i]);


    }
    tdata->calculateAvg();
    tdata->show_Listview(model);


    this->ui->ResultTableView->setModel(model);

    tdata->show_avg_QDebug();
}

void Widget::on_resetPushButton_clicked()
{
    qDebug()<<"resetPushButtonClicked";
    this->ui->ResultTableView->clearSpans();
    this->ui->ResultPlainTextEdit->clear();
    this->ui->timeSpinBox->clear();
    this->ui->AmountSpinBox->clear();
    this->ui->rvalueSpinBox->clear();
    this->ui->lvalueSpinBox->clear();
}

Widget::~Widget()
{
  delete ui;
}




