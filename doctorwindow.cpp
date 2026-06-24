#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include "mainwindow.h"
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QDateTime>

doctorwindow::doctorwindow(const QString &employeeName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AXON_DOCTOR),
    currentUserName(employeeName) // Initialize your member variable
{
    ui->setupUi(this);

    //Clock
    timer= new QTimer(this);
    connect(timer, &QTimer::timeout, this, &doctorwindow::updateDateTime);
    updateDateTime();
    timer->start(1000);

    //SideBar Navigation
    connect(ui->overviewBtn, &QPushButton::clicked, this, &doctorwindow::switchPage);
    connect(ui->patientlistBtn, &QPushButton::clicked, this, &doctorwindow::switchPage);
    connect(ui->scheduleBtn, &QPushButton::clicked, this, &doctorwindow::switchPage);
    ui->stackedWidget->setCurrentIndex(0);

    //Logout Menu
    QMenu *logoutMenu = new QMenu(this);
    logoutMenu->addAction("  Logout  ", this, &doctorwindow::logout);
    ui->logoutBtn->setMenu(logoutMenu);

    logoutMenu->setStyleSheet(
        "QMenu {"
            "background-color: #ffffff ;"
            "color:#2c3e50;"
            "border: 1 px solid #dce1e6;"
            "border-radius: 10 px;"
            "padding: 8 px;"
            "width: 120 px;"
            "height:50 px;"
        "}"
        "QMenu::item {"
            "padding: 0 px;"
            "border-radius: 6 px;"
            "margin: 0 px;"
            "font-size: 13 px;"
            "color: 2c3e50;"
            "width: 100 px;"
            "height: 40 px;"
            "text-align:center;"
        "}"
        "QMenu::item:selected {"
            "background-color: #e8f0fe;"
            "color: #1a73e8;"
        "}"
        );


    doctorBackend = new Doctor();

    this->setWindowTitle("AXON-HMS: Doctor Dashboard");
}

doctorwindow::~doctorwindow()
{
    delete doctorBackend;
    delete ui;
}

void doctorwindow::updateDateTime()
{
    QDateTime now=QDateTime::currentDateTime();
    QString text=now.toString("ddd MMM d yyyy, hh:mm AP");
    ui->label_clock->setText(text);
}

void doctorwindow::switchPage()
{
    QPushButton *btn = qobject_cast<QPushButton *>(sender());
    if(btn==ui->overviewBtn)
    {
        ui->stackedWidget->setCurrentIndex(0);
    }

    else if(btn==ui->patientlistBtn)
    {
        ui->stackedWidget->setCurrentIndex(1);
    }

    else if(btn==ui->scheduleBtn)
    {
        ui->stackedWidget->setCurrentIndex(2);
    }
}

void doctorwindow::logout()
{
    this->close();
    MainWindow *login =new MainWindow();
    login->show();
}