#include "registrationwindow.h"
#include "ui_registrationwindow.h"

RegistrationWindow::RegistrationWindow(QWidget *parent, QSqlDatabase *_db)
    : QDialog(parent)
    , ui(new Ui::RegistrationWindow)
{
    ui->setupUi(this);
    m_oUsers = NSData::Users(_db);
    m_oUsers.GetDate();
    ui->PasswordLineEdit->setEchoMode(QLineEdit::Password);
    ui->ConfirmPasswordLineEdit->setEchoMode(QLineEdit::Password);
}

RegistrationWindow::~RegistrationWindow()
{
    delete ui;
}

void RegistrationWindow::on_RegistrationButton_clicked()
{
    if (!m_oUsers.Check(ui->LoginLineEdit->text()))
    {
        ui->LoginErrorLabel->setText("This login already used!");
        return;
    }

    if (ui->PasswordLineEdit->text() != ui->ConfirmPasswordLineEdit->text())
    {
        ui->PasswordErrorLabel->setText("Passwords do not match!");
        return;
    }

    NSData::User newuser(ui->NameLineEdit->text(),
                         ui->LastnameLineEdit->text(),
                         ui->LoginLineEdit->text(),
                         HashPassword(ui->PasswordLineEdit->text()),
                         100000);
    m_oUsers.Set(newuser);
    this->~RegistrationWindow();
}

