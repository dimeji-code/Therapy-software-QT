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
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *widget;
    QFrame *frame;
    QLabel *menuLabel;
    QListWidget *list;
    QPushButton *pushButton;
    QPushButton *mainMenu;
    QPushButton *back;
    QLabel *title;
    QPushButton *up;
    QPushButton *left;
    QPushButton *right;
    QPushButton *down;
    QLCDNumber *powerLevel;
    QPushButton *powerSelect;
    QPushButton *power;
    QProgressBar *progressBar;
    QLabel *label;
    QLCDNumber *battery;
    QPushButton *recharge;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(912, 712);
        MainWindow->setMinimumSize(QSize(912, 712));
        MainWindow->setMaximumSize(QSize(912, 712));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(200, 10, 581, 521));
        frame = new QFrame(widget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(60, 50, 461, 261));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        menuLabel = new QLabel(frame);
        menuLabel->setObjectName(QString::fromUtf8("menuLabel"));
        menuLabel->setGeometry(QRect(160, 10, 131, 20));
        list = new QListWidget(frame);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        new QListWidgetItem(list);
        QFont font;
        font.setItalic(false);
        font.setStrikeOut(false);
        QListWidgetItem *__qlistwidgetitem = new QListWidgetItem(list);
        __qlistwidgetitem->setFont(font);
        new QListWidgetItem(list);
        list->setObjectName(QString::fromUtf8("list"));
        list->setGeometry(QRect(100, 40, 256, 181));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::MinimumExpanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(list->sizePolicy().hasHeightForWidth());
        list->setSizePolicy(sizePolicy);
        pushButton = new QPushButton(frame);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(170, 220, 113, 32));
        mainMenu = new QPushButton(frame);
        mainMenu->setObjectName(QString::fromUtf8("mainMenu"));
        mainMenu->setGeometry(QRect(10, 40, 60, 60));
        back = new QPushButton(frame);
        back->setObjectName(QString::fromUtf8("back"));
        back->setGeometry(QRect(380, 40, 60, 60));
        title = new QLabel(widget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(50, 10, 501, 20));
        up = new QPushButton(widget);
        up->setObjectName(QString::fromUtf8("up"));
        up->setGeometry(QRect(260, 330, 60, 60));
        left = new QPushButton(widget);
        left->setObjectName(QString::fromUtf8("left"));
        left->setGeometry(QRect(200, 370, 60, 60));
        right = new QPushButton(widget);
        right->setObjectName(QString::fromUtf8("right"));
        right->setGeometry(QRect(320, 370, 60, 60));
        down = new QPushButton(widget);
        down->setObjectName(QString::fromUtf8("down"));
        down->setGeometry(QRect(260, 410, 60, 60));
        powerLevel = new QLCDNumber(widget);
        powerLevel->setObjectName(QString::fromUtf8("powerLevel"));
        powerLevel->setGeometry(QRect(460, 370, 81, 41));
        QFont font1;
        font1.setPointSize(16);
        powerLevel->setFont(font1);
        powerSelect = new QPushButton(widget);
        powerSelect->setObjectName(QString::fromUtf8("powerSelect"));
        powerSelect->setGeometry(QRect(480, 410, 51, 41));
        power = new QPushButton(centralwidget);
        power->setObjectName(QString::fromUtf8("power"));
        power->setGeometry(QRect(10, 60, 121, 101));
        power->setMinimumSize(QSize(121, 61));
        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QString::fromUtf8("progressBar"));
        progressBar->setGeometry(QRect(10, 610, 901, 20));
        progressBar->setValue(24);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(760, 630, 71, 21));
        battery = new QLCDNumber(centralwidget);
        battery->setObjectName(QString::fromUtf8("battery"));
        battery->setGeometry(QRect(830, 630, 51, 21));
        recharge = new QPushButton(centralwidget);
        recharge->setObjectName(QString::fromUtf8("recharge"));
        recharge->setGeometry(QRect(20, 630, 171, 32));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 912, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        menuLabel->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; vertical-align:sub;\">MAIN MENU</span></p></body></html>", nullptr));

        const bool __sortingEnabled = list->isSortingEnabled();
        list->setSortingEnabled(false);
        QListWidgetItem *___qlistwidgetitem = list->item(0);
        ___qlistwidgetitem->setText(QApplication::translate("MainWindow", "Programs", nullptr));
        QListWidgetItem *___qlistwidgetitem1 = list->item(1);
        ___qlistwidgetitem1->setText(QApplication::translate("MainWindow", "Frequency", nullptr));
        QListWidgetItem *___qlistwidgetitem2 = list->item(2);
        ___qlistwidgetitem2->setText(QApplication::translate("MainWindow", "Med", nullptr));
        QListWidgetItem *___qlistwidgetitem3 = list->item(3);
        ___qlistwidgetitem3->setText(QApplication::translate("MainWindow", "Baby Doctor", nullptr));
        QListWidgetItem *___qlistwidgetitem4 = list->item(4);
        ___qlistwidgetitem4->setText(QApplication::translate("MainWindow", "Children", nullptr));
        QListWidgetItem *___qlistwidgetitem5 = list->item(5);
        ___qlistwidgetitem5->setText(QApplication::translate("MainWindow", "Settings", nullptr));
        list->setSortingEnabled(__sortingEnabled);

        pushButton->setText(QApplication::translate("MainWindow", "SELECT", nullptr));
#ifndef QT_NO_TOOLTIP
        mainMenu->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Go to Main Menu</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        mainMenu->setText(QString());
#ifndef QT_NO_TOOLTIP
        back->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Previous Options</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        back->setText(QString());
        title->setText(QApplication::translate("MainWindow", "<html><head/><body><p align=\"center\"><span style=\" font-size:18pt; font-weight:600; vertical-align:super;\">dEnAs EleCtRic tHErApY</span></p></body></html>", nullptr));
        up->setText(QString());
#ifndef QT_NO_TOOLTIP
        left->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Reduce Power </p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        left->setText(QString());
#ifndef QT_NO_TOOLTIP
        right->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Increase Power</p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        right->setText(QString());
        down->setText(QString());
#ifndef QT_NO_TOOLTIP
        powerLevel->setToolTip(QApplication::translate("MainWindow", "<html><head/><body><p>Treatment Power<br/></p></body></html>", nullptr));
#endif // QT_NO_TOOLTIP
        powerSelect->setText(QApplication::translate("MainWindow", "OK", nullptr));
        power->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Battery % :", nullptr));
        recharge->setText(QApplication::translate("MainWindow", "RECHARGE : OFF", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
