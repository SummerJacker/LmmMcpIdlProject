/********************************************************************************
** Form generated from reading UI file 'picturewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTUREWINDOW_H
#define UI_PICTUREWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_PictureWindow
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *pictureLabel;

    void setupUi(QDialog *PictureWindow)
    {
        if (PictureWindow->objectName().isEmpty())
            PictureWindow->setObjectName(QString::fromUtf8("PictureWindow"));
        PictureWindow->resize(400, 300);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PictureWindow->sizePolicy().hasHeightForWidth());
        PictureWindow->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(PictureWindow);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        groupBox = new QGroupBox(PictureWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        pictureLabel = new QLabel(groupBox);
        pictureLabel->setObjectName(QString::fromUtf8("pictureLabel"));

        gridLayout->addWidget(pictureLabel, 0, 0, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(PictureWindow);

        QMetaObject::connectSlotsByName(PictureWindow);
    } // setupUi

    void retranslateUi(QDialog *PictureWindow)
    {
        PictureWindow->setWindowTitle(QApplication::translate("PictureWindow", "Dialog", nullptr));
        groupBox->setTitle(QString());
        pictureLabel->setText(QApplication::translate("PictureWindow", "\345\233\276\347\211\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PictureWindow: public Ui_PictureWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTUREWINDOW_H
