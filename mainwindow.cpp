/*-------------------------------------------------
#
# Project created by QtCreator
# Author: 沙振宇
# CreateTime: 2019-02-26
# UpdateTime: 2019-12-31
# Info: Qt5Web浏览器，刷浏览量专用
# Url:https://shazhenyu.blog.csdn.net
# Github:https://github.com/ShaShiDiZhuanLan/Demo_LoadWebView_Qt
# Todo: 利用不同的IP去刷浏览量
#
#-------------------------------------------------*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SListItem* curItem = (SListItem*)ui->widget_ok;
    curItem->setOpenEnable(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    SListItem* listItem = new SListItem(ui->listWidget);
    QListWidgetItem *item = new QListWidgetItem(ui->listWidget);
    item->setSizeHint(QSize(ui->listWidget->width(),50));
    listItem->resize(ui->listWidget->width(),50);
    SListItem* curItem = (SListItem*)ui->widget_ok;
    listItem->setData(curItem->isName(),curItem->isUrl(),curItem->isTime(),curItem->isOpen());
    curItem->setData("","","",false);
    ui->listWidget->setItemWidget(item, listItem);
}

void MainWindow::on_pushButton_update_clicked()
{
    int totalNum = 0;
    for(int i = 0; i < ui->listWidget->count(); i++) {
        QListWidgetItem* item = ui->listWidget->item(i);
        SListItem* curItem = (SListItem*)(ui->listWidget->itemWidget(item));
        int num = curItem->isNum();
        totalNum += num;
    }
    ui->label_totalNum->setText(QString::number(totalNum));
    ui->label_urlNum->setText(QString::number(ui->listWidget->count()));
}
