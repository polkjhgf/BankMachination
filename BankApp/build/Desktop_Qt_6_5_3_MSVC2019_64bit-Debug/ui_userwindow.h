/********************************************************************************
** Form generated from reading UI file 'userwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERWINDOW_H
#define UI_USERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserWindow
{
public:
    QWidget *centralwidget;
    QPushButton *CreditButton;
    QPushButton *MainWindowButton;
    QPushButton *DepositButton;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *BalanceLabel;
    QLabel *WelcomeLabel;
    QWidget *page_2;
    QLabel *label;
    QTableView *CreditView;
    QPushButton *PayAllButton;
    QPushButton *MonthlyPayButton;
    QSlider *TimeSlider;
    QSlider *RateSlider;
    QSlider *mountSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *TimeLabel;
    QLabel *RateLabel;
    QLabel *AmountLabel;
    QPushButton *pushButton;
    QLabel *ErrorCreditLabel;
    QWidget *page_3;
    QPushButton *ExitButton;

    void setupUi(QMainWindow *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(600, 400);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        CreditButton = new QPushButton(centralwidget);
        CreditButton->setObjectName("CreditButton");
        CreditButton->setGeometry(QRect(0, 350, 200, 50));
        MainWindowButton = new QPushButton(centralwidget);
        MainWindowButton->setObjectName("MainWindowButton");
        MainWindowButton->setGeometry(QRect(200, 350, 200, 50));
        DepositButton = new QPushButton(centralwidget);
        DepositButton->setObjectName("DepositButton");
        DepositButton->setGeometry(QRect(400, 350, 200, 50));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 40, 601, 311));
        page = new QWidget();
        page->setObjectName("page");
        BalanceLabel = new QLabel(page);
        BalanceLabel->setObjectName("BalanceLabel");
        BalanceLabel->setGeometry(QRect(210, 70, 161, 111));
        WelcomeLabel = new QLabel(page);
        WelcomeLabel->setObjectName("WelcomeLabel");
        WelcomeLabel->setGeometry(QRect(20, 10, 181, 16));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 49, 16));
        CreditView = new QTableView(page_2);
        CreditView->setObjectName("CreditView");
        CreditView->setGeometry(QRect(20, 50, 421, 31));
        PayAllButton = new QPushButton(page_2);
        PayAllButton->setObjectName("PayAllButton");
        PayAllButton->setGeometry(QRect(40, 90, 80, 24));
        MonthlyPayButton = new QPushButton(page_2);
        MonthlyPayButton->setObjectName("MonthlyPayButton");
        MonthlyPayButton->setGeometry(QRect(160, 90, 80, 24));
        TimeSlider = new QSlider(page_2);
        TimeSlider->setObjectName("TimeSlider");
        TimeSlider->setGeometry(QRect(80, 160, 160, 16));
        TimeSlider->setOrientation(Qt::Horizontal);
        RateSlider = new QSlider(page_2);
        RateSlider->setObjectName("RateSlider");
        RateSlider->setGeometry(QRect(80, 190, 160, 16));
        RateSlider->setOrientation(Qt::Horizontal);
        mountSlider = new QSlider(page_2);
        mountSlider->setObjectName("mountSlider");
        mountSlider->setGeometry(QRect(80, 220, 160, 16));
        mountSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 160, 49, 16));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 190, 49, 16));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 220, 49, 16));
        TimeLabel = new QLabel(page_2);
        TimeLabel->setObjectName("TimeLabel");
        TimeLabel->setGeometry(QRect(250, 160, 49, 16));
        RateLabel = new QLabel(page_2);
        RateLabel->setObjectName("RateLabel");
        RateLabel->setGeometry(QRect(250, 190, 49, 16));
        AmountLabel = new QLabel(page_2);
        AmountLabel->setObjectName("AmountLabel");
        AmountLabel->setGeometry(QRect(250, 220, 49, 16));
        pushButton = new QPushButton(page_2);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(370, 170, 80, 24));
        ErrorCreditLabel = new QLabel(page_2);
        ErrorCreditLabel->setObjectName("ErrorCreditLabel");
        ErrorCreditLabel->setGeometry(QRect(380, 210, 49, 16));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        stackedWidget->addWidget(page_3);
        ExitButton = new QPushButton(centralwidget);
        ExitButton->setObjectName("ExitButton");
        ExitButton->setGeometry(QRect(510, 10, 80, 24));
        UserWindow->setCentralWidget(centralwidget);

        retranslateUi(UserWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        CreditButton->setText(QCoreApplication::translate("UserWindow", "Credit", nullptr));
        MainWindowButton->setText(QCoreApplication::translate("UserWindow", "Main Window", nullptr));
        DepositButton->setText(QCoreApplication::translate("UserWindow", "Deposit", nullptr));
        BalanceLabel->setText(QCoreApplication::translate("UserWindow", "Balance", nullptr));
        WelcomeLabel->setText(QCoreApplication::translate("UserWindow", "Welcome", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Credit", nullptr));
        PayAllButton->setText(QCoreApplication::translate("UserWindow", "Pay all", nullptr));
        MonthlyPayButton->setText(QCoreApplication::translate("UserWindow", " Monthly pay", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        TimeLabel->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        RateLabel->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        AmountLabel->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        pushButton->setText(QCoreApplication::translate("UserWindow", "Take Credit", nullptr));
        ErrorCreditLabel->setText(QCoreApplication::translate("UserWindow", "Error", nullptr));
        ExitButton->setText(QCoreApplication::translate("UserWindow", "exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
