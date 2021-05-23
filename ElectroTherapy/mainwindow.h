
#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "program.h"
#include "activetreatment.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int mainMenu(int);
    void deviceOn();
    void deviceOff();
    void onTimeOut();
    void loadMainMenu();
    void getMatchingPrograms(QString);
    void segueLevel1();
    void segueLevel2();
    void segueLevel3();
    void segueLevel4();
    void charge();

private slots:

    void on_power_clicked();

    void on_up_clicked();

    void on_down_clicked();

    void on_pushButton_clicked();

    void on_mainMenu_clicked();

    void on_right_clicked();

    void on_left_clicked();

    void on_back_clicked();

    void on_recharge_clicked();

private:
    bool charging;
    bool on;
    int powerLev;
    int mode;
    int segueLevel;
    Ui::MainWindow *ui;
    QTimer*timer;
    QList <Program*> progVector;
    ActiveTreatment *a;

};
#endif // MAINWINDOW_H
