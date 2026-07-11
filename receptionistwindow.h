#ifndef RECEPTIONISTWINDOW_H
#define RECEPTIONISTWINDOW_H

#include <QWidget>
#include <QTimer>
#include <QDateTime>

QT_BEGIN_NAMESPACE
namespace Ui { class ReceptionistWindow; }
QT_END_NAMESPACE

class ReceptionistWindow : public QWidget
{
    Q_OBJECT

public:
    ReceptionistWindow(QWidget *parent = nullptr);
    ~ReceptionistWindow();

private slots:
    // Sidebar Navigation Buttons
    void onDashboardClicked();
    void onRegisterPatientClicked();
    void onScheduleClicked();
    void onBillingClicked();

    // Action Buttons
    void onViewAllAppointmentsClicked();
    void onClearFormClicked();
    void onSubmitRegistrationClicked();
    void updateDateTime();

private:
    Ui::ReceptionistWindow *ui;

    // Helper functions to keep code clean
    void setupConnections();
    void refreshDashboardData();
    void populateAppointmentsTable();
    void populateRecentPatientsTable();
    QTimer *dateTimeTimer;
};

#endif // RECEPTIONISTWINDOW_H