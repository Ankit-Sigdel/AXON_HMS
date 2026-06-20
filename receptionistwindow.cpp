#include "receptionistwindow.h"
#include "ui_receptionistwindow.h"

receptionistwindow::receptionistwindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::receptionistwindow)
{
    ui->setupUi(this);
}

receptionistwindow::~receptionistwindow()
{
    delete ui;
}
