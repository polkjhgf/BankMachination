#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connect();
    m_oUsers = NSData::Users(m_oDB);
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Connect()
{
    m_oDB = new QSqlDatabase;
    *m_oDB = QSqlDatabase::addDatabase("QPSQL");
    m_oDB->setDatabaseName("postgres");
    m_oDB->setUserName("postgres");
    m_oDB->setPassword("12345678");
    m_oDB->open();
}

void MainWindow::on_LoginButton_clicked()
{
    if (m_oUsers.Check(ui->LoginLineEdit->text()))
    {
        ui->LoginErrorLabel->setText("Incorrect login!");
        return;
    }

    NSData::User user = m_oUsers.Get(ui->LoginLineEdit->text());

    QString pas = HashPassword(ui->PasswordLineEdit->text());

    if (HashPassword(ui->PasswordLineEdit->text()) != user.Password)
    {
        ui->PasswordErrorLabel->setText("IncorrectPassword!");
        return;
    }

    this->hide();
    UserWindow window(nullptr, &user, m_oDB);
    window.setModal(true);
    window.exec();
}


void MainWindow::on_RegistrationButton_clicked()
{
    RegistrationWindow window(nullptr, m_oDB);
    window.setModal(true);
    window.exec();
}

