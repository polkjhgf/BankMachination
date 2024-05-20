#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, NSData::User *_user, QSqlDatabase *_db)
    : QDialog(parent)
    , ui(new Ui::UserWindow)
    , m_oDB(_db)
{
    ui->setupUi(this);

    user = _user;

    m_oUsers = NSData::Users(_db);
    m_oUsers.GetDate();
    m_oCredits = NSData::Credits(_db);
    m_oCredits.GetDate();
    m_oDeposits = NSData::Deposits(_db);
    m_oDeposits.GetDate();

    ui->WelcomeLabel->setText("Welcome " + _user->Name);
    ui->BalanceLabel->setText(QString::number(_user->Balance, 'f', 0));
    ui->AmountLabel_2->setText(QString::number(MINDEPOSIT));
    ui->AmountLabel->setText(QString::number(MINCREDIT));
    ui->TimeLabel_2->setText(QString::number(MINTIMEDEPOSIT * 12));
    ui->TimeLabel->setText(QString::number(MINTIMECREDIT * 12));
    ui->RateLabel_2->setText(QString::number(MINPROCDEPOSIT));
    ui->RateLabel->setText(QString::number(MINPROCCREDIT));

    credit = new NSData::Credit(0);
    *credit = m_oCredits.Get(_user->ID);
    if (credit->CustomerID != 0)
    {
        setCredit(*credit);
    }
    else
        credit = nullptr;

    deposit = new NSData::Deposit(0);
    *deposit = m_oDeposits.Get(_user->ID);
    if (deposit->CustomerID != 0)
    {
        deposit->Amount += deposit->Amount * deposit->Rate / 1200;
        deposit->Time -= 1;
        m_oDeposits.resetData(*deposit);
        setDeposit(*deposit);
    }
    else
        deposit = nullptr;

    ui->stackedWidget->setCurrentIndex(0);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::setCredit(const NSData::Credit& _credit)
{
    QStandardItemModel *model = new QStandardItemModel(2, 5);
    model->setItem(0, 0, new QStandardItem("Time last"));
    model->setItem(0, 1, new QStandardItem("Rate"));
    model->setItem(0, 2, new QStandardItem("Full payment"));
    model->setItem(0, 3, new QStandardItem("Monthly payment"));
    model->setItem(0, 4, new QStandardItem("Month paid"));
    model->setItem(1, 0, new QStandardItem(QString::number(_credit.Time)));
    model->setItem(1, 1, new QStandardItem(QString::number(_credit.Rate)));
    model->setItem(1, 2, new QStandardItem(QString::number(_credit.Amount)));
    model->setItem(1, 3, new QStandardItem(QString::number(_credit.Amount / (_credit.Time - _credit.MonthPaid)  + _credit.Amount * _credit.Rate / 12)));
    model->setItem(1, 4, new QStandardItem(QString::number(_credit.MonthPaid)));

    ui->CreditView->setModel(model);
}

void UserWindow::setDeposit(const NSData::Deposit& _deposit)
{
    QStandardItemModel *model = new QStandardItemModel(2, 3);
    model->setItem(0, 0, new QStandardItem("Time last"));
    model->setItem(0, 1, new QStandardItem("Rate"));
    model->setItem(0, 2, new QStandardItem("Amount"));
    model->setItem(1, 0, new QStandardItem(QString::number(_deposit.Time)));
    model->setItem(1, 1, new QStandardItem(QString::number(_deposit.Rate)));
    model->setItem(1, 2, new QStandardItem(QString::number(_deposit.Amount)));

    ui->DepositView->setModel(model);
}

void UserWindow::on_MainWindowButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void UserWindow::on_CreditButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void UserWindow::on_DepositButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void UserWindow::on_CloseDepositButton_clicked()
{
    user->Balance += deposit->Amount;
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    m_oUsers.resetData(*user);
    m_oDeposits.Close(*deposit);
    deposit = nullptr;
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->DepositView->model());
    if (model) {
        model->removeRows(0, model->rowCount());
    }
}


