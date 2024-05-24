#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, NSData::User *_user, QSqlDatabase *_db)
    : QDialog(parent)
    , ui(new Ui::UserWindow)
    , m_oDB(_db)
{
    ui->setupUi(this);
    ui->AdminPasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->AdminPasswordLineEdit->hide();
    ui->Password->hide();

    user = _user;

    m_oUsers = NSData::Users(_db);
    m_oUsers.SetDate();
    m_oCredits = NSData::Credits(_db);
    m_oCredits.SetDate();
    m_oDeposits = NSData::Deposits(_db);
    m_oDeposits.SetDate();

    ui->WelcomeLabel->setText("Welcome " + _user->Name);
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
        int monthLost  = (m_oCredits.GetDate().sliced(0, 4).toInt() - credit->ContractDate.sliced(0, 4).toInt()) * 12 +
                        m_oCredits.GetDate().sliced(5, 2).toInt() - credit->ContractDate.sliced(5, 2).toInt() - credit->MonthPaid;
        if(monthLost > 0)
        {
            ui->ErrorPayLabel->setText(QString::number(monthLost) + " month not payed!");
            user->Rating -= 0.1 * monthLost / credit->Time;
            m_oUsers.resetData(*user);
        }
    }
    else
        credit = nullptr;

    deposit = new NSData::Deposit(0);
    *deposit = m_oDeposits.Get(_user->ID);
    if (deposit->CustomerID != 0)
    {
        int monthLost  = (m_oDeposits.GetDate().sliced(0, 4).toInt() - deposit->ContractDate.sliced(0, 4).toInt()) * 12 +
                        m_oDeposits.GetDate().sliced(5, 2).toInt() - deposit->ContractDate.sliced(5, 2).toInt() - deposit->MonthPaid;
        for (int i = 0; i < monthLost; i++)
        {
            deposit->Amount += deposit->Amount * deposit->Rate / 1200;
            deposit->MonthPaid++;
        }
        m_oDeposits.resetData(*deposit);
        if (deposit->Time == deposit->MonthPaid)
        {
            user->Balance += deposit->Amount;
            m_oDeposits.Close(*deposit);
        }
        else
        {
            setDeposit(*deposit);
        }
    }
    else
        deposit = nullptr;

    ui->BalanceLabel->setText(QString::number(_user->Balance, 'f', 0));
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
    model->setItem(1, 0, new QStandardItem(QString::number(_deposit.Time - _deposit.MonthPaid)));
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
    deposit->MonthPaid = deposit->Time;
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
    credit->MonthPaid = credit->Time;
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    m_oUsers.resetData(*user);
    m_oCredits.Close(*credit);
    ui->ErrorPayLabel->setText("");
    QStandardItemModel *model = qobject_cast<QStandardItemModel*>(ui->CreditView->model());
    if (model) {
        model->removeRows(0, model->rowCount());
    }
}


void UserWindow::on_MonthlyPayButton_clicked()
{
    if (user->Balance < (credit->AllAmount / credit->Time  + credit->Amount * credit->Rate / 1200))
    {
        ui->ErrorPayLabel->setText("Insufficient funds!");
        return;
    }

    user->Balance -= (credit->AllAmount / credit->Time  + credit->Amount * credit->Rate / 1200);
    m_oUsers.resetData(*user);
    ui->BalanceLabel->setText(QString::number(user->Balance, 'f', 0));
    credit->Amount -= credit->AllAmount / credit->Time;
    credit->MonthPaid += 1;
    if (credit->MonthPaid == credit->Time)
    {
        on_PayAllButton_clicked();
        return;
    }
    m_oCredits.resetData(*credit);
    int monthLost  = (m_oCredits.GetDate().sliced(0, 4).toInt() - credit->ContractDate.sliced(0, 4).toInt()) * 12 +
                    m_oCredits.GetDate().sliced(5, 2).toInt() - credit->ContractDate.sliced(5, 2).toInt() - credit->MonthPaid;
    if(monthLost > 0)
    {
        ui->ErrorPayLabel->setText(QString::number(monthLost) + " not payed!");
        user->Rating -= 0.1 * monthLost / credit->Time;
        m_oUsers.resetData(*user);
    }
    else
        ui->ErrorPayLabel->setText("");
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
    credit = new NSData::Credit(newcredit);
    credit->ContractDate = m_oCredits.GetDate();
    ui->ErrorCreditLabel->setText("");
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
    deposit = new NSData::Deposit(newdeposit);
    deposit->ContractDate = m_oDeposits.GetDate();
    ui->ErrorDepositLabel->setText("");
}


void UserWindow::on_pushButton_clicked()
{
    ui->AdminPasswordLineEdit->show();
    ui->Password->show();
}


void UserWindow::on_LoginAdmin_clicked()
{
    QSqlQuery query = QSqlQuery(*m_oDB);
    query.exec("SELECT password FROM Users WHERE ID = 1");
    query.first();
    if (HashPassword1(ui->AdminPasswordLineEdit->text()) == query.value(0).toString())
    {
        AdministratorWindow window(nullptr, m_oDB);
        window.setModal(true);
        window.exec();
    }
}

