#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QDialog>
#include "DataBase.h"
namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr, NSData::User *_user = nullptr, QSqlDatabase *_db = nullptr);
    ~UserWindow();

private:
    Ui::UserWindow *ui;

    NSData::Users m_oUsers;
    NSData::Credits m_oCredits;
    NSData::Deposits m_oDeposits;

    QSqlDatabase *m_oDB;
};

#endif // USERWINDOW_H
