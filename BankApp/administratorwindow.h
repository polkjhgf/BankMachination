#ifndef ADMINISTRATORWINDOW_H
#define ADMINISTRATORWINDOW_H

#include <QDialog>
#include <QCryptographicHash>
#include "DataBase.h"

namespace Ui {
class AdministratorWindow;
}

class AdministratorWindow : public QDialog
{
    Q_OBJECT

public:
    explicit AdministratorWindow(QWidget *parent = nullptr, QSqlDatabase* _db = nullptr);
    ~AdministratorWindow();

private slots:
    void on_UpdateButton_clicked();
    void SetDB();
private:
    Ui::AdministratorWindow *ui;
    QSqlDatabase *m_oDB;
    QSqlTableModel *m_oModelUsers;
    QSqlTableModel *m_oModelCredits;
    QSqlTableModel *m_oModelDeposits;
    QSqlTableModel *m_oModelBank;
};

#endif // ADMINISTRATORWINDOW_H
