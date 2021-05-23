#ifndef ACTIVETREATMENT_H
#define ACTIVETREATMENT_H

#include <QDialog>
#include <QPushButton>
#include <QPropertyAnimation>

namespace Ui {
class ActiveTreatment;
}

class ActiveTreatment : public QDialog
{
    Q_OBJECT

public:
    explicit ActiveTreatment(QWidget *parent = nullptr);
    ~ActiveTreatment();
    void onTimeOut();
    QString convert(int);
    void setFreq(QString);
    void setTimeLimit(int);

private slots:
    void on_skinTouch_clicked();

private:
    Ui::ActiveTreatment *ui;
    QPushButton skinTouch;
    QTimer *timer;
    bool is_therapy;
    QPropertyAnimation *anime;
    QMovie* movie;
    int time;
    QString freq;
    int timeLimit;
};

#endif // ACTIVETREATMENT_H
