#include "doctorwindow.h"
#include "ui_doctorwindow.h"
#include <QDateTime>

doctorwindow::doctorwindow(const QString &employeeName, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AXON_DOCTOR),
    currentUserName(employeeName) // Initialize your member variable
{
    ui->setupUi(this);

    timer= new QTimer(this);
    connect(timer, &QTimer::timeout, this, &doctorwindow::updateDateTime);
    updateDateTime();
    timer->start(1000);

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