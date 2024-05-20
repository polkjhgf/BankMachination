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
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
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
    QLabel *label_9;
    QWidget *page_2;
    QLabel *label;
    QTableView *CreditView;
    QPushButton *PayAllButton;
    QPushButton *MonthlyPayButton;
    QSlider *TimeSlider;
    QSlider *RateSlider;
    QSlider *AmountSlider;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *TimeLabel;
    QLabel *RateLabel;
    QLabel *AmountLabel;
    QPushButton *TakeCreditButton;
    QLabel *ErrorCreditLabel;
    QLabel *ErrorPayLabel;
    QWidget *page_3;
    QLabel *label_5;
    QTableView *DepositView;
    QPushButton *CloseDepositButton;
    QSlider *TimeSlider_2;
    QSlider *RateSlider_2;
    QSlider *AmountSlider_2;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *TimeLabel_2;
    QLabel *RateLabel_2;
    QLabel *AmountLabel_2;
    QPushButton *TakeDepositButton;
    QLabel *ErrorDepositLabel;
    QLabel *WelcomeLabel;

    void setupUi(QDialog *UserWindow)
    {
        if (UserWindow->objectName().isEmpty())
            UserWindow->setObjectName("UserWindow");
        UserWindow->resize(600, 400);
        centralwidget = new QWidget(UserWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setGeometry(QRect(0, 0, 601, 440));
        centralwidget->setStyleSheet(QString::fromUtf8("background-color: #052C6E;"));
        CreditButton = new QPushButton(centralwidget);
        CreditButton->setObjectName("CreditButton");
        CreditButton->setGeometry(QRect(0, 350, 200, 50));
        QFont font;
        font.setPointSize(14);
        CreditButton->setFont(font);
        CreditButton->setStyleSheet(QString::fromUtf8("color: white;\n"
"\n"
""));
        MainWindowButton = new QPushButton(centralwidget);
        MainWindowButton->setObjectName("MainWindowButton");
        MainWindowButton->setGeometry(QRect(200, 350, 200, 50));
        MainWindowButton->setFont(font);
        MainWindowButton->setStyleSheet(QString::fromUtf8("color: white;\n"
"\n"
""));
        DepositButton = new QPushButton(centralwidget);
        DepositButton->setObjectName("DepositButton");
        DepositButton->setGeometry(QRect(400, 350, 200, 50));
        DepositButton->setFont(font);
        DepositButton->setStyleSheet(QString::fromUtf8("color: white;\n"
"\n"
""));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName("stackedWidget");
        stackedWidget->setGeometry(QRect(0, 40, 601, 311));
        stackedWidget->setStyleSheet(QString::fromUtf8("background-color:  #4ea5ff;"));
        page = new QWidget();
        page->setObjectName("page");
        BalanceLabel = new QLabel(page);
        BalanceLabel->setObjectName("BalanceLabel");
        BalanceLabel->setGeometry(QRect(220, 80, 161, 21));
        BalanceLabel->setStyleSheet(QString::fromUtf8("color: white;"));
        label_9 = new QLabel(page);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(91, 80, 121, 20));
        label_9->setStyleSheet(QString::fromUtf8("color: white;"));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        label = new QLabel(page_2);
        label->setObjectName("label");
        label->setGeometry(QRect(30, 20, 49, 16));
        QFont font1;
        font1.setPointSize(12);
        label->setFont(font1);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        CreditView = new QTableView(page_2);
        CreditView->setObjectName("CreditView");
        CreditView->setGeometry(QRect(20, 40, 421, 110));
        CreditView->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;"));
        PayAllButton = new QPushButton(page_2);
        PayAllButton->setObjectName("PayAllButton");
        PayAllButton->setGeometry(QRect(40, 160, 80, 24));
        PayAllButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"text-color: blue;"));
        MonthlyPayButton = new QPushButton(page_2);
        MonthlyPayButton->setObjectName("MonthlyPayButton");
        MonthlyPayButton->setGeometry(QRect(160, 160, 80, 24));
        MonthlyPayButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"text-color: blue;"));
        TimeSlider = new QSlider(page_2);
        TimeSlider->setObjectName("TimeSlider");
        TimeSlider->setGeometry(QRect(80, 210, 160, 16));
        TimeSlider->setOrientation(Qt::Horizontal);
        RateSlider = new QSlider(page_2);
        RateSlider->setObjectName("RateSlider");
        RateSlider->setGeometry(QRect(80, 230, 160, 16));
        RateSlider->setOrientation(Qt::Horizontal);
        AmountSlider = new QSlider(page_2);
        AmountSlider->setObjectName("AmountSlider");
        AmountSlider->setGeometry(QRect(80, 250, 160, 16));
        AmountSlider->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(page_2);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(30, 210, 49, 16));
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_3 = new QLabel(page_2);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 230, 49, 16));
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        label_4 = new QLabel(page_2);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(30, 250, 49, 16));
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        TimeLabel = new QLabel(page_2);
        TimeLabel->setObjectName("TimeLabel");
        TimeLabel->setGeometry(QRect(250, 210, 49, 16));
        TimeLabel->setStyleSheet(QString::fromUtf8("color: white;"));
        RateLabel = new QLabel(page_2);
        RateLabel->setObjectName("RateLabel");
        RateLabel->setGeometry(QRect(250, 230, 49, 16));
        RateLabel->setStyleSheet(QString::fromUtf8("color: white;"));
        AmountLabel = new QLabel(page_2);
        AmountLabel->setObjectName("AmountLabel");
        AmountLabel->setGeometry(QRect(250, 250, 49, 16));
        AmountLabel->setStyleSheet(QString::fromUtf8("color: white;"));
        TakeCreditButton = new QPushButton(page_2);
        TakeCreditButton->setObjectName("TakeCreditButton");
        TakeCreditButton->setGeometry(QRect(370, 210, 80, 24));
        TakeCreditButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"text-color: blue;"));
        ErrorCreditLabel = new QLabel(page_2);
        ErrorCreditLabel->setObjectName("ErrorCreditLabel");
        ErrorCreditLabel->setGeometry(QRect(380, 250, 151, 16));
        ErrorCreditLabel->setStyleSheet(QString::fromUtf8("color: #BF3030;"));
        ErrorPayLabel = new QLabel(page_2);
        ErrorPayLabel->setObjectName("ErrorPayLabel");
        ErrorPayLabel->setGeometry(QRect(290, 160, 141, 16));
        ErrorPayLabel->setStyleSheet(QString::fromUtf8("color: #BF3030;\n"
""));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName("page_3");
        label_5 = new QLabel(page_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 20, 71, 21));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        DepositView = new QTableView(page_3);
        DepositView->setObjectName("DepositView");
        DepositView->setGeometry(QRect(30, 50, 421, 100));
        DepositView->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;"));
        CloseDepositButton = new QPushButton(page_3);
        CloseDepositButton->setObjectName("CloseDepositButton");
        CloseDepositButton->setGeometry(QRect(80, 160, 80, 24));
        CloseDepositButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"text-color: blue;"));
        TimeSlider_2 = new QSlider(page_3);
        TimeSlider_2->setObjectName("TimeSlider_2");
        TimeSlider_2->setGeometry(QRect(70, 200, 160, 16));
        TimeSlider_2->setOrientation(Qt::Horizontal);
        RateSlider_2 = new QSlider(page_3);
        RateSlider_2->setObjectName("RateSlider_2");
        RateSlider_2->setGeometry(QRect(70, 220, 160, 16));
        RateSlider_2->setOrientation(Qt::Horizontal);
        AmountSlider_2 = new QSlider(page_3);
        AmountSlider_2->setObjectName("AmountSlider_2");
        AmountSlider_2->setGeometry(QRect(70, 240, 160, 16));
        AmountSlider_2->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(page_3);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(20, 200, 49, 16));
        label_6->setStyleSheet(QString::fromUtf8("color: white; "));
        label_7 = new QLabel(page_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(20, 220, 49, 16));
        label_7->setStyleSheet(QString::fromUtf8("color: white; "));
        label_8 = new QLabel(page_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(20, 240, 49, 16));
        label_8->setStyleSheet(QString::fromUtf8("color: white; "));
        TimeLabel_2 = new QLabel(page_3);
        TimeLabel_2->setObjectName("TimeLabel_2");
        TimeLabel_2->setGeometry(QRect(240, 200, 49, 16));
        TimeLabel_2->setStyleSheet(QString::fromUtf8("color: white; "));
        RateLabel_2 = new QLabel(page_3);
        RateLabel_2->setObjectName("RateLabel_2");
        RateLabel_2->setGeometry(QRect(240, 220, 49, 16));
        RateLabel_2->setStyleSheet(QString::fromUtf8("color: white; "));
        AmountLabel_2 = new QLabel(page_3);
        AmountLabel_2->setObjectName("AmountLabel_2");
        AmountLabel_2->setGeometry(QRect(240, 240, 49, 16));
        AmountLabel_2->setStyleSheet(QString::fromUtf8("color: white; "));
        TakeDepositButton = new QPushButton(page_3);
        TakeDepositButton->setObjectName("TakeDepositButton");
        TakeDepositButton->setGeometry(QRect(370, 200, 80, 24));
        TakeDepositButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"text-color: blue;"));
        ErrorDepositLabel = new QLabel(page_3);
        ErrorDepositLabel->setObjectName("ErrorDepositLabel");
        ErrorDepositLabel->setGeometry(QRect(370, 240, 161, 16));
        ErrorDepositLabel->setStyleSheet(QString::fromUtf8("color: #BF3030;"));
        stackedWidget->addWidget(page_3);
        WelcomeLabel = new QLabel(centralwidget);
        WelcomeLabel->setObjectName("WelcomeLabel");
        WelcomeLabel->setGeometry(QRect(10, 0, 241, 31));
        QFont font2;
        font2.setPointSize(20);
        WelcomeLabel->setFont(font2);
        WelcomeLabel->setStyleSheet(QString::fromUtf8("color: white;\n"
""));

        retranslateUi(UserWindow);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(UserWindow);
    } // setupUi

    void retranslateUi(QDialog *UserWindow)
    {
        UserWindow->setWindowTitle(QCoreApplication::translate("UserWindow", "MainWindow", nullptr));
        CreditButton->setText(QCoreApplication::translate("UserWindow", "Credit", nullptr));
        MainWindowButton->setText(QCoreApplication::translate("UserWindow", "Main Window", nullptr));
        DepositButton->setText(QCoreApplication::translate("UserWindow", "Deposit", nullptr));
        BalanceLabel->setText(QCoreApplication::translate("UserWindow", "Balance", nullptr));
        label_9->setText(QCoreApplication::translate("UserWindow", "Your BALANCE is ", nullptr));
        label->setText(QCoreApplication::translate("UserWindow", "Credit", nullptr));
        PayAllButton->setText(QCoreApplication::translate("UserWindow", "Pay all", nullptr));
        MonthlyPayButton->setText(QCoreApplication::translate("UserWindow", " Monthly pay", nullptr));
        label_2->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        label_3->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        label_4->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        TimeLabel->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        RateLabel->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        AmountLabel->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        TakeCreditButton->setText(QCoreApplication::translate("UserWindow", "Take Credit", nullptr));
        ErrorCreditLabel->setText(QString());
        ErrorPayLabel->setText(QString());
        label_5->setText(QCoreApplication::translate("UserWindow", "Deposit", nullptr));
        CloseDepositButton->setText(QCoreApplication::translate("UserWindow", "Close Deposit", nullptr));
        label_6->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        label_7->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        label_8->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        TimeLabel_2->setText(QCoreApplication::translate("UserWindow", "Time", nullptr));
        RateLabel_2->setText(QCoreApplication::translate("UserWindow", "Rate", nullptr));
        AmountLabel_2->setText(QCoreApplication::translate("UserWindow", "Amount", nullptr));
        TakeDepositButton->setText(QCoreApplication::translate("UserWindow", "Take Deposit", nullptr));
        ErrorDepositLabel->setText(QString());
        WelcomeLabel->setText(QCoreApplication::translate("UserWindow", "Welcome", nullptr));
    } // retranslateUi

};

namespace Ui {
    class UserWindow: public Ui_UserWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERWINDOW_H
