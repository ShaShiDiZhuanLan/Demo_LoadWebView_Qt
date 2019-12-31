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
#include <QApplication>

int main(int argc, char *argv[])
{
    QString libPath = "./";
    QCoreApplication::addLibraryPath(libPath);

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
