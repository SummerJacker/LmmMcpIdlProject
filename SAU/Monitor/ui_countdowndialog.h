/********************************************************************************
** Form generated from reading UI file 'countdowndialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COUNTDOWNDIALOG_H
#define UI_COUNTDOWNDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_CountDownDialog
{
public:
    QLabel *stateLabel;
    QGroupBox *groupBox;
    QLabel *label1;
    QLCDNumber *lcdNumber;
    QLabel *label2;

    void setupUi(QDialog *CountDownDialog)
    {
        if (CountDownDialog->objectName().isEmpty())
            CountDownDialog->setObjectName(QString::fromUtf8("CountDownDialog"));
        CountDownDialog->resize(320, 200);
        CountDownDialog->setMinimumSize(QSize(320, 200));
        CountDownDialog->setSizeIncrement(QSize(320, 200));
        stateLabel = new QLabel(CountDownDialog);
        stateLabel->setObjectName(QString::fromUtf8("stateLabel"));
        stateLabel->setGeometry(QRect(30, 20, 251, 81));
        QFont font;
        font.setPointSize(15);
        stateLabel->setFont(font);
        stateLabel->setFrameShape(QFrame::NoFrame);
        stateLabel->setFrameShadow(QFrame::Raised);
        stateLabel->setScaledContents(false);
        stateLabel->setAlignment(Qt::AlignCenter);
        stateLabel->setWordWrap(true);
        groupBox = new QGroupBox(CountDownDialog);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 110, 271, 81));
        label1 = new QLabel(groupBox);
        label1->setObjectName(QString::fromUtf8("label1"));
        label1->setGeometry(QRect(10, 10, 101, 61));
        QFont font1;
        font1.setPointSize(17);
        label1->setFont(font1);
        label1->setFrameShadow(QFrame::Raised);
        lcdNumber = new QLCDNumber(groupBox);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(120, 10, 91, 61));
        lcdNumber->setLayoutDirection(Qt::LeftToRight);
        lcdNumber->setFrameShape(QFrame::Box);
        lcdNumber->setFrameShadow(QFrame::Plain);
        lcdNumber->setSmallDecimalPoint(false);
        lcdNumber->setDigitCount(3);
        lcdNumber->setSegmentStyle(QLCDNumber::Filled);
        lcdNumber->setProperty("value", QVariant(0.000000000000000));
        label2 = new QLabel(groupBox);
        label2->setObjectName(QString::fromUtf8("label2"));
        label2->setGeometry(QRect(230, 10, 31, 61));
        label2->setFont(font1);
        label2->setFrameShadow(QFrame::Raised);

        retranslateUi(CountDownDialog);

        QMetaObject::connectSlotsByName(CountDownDialog);
    } // setupUi

    void retranslateUi(QDialog *CountDownDialog)
    {
        CountDownDialog->setWindowTitle(QApplication::translate("CountDownDialog", "Dialog", nullptr));
        stateLabel->setText(QString());
        groupBox->setTitle(QString());
        label1->setText(QApplication::translate("CountDownDialog", "\345\200\222\350\256\241\346\227\266:", nullptr));
        label2->setText(QApplication::translate("CountDownDialog", "\347\247\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CountDownDialog: public Ui_CountDownDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COUNTDOWNDIALOG_H
