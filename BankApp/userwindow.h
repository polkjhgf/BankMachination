#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QTableView>
#include <QStandardItemModel>
#include "DataBase.h"
#include "Definition.h"

namespace Ui {
class UserWindow;
}

class UserWindow : public QDialog
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr, NSData::User *_user = nullptr, QSqlDatabase *_db = nullptr);
    ~UserWindow();

private slots:


    void setCredit(const NSData::Credit& _credit);

    void setDeposit(const NSData::Deposit& _deposit);

    void on_MainWindowButton_clicked();

    void on_CreditButton_clicked();

    void on_DepositButton_clicked();

    void on_CloseDepositButton_clicked();

    void on_PayAllButton_clicked();

    void on_MonthlyPayButton_clicked();

    void on_TimeSlider_2_sliderMoved(int position);

    void on_RateSlider_2_sliderMoved(int position);

    void on_AmountSlider_2_sliderMoved(int position);

    void on_TimeSlider_sliderMoved(int position);

    void on_RateSlider_sliderMoved(int position);

    void on_AmountSlider_sliderMoved(int position);

    void on_TakeCreditButton_clicked();

    void on_TakeDepositButton_clicked();

private:
    Ui::UserWindow *ui;

    NSData::User *user;
    NSData::Credit *credit;
    NSData::Deposit *deposit;

    NSData::Users m_oUsers;
    NSData::Credits m_oCredits;
    NSData::Deposits m_oDeposits;

    QSqlDatabase *m_oDB;
};

#endif // USERWINDOW_H
