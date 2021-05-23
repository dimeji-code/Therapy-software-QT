/********************************************************************************
** Form generated from reading UI file 'activetreatment.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ACTIVETREATMENT_H
#define UI_ACTIVETREATMENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QOpenGLWidget>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ActiveTreatment
{
public:
    QLCDNumber *lcdNumber;
    QOpenGLWidget *openGLWidget;
    QFrame *line;
    QFrame *line_2;
    QLabel *label_2;
    QPushButton *skinTouch;
    QLCDNumber *therapyTime;
    QLabel *label;

    void setupUi(QDialog *ActiveTreatment)
    {
        if (ActiveTreatment->objectName().isEmpty())
            ActiveTreatment->setObjectName(QString::fromUtf8("ActiveTreatment"));
        ActiveTreatment->resize(480, 364);
        lcdNumber = new QLCDNumber(ActiveTreatment);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));
        lcdNumber->setGeometry(QRect(190, 10, 101, 51));
        openGLWidget = new QOpenGLWidget(ActiveTreatment);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(90, 70, 300, 230));
        line = new QFrame(ActiveTreatment);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(0, 290, 481, 20));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(ActiveTreatment);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(80, 70, 20, 291));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        label_2 = new QLabel(ActiveTreatment);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(160, 320, 111, 31));
        label_2->setAlignment(Qt::AlignCenter);
        skinTouch = new QPushButton(ActiveTreatment);
        skinTouch->setObjectName(QString::fromUtf8("skinTouch"));
        skinTouch->setGeometry(QRect(390, 320, 75, 31));
        therapyTime = new QLCDNumber(ActiveTreatment);
        therapyTime->setObjectName(QString::fromUtf8("therapyTime"));
        therapyTime->setGeometry(QRect(270, 320, 64, 31));
        label = new QLabel(ActiveTreatment);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(340, 322, 21, 31));

        retranslateUi(ActiveTreatment);

        QMetaObject::connectSlotsByName(ActiveTreatment);
    } // setupUi

    void retranslateUi(QDialog *ActiveTreatment)
    {
        ActiveTreatment->setWindowTitle(QCoreApplication::translate("ActiveTreatment", "Dialog", nullptr));
        label_2->setText(QCoreApplication::translate("ActiveTreatment", "Time of Therapy : ", nullptr));
        skinTouch->setText(QCoreApplication::translate("ActiveTreatment", "Touch Here", nullptr));
        label->setText(QCoreApplication::translate("ActiveTreatment", "S", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ActiveTreatment: public Ui_ActiveTreatment {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ACTIVETREATMENT_H
