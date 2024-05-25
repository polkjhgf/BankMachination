/********************************************************************************
** Form generated from reading UI file 'registrationwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTRATIONWINDOW_H
#define UI_REGISTRATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RegistrationWindow
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *NameLineEdit;
    QLabel *label_3;
    QLineEdit *LastnameLineEdit;
    QLabel *label_4;
    QLineEdit *LoginLineEdit;
    QLabel *label_5;
    QLineEdit *PasswordLineEdit;
    QLabel *label_6;
    QLineEdit *ConfirmPasswordLineEdit;
    QPushButton *RegistrationButton;
    QLabel *LoginErrorLabel;
    QLabel *PasswordErrorLabel;

    void setupUi(QDialog *RegistrationWindow)
    {
        if (RegistrationWindow->objectName().isEmpty())
            RegistrationWindow->setObjectName("RegistrationWindow");
        RegistrationWindow->resize(300, 489);
        RegistrationWindow->setStyleSheet(QString::fromUtf8("background-color:  #4ea5ff;"));
        label = new QLabel(RegistrationWindow);
        label->setObjectName("label");
        label->setGeometry(QRect(40, 10, 211, 56));
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font.setPointSize(30);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("color: white;\n"
"text-font: segoe;"));
        label_2 = new QLabel(RegistrationWindow);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 90, 49, 16));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe MDL2 Assets")});
        font1.setPointSize(11);
        label_2->setFont(font1);
        label_2->setStyleSheet(QString::fromUtf8("color: white;\n"
"text-font: segoe;"));
        NameLineEdit = new QLineEdit(RegistrationWindow);
        NameLineEdit->setObjectName("NameLineEdit");
        NameLineEdit->setGeometry(QRect(10, 110, 281, 24));
        NameLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        label_3 = new QLabel(RegistrationWindow);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(40, 150, 71, 16));
        label_3->setFont(font1);
        label_3->setStyleSheet(QString::fromUtf8("color: white;\n"
"text-font: segoe;"));
        LastnameLineEdit = new QLineEdit(RegistrationWindow);
        LastnameLineEdit->setObjectName("LastnameLineEdit");
        LastnameLineEdit->setGeometry(QRect(10, 170, 281, 24));
        LastnameLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        label_4 = new QLabel(RegistrationWindow);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(40, 210, 58, 21));
        label_4->setFont(font1);
        label_4->setStyleSheet(QString::fromUtf8("color: white;"));
        LoginLineEdit = new QLineEdit(RegistrationWindow);
        LoginLineEdit->setObjectName("LoginLineEdit");
        LoginLineEdit->setGeometry(QRect(10, 230, 281, 24));
        LoginLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        label_5 = new QLabel(RegistrationWindow);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(40, 280, 81, 16));
        label_5->setFont(font1);
        label_5->setStyleSheet(QString::fromUtf8("color: white;"));
        PasswordLineEdit = new QLineEdit(RegistrationWindow);
        PasswordLineEdit->setObjectName("PasswordLineEdit");
        PasswordLineEdit->setGeometry(QRect(10, 300, 281, 24));
        PasswordLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        label_6 = new QLabel(RegistrationWindow);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 330, 121, 16));
        label_6->setFont(font1);
        label_6->setStyleSheet(QString::fromUtf8("color: white;\n"
""));
        ConfirmPasswordLineEdit = new QLineEdit(RegistrationWindow);
        ConfirmPasswordLineEdit->setObjectName("ConfirmPasswordLineEdit");
        ConfirmPasswordLineEdit->setGeometry(QRect(10, 350, 281, 24));
        ConfirmPasswordLineEdit->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"color: black;"));
        RegistrationButton = new QPushButton(RegistrationWindow);
        RegistrationButton->setObjectName("RegistrationButton");
        RegistrationButton->setGeometry(QRect(10, 410, 281, 24));
        RegistrationButton->setStyleSheet(QString::fromUtf8("color: 4e598c;\n"
"background-color: white;\n"
"border-radius: 5px;\n"
"color: black;"));
        LoginErrorLabel = new QLabel(RegistrationWindow);
        LoginErrorLabel->setObjectName("LoginErrorLabel");
        LoginErrorLabel->setGeometry(QRect(40, 260, 221, 16));
        LoginErrorLabel->setStyleSheet(QString::fromUtf8("color: red;\n"
""));
        PasswordErrorLabel = new QLabel(RegistrationWindow);
        PasswordErrorLabel->setObjectName("PasswordErrorLabel");
        PasswordErrorLabel->setGeometry(QRect(40, 380, 221, 16));
        PasswordErrorLabel->setStyleSheet(QString::fromUtf8("color: red;"));

        retranslateUi(RegistrationWindow);

        QMetaObject::connectSlotsByName(RegistrationWindow);
    } // setupUi

    void retranslateUi(QDialog *RegistrationWindow)
    {
        RegistrationWindow->setWindowTitle(QCoreApplication::translate("RegistrationWindow", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("RegistrationWindow", "Registration", nullptr));
        label_2->setText(QCoreApplication::translate("RegistrationWindow", "Name", nullptr));
        label_3->setText(QCoreApplication::translate("RegistrationWindow", "Lastname", nullptr));
        label_4->setText(QCoreApplication::translate("RegistrationWindow", "Login", nullptr));
        label_5->setText(QCoreApplication::translate("RegistrationWindow", "Password", nullptr));
        label_6->setText(QCoreApplication::translate("RegistrationWindow", "Confirm Password", nullptr));
        RegistrationButton->setText(QCoreApplication::translate("RegistrationWindow", "registration", nullptr));
        LoginErrorLabel->setText(QString());
        PasswordErrorLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class RegistrationWindow: public Ui_RegistrationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTRATIONWINDOW_H
