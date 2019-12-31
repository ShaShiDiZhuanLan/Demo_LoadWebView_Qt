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
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "slistitem.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_update_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
