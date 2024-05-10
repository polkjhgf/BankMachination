#include "mainwindow.h"
#include "ui_mainwindow.h"

inline QString HashPassword(const QString& _password)
{
    QByteArray passwordData = _password.toUtf8();
    QByteArray hashedData = QCryptographicHash::hash(passwordData, QCryptographicHash::Sha256);
    return QString::fromLatin1(hashedData.toHex());
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Connect();
    m_oUsers = NSData::Users(&m_oDB);
    m_oCredits = NSData::Credits(&m_oDB);
    m_oDeposits = NSData::Deposits(&m_oDB);
}

MainWindow::~MainWindow()
{
    Disconnect();
    delete ui;
}
