/********************************************************************************
** Form generated from reading UI file 'dialogaddmedicine.ui'
**
** Created by: Qt User Interface Compiler version 6.3.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDMEDICINE_H
#define UI_DIALOGADDMEDICINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DialogAddMedicine
{
public:
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEdit;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QSpinBox *spinBox_2;
    QLabel *label_5;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;

    void setupUi(QDialog *DialogAddMedicine)
    {
        if (DialogAddMedicine->objectName().isEmpty())
            DialogAddMedicine->setObjectName(QString::fromUtf8("DialogAddMedicine"));
        DialogAddMedicine->resize(371, 289);
        formLayout = new QFormLayout(DialogAddMedicine);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label = new QLabel(DialogAddMedicine);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEdit = new QLineEdit(DialogAddMedicine);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEdit);

        label_2 = new QLabel(DialogAddMedicine);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        dateEdit = new QDateEdit(DialogAddMedicine);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));
        dateEdit->setCalendarPopup(true);

        formLayout->setWidget(1, QFormLayout::FieldRole, dateEdit);

        label_3 = new QLabel(DialogAddMedicine);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        spinBox = new QSpinBox(DialogAddMedicine);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBox);

        label_4 = new QLabel(DialogAddMedicine);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        spinBox_2 = new QSpinBox(DialogAddMedicine);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        formLayout->setWidget(3, QFormLayout::FieldRole, spinBox_2);

        label_5 = new QLabel(DialogAddMedicine);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        lineEdit_2 = new QLineEdit(DialogAddMedicine);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEdit_2);

        pushButton = new QPushButton(DialogAddMedicine);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        formLayout->setWidget(5, QFormLayout::FieldRole, pushButton);


        retranslateUi(DialogAddMedicine);

        QMetaObject::connectSlotsByName(DialogAddMedicine);
    } // setupUi

    void retranslateUi(QDialog *DialogAddMedicine)
    {
        DialogAddMedicine->setWindowTitle(QCoreApplication::translate("DialogAddMedicine", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("DialogAddMedicine", "Title", nullptr));
        label_2->setText(QCoreApplication::translate("DialogAddMedicine", "Date", nullptr));
        dateEdit->setDisplayFormat(QCoreApplication::translate("DialogAddMedicine", "yyyy-MM-dd", nullptr));
        label_3->setText(QCoreApplication::translate("DialogAddMedicine", "Term", nullptr));
        label_4->setText(QCoreApplication::translate("DialogAddMedicine", "Price", nullptr));
        label_5->setText(QCoreApplication::translate("DialogAddMedicine", "Country", nullptr));
        pushButton->setText(QCoreApplication::translate("DialogAddMedicine", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddMedicine: public Ui_DialogAddMedicine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDMEDICINE_H
