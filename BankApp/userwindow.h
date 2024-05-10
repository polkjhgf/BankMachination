#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "DataBase.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
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
