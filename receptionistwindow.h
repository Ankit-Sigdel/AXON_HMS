#ifndef RECEPTIONISTWINDOW_H
#define RECEPTIONISTWINDOW_H

#include <QWidget>

namespace Ui {
class receptionistwindow;
}

class receptionistwindow : public QWidget
{
    Q_OBJECT

public:
    explicit receptionistwindow(QWidget *parent = nullptr);
    ~receptionistwindow();

private:
    Ui::receptionistwindow *ui;
};

#endif // RECEPTIONISTWINDOW_H
