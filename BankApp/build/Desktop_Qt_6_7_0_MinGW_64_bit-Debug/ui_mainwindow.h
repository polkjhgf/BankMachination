/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *LoginLineEdit;
    QLineEdit *PasswordLineEdit;
    QFrame *frame;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *PasswordErrorLabel;
    QLabel *LoginErrorLabel;
    QPushButton *LoginButton;
    QLabel *label_4;
    QPushButton *RegistrationButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(700, 500);
        QFont font;
        font.setFamilies({QString::fromUtf8("Times New Roman")});
        font.setPointSize(16);
        font.setItalic(false);
        font.setKerning(false);
        MainWindow->setFont(font);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setStyleSheet(QString::fromUtf8("background-color: white;"));
        MainWindow->setIconSize(QSize(24, 24));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        LoginLineEdit = new QLineEdit(centralwidget);
        LoginLineEdit->setObjectName("LoginLineEdit");
        LoginLineEdit->setGeometry(QRect(270, 170, 251, 24));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: black;"));
        PasswordLineEdit = new QLineEdit(centralwidget);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        PasswordLineEdit->setGeometry(QRect(270, 220, 251, 24));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("border-radius: 5px;\n"
"color: black;"));
        frame = new QFrame(centralwidget);
        frame->setObjectName("frame");
        frame->setEnabled(true);
        frame->setGeometry(QRect(170, 20, 361, 441));
        frame->setAutoFillBackground(false);
        frame->setStyleSheet(QString::fromUtf8("background-color:  #4ea5ff;\n"
"border-radius: 10;\n"
"border-color: white;"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setEnabled(false);
        label->setGeometry(QRect(130, 10, 111, 52));
        QPalette palette;
        QBrush brush(QColor(255, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(78, 165, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(255, 255, 255, 128));
        brush2.setStyle(Qt::SolidPattern);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush2);
#endif
        label->setPalette(palette);
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font1.setPointSize(32);
        font1.setBold(false);
        font1.setItalic(false);
        font1.setKerning(false);
        label->setFont(font1);
        label->setAutoFillBackground(false);
        label->setStyleSheet(QString::fromUtf8("color: white;"));
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 150, 49, 24));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font2.setPointSize(16);
        font2.setItalic(false);
        label_2->setFont(font2);
        label_2->setStyleSheet(QString::fromUtf8("color: white;"));
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 200, 88, 25));
        label_3->setFont(font2);
        label_3->setStyleSheet(QString::fromUtf8("color: white;"));
        PasswordErrorLabel = new QLabel(frame);
        PasswordErrorLabel->setObjectName("PasswordErrorLabel");
        PasswordErrorLabel->setGeometry(QRect(100, 230, 251, 16));
        QFont font3;
        font3.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font3.setPointSize(9);
        font3.setItalic(false);
        PasswordErrorLabel->setFont(font3);
        PasswordErrorLabel->setStyleSheet(QString::fromUtf8("color: #e54b4b;\n"
"text-font: sergoe;"));
        LoginErrorLabel = new QLabel(frame);
        LoginErrorLabel->setObjectName("LoginErrorLabel");
        LoginErrorLabel->setGeometry(QRect(100, 180, 251, 16));
        LoginErrorLabel->setFont(font3);
        LoginErrorLabel->setStyleSheet(QString::fromUtf8("color: #e54b4b;\n"
"text-font: sergoe"));
        LoginButton = new QPushButton(frame);
        LoginButton->setObjectName("LoginButton");
        LoginButton->setGeometry(QRect(10, 260, 341, 31));
        QFont font4;
        font4.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font4.setPointSize(12);
        font4.setItalic(false);
        font4.setKerning(false);
        LoginButton->setFont(font4);
        LoginButton->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border-radius: 5px;\n"
"color: black;"));
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 306, 191, 21));
        QFont font5;
        font5.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font5.setPointSize(12);
        font5.setItalic(false);
        label_4->setFont(font5);
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        RegistrationButton = new QPushButton(frame);
        RegistrationButton->setObjectName("RegistrationButton");
        RegistrationButton->setGeometry(QRect(260, 300, 86, 31));
        RegistrationButton->setFont(font4);
        RegistrationButton->setStyleSheet(QString::fromUtf8("color: white;"));
        MainWindow->setCentralWidget(centralwidget);
        frame->raise();
        LoginLineEdit->raise();
        PasswordLineEdit->raise();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Password", nullptr));
        PasswordErrorLabel->setText(QString());
        LoginErrorLabel->setText(QString());
        LoginButton->setText(QCoreApplication::translate("MainWindow", "Login", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "You don't have an account?", nullptr));
        RegistrationButton->setText(QCoreApplication::translate("MainWindow", "Registration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
