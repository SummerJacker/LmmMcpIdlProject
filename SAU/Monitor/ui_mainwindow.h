/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *unitsStateGroupBox;
    QListView *unitsStateListView;
    QGroupBox *fireRelativeGroupBox;
    QListView *fireEventListView;
    QGroupBox *firePicGroupBox;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QLabel *firePictureLabel;
    QLabel *label;
    QComboBox *firePicsListComboBox;
    QLabel *firePicTimestampLabel;
    QLabel *fireEventIDLabel;
    QLabel *label_2;
    QPushButton *newWinPushButton;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QGroupBox *trapGroupBox;
    QListView *trapListView;
    QGroupBox *msgGroupBox;
    QTextEdit *msgOutput;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1824, 900);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        unitsStateGroupBox = new QGroupBox(centralWidget);
        unitsStateGroupBox->setObjectName(QString::fromUtf8("unitsStateGroupBox"));
        unitsStateGroupBox->setGeometry(QRect(30, 40, 441, 501));
        unitsStateListView = new QListView(unitsStateGroupBox);
        unitsStateListView->setObjectName(QString::fromUtf8("unitsStateListView"));
        unitsStateListView->setGeometry(QRect(20, 20, 401, 461));
        fireRelativeGroupBox = new QGroupBox(centralWidget);
        fireRelativeGroupBox->setObjectName(QString::fromUtf8("fireRelativeGroupBox"));
        fireRelativeGroupBox->setGeometry(QRect(860, 40, 921, 791));
        fireEventListView = new QListView(fireRelativeGroupBox);
        fireEventListView->setObjectName(QString::fromUtf8("fireEventListView"));
        fireEventListView->setGeometry(QRect(690, 30, 211, 741));
        fireEventListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        firePicGroupBox = new QGroupBox(fireRelativeGroupBox);
        firePicGroupBox->setObjectName(QString::fromUtf8("firePicGroupBox"));
        firePicGroupBox->setGeometry(QRect(20, 19, 651, 661));
        scrollArea = new QScrollArea(firePicGroupBox);
        scrollArea->setObjectName(QString::fromUtf8("scrollArea"));
        scrollArea->setGeometry(QRect(20, 30, 611, 611));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QString::fromUtf8("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 609, 609));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        firePictureLabel = new QLabel(scrollAreaWidgetContents);
        firePictureLabel->setObjectName(QString::fromUtf8("firePictureLabel"));
        firePictureLabel->setAlignment(Qt::AlignCenter);

        gridLayout->addWidget(firePictureLabel, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);
        label = new QLabel(fireRelativeGroupBox);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(370, 720, 81, 21));
        label->setScaledContents(false);
        label->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label->setWordWrap(false);
        firePicsListComboBox = new QComboBox(fireRelativeGroupBox);
        firePicsListComboBox->setObjectName(QString::fromUtf8("firePicsListComboBox"));
        firePicsListComboBox->setGeometry(QRect(180, 720, 161, 22));
        firePicTimestampLabel = new QLabel(fireRelativeGroupBox);
        firePicTimestampLabel->setObjectName(QString::fromUtf8("firePicTimestampLabel"));
        firePicTimestampLabel->setGeometry(QRect(450, 720, 171, 21));
        firePicTimestampLabel->setScaledContents(false);
        firePicTimestampLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        firePicTimestampLabel->setWordWrap(false);
        fireEventIDLabel = new QLabel(fireRelativeGroupBox);
        fireEventIDLabel->setObjectName(QString::fromUtf8("fireEventIDLabel"));
        fireEventIDLabel->setGeometry(QRect(260, 690, 171, 21));
        fireEventIDLabel->setScaledContents(false);
        fireEventIDLabel->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        fireEventIDLabel->setWordWrap(false);
        label_2 = new QLabel(fireRelativeGroupBox);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(60, 720, 121, 21));
        label_2->setScaledContents(false);
        label_2->setAlignment(Qt::AlignHCenter|Qt::AlignTop);
        label_2->setWordWrap(false);
        newWinPushButton = new QPushButton(fireRelativeGroupBox);
        newWinPushButton->setObjectName(QString::fromUtf8("newWinPushButton"));
        newWinPushButton->setGeometry(QRect(70, 750, 93, 28));
        pushButton = new QPushButton(fireRelativeGroupBox);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(180, 750, 93, 28));
        pushButton_2 = new QPushButton(fireRelativeGroupBox);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(290, 750, 93, 28));
        trapGroupBox = new QGroupBox(centralWidget);
        trapGroupBox->setObjectName(QString::fromUtf8("trapGroupBox"));
        trapGroupBox->setGeometry(QRect(530, 40, 271, 501));
        trapListView = new QListView(trapGroupBox);
        trapListView->setObjectName(QString::fromUtf8("trapListView"));
        trapListView->setGeometry(QRect(20, 20, 231, 461));
        trapListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        trapListView->setProperty("isWrapping", QVariant(false));
        trapListView->setViewMode(QListView::ListMode);
        trapListView->setWordWrap(false);
        trapListView->setSelectionRectVisible(false);
        msgGroupBox = new QGroupBox(centralWidget);
        msgGroupBox->setObjectName(QString::fromUtf8("msgGroupBox"));
        msgGroupBox->setGeometry(QRect(30, 560, 771, 271));
        msgOutput = new QTextEdit(msgGroupBox);
        msgOutput->setObjectName(QString::fromUtf8("msgOutput"));
        msgOutput->setGeometry(QRect(20, 30, 731, 221));
        msgOutput->setReadOnly(true);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1824, 26));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        unitsStateGroupBox->setTitle(QApplication::translate("MainWindow", "\345\215\225\345\205\203\347\212\266\346\200\201\351\235\242\346\235\277", nullptr));
        fireRelativeGroupBox->setTitle(QApplication::translate("MainWindow", "\347\201\253\346\203\205\345\244\204\347\220\206\351\235\242\346\235\277", nullptr));
        firePicGroupBox->setTitle(QApplication::translate("MainWindow", "\347\201\253\346\203\205\345\233\276\347\211\207", nullptr));
        firePictureLabel->setText(QApplication::translate("MainWindow", "\347\201\253\346\203\205\345\233\276\347\211\207\346\230\276\347\244\272\345\214\272\345\237\237", nullptr));
        label->setText(QApplication::translate("MainWindow", "\346\213\215\346\221\204\346\227\266\351\227\264\357\274\232", nullptr));
        firePicTimestampLabel->setText(QApplication::translate("MainWindow", "\346\227\266\351\227\264\346\210\263\346\225\260\345\200\274", nullptr));
        fireEventIDLabel->setText(QApplication::translate("MainWindow", "\347\201\253\346\203\205ID", nullptr));
        label_2->setText(QApplication::translate("MainWindow", "\347\201\253\346\203\205\347\233\270\345\205\263\345\233\276\347\211\207\357\274\232", nullptr));
        newWinPushButton->setText(QApplication::translate("MainWindow", "\347\252\227\345\217\243\344\270\255\346\211\223\345\274\200", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\345\217\246\345\255\230\344\270\272", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Test", nullptr));
        trapGroupBox->setTitle(QApplication::translate("MainWindow", "\351\231\267\351\230\261\351\235\242\346\235\277", nullptr));
        msgGroupBox->setTitle(QApplication::translate("MainWindow", "\346\266\210\346\201\257\350\276\223\345\207\272\351\235\242\346\235\277", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
