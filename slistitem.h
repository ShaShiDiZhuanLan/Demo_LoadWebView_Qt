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
#ifndef SLISTITEM_H
#define SLISTITEM_H

#include <QWidget>
#include <QTimer>
#include <QWebEngineView>

namespace Ui {
class SListItem;
}


class SListItem : public QWidget
{
    Q_OBJECT

public:
    explicit SListItem(QWidget *parent = 0);
    ~SListItem();

    void setOpenEnable(bool isEnable);
    void setData(QString name, QString url, QString timeNum, bool isOpen);
    QString isName();
    QString isTime();
    bool isOpen();
    QString isUrl();
    int isNum();
private slots:
    void on_checkBox_clicked();
private:
    void regExp_Time();//整型（只能输入数字）
    void load_WebView();
    void onTime();
private:
    Ui::SListItem *ui;

    int m_loadNum = 0;
    QWebEngineView* m_view = Q_NULLPTR;
    QTimer* m_timer = Q_NULLPTR;
};

#endif // SLISTITEM_H
