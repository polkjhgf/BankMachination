/********************************************************************************
** Form generated from reading UI file 'administratorwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATORWINDOW_H
#define UI_ADMINISTRATORWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>

QT_BEGIN_NAMESPACE

class Ui_AdministratorWindow
{
public:
    QTableView *UserTableView;
    QTableView *CreditTableView;
    QTableView *DepositTableView;
    QTableView *BankTableView;
    QPushButton *UpdateButton;

    void setupUi(QDialog *AdministratorWindow)
    {
        if (AdministratorWindow->objectName().isEmpty())
            AdministratorWindow->setObjectName("AdministratorWindow");
        AdministratorWindow->resize(1207, 660);
        AdministratorWindow->setStyleSheet(QString::fromUtf8("background-color:  #4ea5ff;"));
        UserTableView = new QTableView(AdministratorWindow);
        UserTableView->setObjectName("UserTableView");
        UserTableView->setGeometry(QRect(20, 60, 741, 192));
        UserTableView->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white"));
        CreditTableView = new QTableView(AdministratorWindow);
        CreditTableView->setObjectName("CreditTableView");
        CreditTableView->setGeometry(QRect(20, 320, 551, 192));
        CreditTableView->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        DepositTableView = new QTableView(AdministratorWindow);
        DepositTableView->setObjectName("DepositTableView");
        DepositTableView->setGeometry(QRect(590, 320, 601, 192));
        DepositTableView->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        BankTableView = new QTableView(AdministratorWindow);
        BankTableView->setObjectName("BankTableView");
        BankTableView->setGeometry(QRect(780, 60, 411, 191));
        BankTableView->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color: white;"));
        UpdateButton = new QPushButton(AdministratorWindow);
        UpdateButton->setObjectName("UpdateButton");
        UpdateButton->setGeometry(QRect(440, 620, 291, 24));
        UpdateButton->setStyleSheet(QString::fromUtf8("color: black;\n"
"background-color:  white;"));

        retranslateUi(AdministratorWindow);

        QMetaObject::connectSlotsByName(AdministratorWindow);
    } // setupUi

    void retranslateUi(QDialog *AdministratorWindow)
    {
        AdministratorWindow->setWindowTitle(QCoreApplication::translate("AdministratorWindow", "Dialog", nullptr));
        UpdateButton->setText(QCoreApplication::translate("AdministratorWindow", "Update", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AdministratorWindow: public Ui_AdministratorWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATORWINDOW_H
