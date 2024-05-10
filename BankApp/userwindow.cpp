#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, NSData::User *_user, QSqlDatabase *_db)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
    , m_oDB(_db)
{
    ui->setupUi(this);

    m_oUsers = NSData::Users(_db);
    m_oCredits = NSData::Credits(_db);
    m_oDeposits = NSData::Deposits(_db);

    ui->WelcomeLabel->setText("Welcome " + _user->Name);
    ui->BalanceLabel->setText(QString::number(_user->Balance));

    NSData::Credit credit = m_oCredits.Get(_user->ID);
    QStandardItemModel *model = new QStandardItemModel(2, 5);
    model->setItem(0, 0, new QStandardItem("Time"));
    model->setItem(0, 1, new QStandardItem("Rate"));
    model->setItem(0, 2, new QStandardItem("Full payment"));
    model->setItem(0, 3, new QStandardItem("Monthly payment"));
    model->setItem(0, 4, new QStandardItem("Month paid"));
    model->setItem(1, 0, new QStandardItem(QString::number()))
}

UserWindow::~UserWindow()
{
    delete ui;
}
