#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include "DataBase.h"

namespace Ui {
class RegistrationWindow;
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr, QSqlDatabase *_db = nullptr);
    ~RegistrationWindow();

private slots:
    void on_pushButton_clicked();

private:
    NSData::Users m_oUsers;

    Ui::RegistrationWindow *ui;
};

#endif // REGISTRATIONWINDOW_H
