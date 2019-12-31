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
#include "slistitem.h"
#include "ui_slistitem.h"
#include <QRegExp>
#include <QValidator>
#include <QRegExpValidator>

SListItem::SListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SListItem)
{
    ui->setupUi(this);

    regExp_Time();

    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &SListItem::onTime);
    m_timer->start();
}

SListItem::~SListItem()
{
    delete ui;
}

void SListItem::setOpenEnable(bool isEnable)
{
    ui->checkBox->setEnabled(isEnable);
}

void SListItem::setData(QString name, QString url, QString timeNum, bool isOpen)
{
    if (ui->lineEdit_time->text().toInt() < 500) {
        ui->lineEdit_time->setText("500");
    }
    ui->lineEdit_name->setText(name);
    ui->lineEdit_url->setText(url);
    ui->lineEdit_time->setText(timeNum);
    ui->checkBox->setChecked(isOpen);
}

QString SListItem::isName()
{
    return ui->lineEdit_name->text();
}

QString SListItem::isTime()
{
    return ui->lineEdit_time->text();
}

bool SListItem::isOpen()
{
    return ui->checkBox->isChecked();
}

QString SListItem::isUrl()
{
    return ui->lineEdit_url->text();
}

int SListItem::isNum()
{
    return m_loadNum;
}

void SListItem::regExp_Time()
{
    //整型（只能输入数字）
    QRegExp regx("[0-9]+$");
    QValidator *validator = new QRegExpValidator(regx, ui->lineEdit_time);
    ui->lineEdit_time->setValidator(validator);
}

void SListItem::load_WebView()
{
    if(m_view) {
        m_view->deleteLater();
        m_view = Q_NULLPTR;
    }
    m_view = new QWebEngineView(this);
    m_view->load(QUrl(ui->lineEdit_url->text()));
    m_view->hide();

    m_loadNum++;
    if(m_loadNum > 9999999) {
        m_loadNum = 0;
    }
    ui->label_num->setText(QString::number(m_loadNum));
}

void SListItem::onTime()
{
    if (ui->lineEdit_time->text().toInt() < 500) {
        ui->lineEdit_time->setText("500");
    }
    m_timer->setInterval(ui->lineEdit_time->text().toInt());
    if(ui->checkBox->isChecked()) {
        load_WebView();
    }
}

void SListItem::on_checkBox_clicked()
{
    if (ui->lineEdit_time->text().toInt() < 500) {
        ui->lineEdit_time->setText("500");
    }
    bool isUnCheck = !(ui->checkBox->isChecked());
    ui->lineEdit_time->setEnabled(isUnCheck);
    ui->lineEdit_url->setEnabled(isUnCheck);
}
