#include "administratorwindow.h"
#include "ui_administratorwindow.h"

AdministratorWindow::AdministratorWindow(QWidget *parent, QSqlDatabase *_db)
    : QDialog(parent)
    , ui(new Ui::AdministratorWindow)
    , m_oDB(_db)
{
    ui->setupUi(this);
    m_oModelUsers = new QSqlTableModel(nullptr, *m_oDB);
    m_oModelCredits = new QSqlTableModel(nullptr, *m_oDB);
    m_oModelDeposits = new QSqlTableModel(nullptr, *m_oDB);
    m_oModelBank = new QSqlTableModel(nullptr, *m_oDB);
    SetDB();
}

AdministratorWindow::~AdministratorWindow()
{
    delete ui;
}

void AdministratorWindow::SetDB()
{
    m_oModelUsers->setTable("users");
    m_oModelUsers->select();
    ui->UserTableView->setModel(m_oModelUsers);
    ui->UserTableView->show();
    m_oModelCredits->setTable("credits");
    m_oModelCredits->select();
    ui->CreditTableView->setModel(m_oModelCredits);
    ui->CreditTableView->show();
    m_oModelDeposits->setTable("deposits");
    m_oModelDeposits->select();
    ui->DepositTableView->setModel(m_oModelDeposits);
    ui->DepositTableView->show();
    m_oModelBank->setTable("bank");
    m_oModelBank->select();
    ui->BankTableView->setModel(m_oModelBank);
    ui->BankTableView->show();
}

void AdministratorWindow::on_UpdateButton_clicked()
{
    SetDB();
}

