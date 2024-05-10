#ifndef REGISTRATIONWINDOW_H
#define REGISTRATIONWINDOW_H

#include <QDialog>
#include <QCryptographicHash>
#include "DataBase.h"

namespace Ui {
class RegistrationWindow;
}

inline QString HashPassword(const QString& _password)
{
    QByteArray passwordData = _password.toUtf8();
    QByteArray hashedData = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);
    return QString::fromLatin1(hashedData.toHex());
}

class RegistrationWindow : public QDialog
{
    Q_OBJECT

public:
    explicit RegistrationWindow(QWidget *parent = nullptr, QSqlDatabase *_db = nullptr);
    ~RegistrationWindow();

private slots:


    void on_RegistrationButton_clicked();

private:
    NSData::Users m_oUsers;

    Ui::RegistrationWindow *ui;
};

#endif // REGISTRATIONWINDOW_H
