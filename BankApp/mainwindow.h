#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QPixmap>
#include <QPalette>
#include <QLabel>
#include "registrationwindow.h"
#include "userwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Connect();

private slots:
    void on_LoginButton_clicked();

    void on_RegistrationButton_clicked();

private:
    NSData::Users m_oUsers;
    NSData::Credits m_oCredits;
    NSData::Deposits m_oDeposits;

    Ui::MainWindow *ui;
    QSqlDatabase *m_oDB;
};
#endif // MAINWINDOW_H