void UserWindow::on_PayAllButton_clicked()
{
    if (user->Balance < credit->Amount)
    {
        ui->ErrorPayLabel->setText("Insufficient funds!");
        return;
    }

    user->Balance -= credit->Amount;
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    m_oUsers.resetData(*user);
    m_oCredits.Close(*credit);
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->CreditView->model());
    if (model) {
        model->removeRows(0, model->rowCount());
    }
}


void UserWindow::on_MonthlyPayButton_clicked()
{
    if (user->Balance < (credit->Amount / (credit->Time - credit->MonthPaid)  + credit->Amount * credit->Rate / 1200))
    {
        ui->ErrorPayLabel->setText("Insufficient funds!");
        return;
    }

    user->Balance -= (credit->Amount / (credit->Time - credit->MonthPaid)  + credit->Amount * credit->Rate / 1200);
    m_oUsers.resetData(*user);
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    credit->Amount -= credit->Amount / (credit->Time - credit->MonthPaid);
    credit->MonthPaid += 1;
    credit->Time -= 1;
    m_oCredits.resetData(*credit);
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->CreditView->model());
    if (model) {
        model->removeRows(0, model->rowCount());
    }
    setCredit(*credit);
}


void UserWindow::on_TimeSlider_2_sliderMoved(int position)
{
    ui->TimeLabel_2->setText(QString::number((MINTIMEDEPOSIT + position * (MAXTIMEDEPOSIT - MINTIMEDEPOSIT) / 99) * 12));
}


void UserWindow::on_RateSlider_2_sliderMoved(int position)
{
    ui->RateLabel_2->setText(QString::number(MINPROCDEPOSIT + position * (MAXPROCDEPOSIT - MINPROCDEPOSIT) / 99));
}


void UserWindow::on_AmountSlider_2_sliderMoved(int position)
{
    ui->AmountLabel_2->setText(QString::number(MINDEPOSIT + position * (MAXDEPOSIT - MINDEPOSIT) / 99));
}


void UserWindow::on_TimeSlider_sliderMoved(int position)
{
    ui->TimeLabel->setText(QString::number((MINTIMECREDIT + position * (MAXTIMECREDIT - MINTIMECREDIT) / 99) * 12));
}


void UserWindow::on_RateSlider_sliderMoved(int position)
{
    ui->RateLabel->setText(QString::number(MINPROCCREDIT + position * (MAXPROCCREDIT - MINPROCCREDIT) / 99));
}


void UserWindow::on_AmountSlider_sliderMoved(int position)
{
    ui->AmountLabel->setText(QString::number(MINCREDIT + position * (MAXCREDIT - MINCREDIT) / 99));
}


void UserWindow::on_TakeCreditButton_clicked()
{
    NSData::Credit newcredit = NSData::Credit(user->ID, ui->RateLabel->text().toFloat(), ui->TimeLabel->text().toInt(), ui->AmountLabel->text().toInt());
    if(!m_oCredits.Check(newcredit))
    {
        ui->ErrorCreditLabel->setText("Credit denied!");
        return;
    }
    user->Balance += newcredit.Amount;
    m_oUsers.resetData(*user);
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    m_oCredits.Set(newcredit);
    setCredit(newcredit);
    credit = &newcredit;
}


void UserWindow::on_TakeDepositButton_clicked()
{
    NSData::Deposit newdeposit = NSData::Deposit(user->ID, ui->RateLabel_2->text().toFloat(), ui->TimeLabel_2->text().toInt(), ui->AmountLabel_2->text().toInt());
    if (newdeposit.Amount > user->Balance)
    {
        ui->ErrorDepositLabel->setText("Insufficient funds!");
        return;
    }
    if(!m_oDeposits.Check(newdeposit))
    {
        ui->ErrorDepositLabel->setText("Deposit denied!");
        return;
    }
    user->Balance -= newdeposit.Amount;
    m_oUsers.resetData(*user);
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    m_oDeposits.Set(newdeposit);
    setDeposit(newdeposit);
    deposit = &newdeposit;
}

