#include "userwindow.h"
#include "ui_userwindow.h"

UserWindow::UserWindow(QWidget *parent, NSData::User *_user, QSqlDatabase *_db)
    : QDialog(parent)
    , ui(new Ui::UserWindow)
    , m_oDB(_db)
{
    ui->setupUi(this);

    m_oUsers = NSData::Users(_db);
    m_oCredits = NSData::Credits(_db);
    m_oDeposits = NSData::Deposits(_db);
}

UserWindow::~UserWindow()
{
    delete m_oDB;
    delete ui;
}
