#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <time.h>
#include "activetreatment.h"
#include "program.h"

#include <QTimer>
#include <QMessageBox>
#include <QDebug>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{   charging = false;
    powerLev = 0;
    on = true;
    ui->setupUi(this);
    ui->list->setCurrentRow(0);
    mode = 1;
    segueLevel = 1; //is the menu id allowing for quick segues to prvious menu.


    QPixmap pix(":/img/pwrOn.png");

    QPixmap up(":/img/up.png");
    QPixmap down(":/img/down.png");
    QPixmap left(":/img/left.png");
    QPixmap right(":/img/right.png");

    QPixmap menu(":/img/menu.png");
    QPixmap backwards(":/img/back.png");

    QIcon pow(pix);
    ui->power->setIcon(pow);
    ui->power->setIconSize(QSize(110,110));

    QIcon upIcon(up);
    ui->up->setIcon(upIcon);
    ui->up->setIconSize(QSize(60,60));

    QIcon downIcon(down);
    ui->down->setIcon(downIcon);
    ui->down->setIconSize(QSize(60,60));

    QIcon leftIcon(left);
    ui->left->setIcon(leftIcon);
    ui->left->setIconSize(QSize(60,60));

    QIcon rightIcon(right);
    ui->right->setIcon(rightIcon);
    ui->right->setIconSize(QSize(60,60));

    QIcon menuIcon(menu);
    ui->mainMenu->setIcon(menuIcon);
    ui->mainMenu->setIconSize(QSize(40,40));

    QIcon backIcon(backwards);
    ui->back->setIcon(backIcon);
    ui->back->setIconSize(QSize(60,60));

    ui->progressBar->setRange(0,100);
    ui->progressBar->setValue(100);
    ui->battery->display(100);

    timer = new QTimer(this);
    timer->setInterval(2000);

  //  programs
        Program *allergy = new Program("Allergy","<<77 10>>" ,10);
        Program *hypertension = new Program("Hypertension","<<77 10>>",5);
        Program *bloating = new Program("Bloating","<<77 10>>" ,10);
        Program *throat = new Program("Throat","60Hz",10);
        Program *pain = new Program("Pain",NULL,10);
        Program *severePain = new Program("Severe Pain",NULL,15);
        Program *gynaecology = new Program("Gynaecology","<<77 10>>" ,15);
        Program *head = new Program("Head","60Hz" ,5);
        Program *muscles = new Program("Muscles",NULL ,15);
        Program *constipation = new Program("Constipation","<<77AM>>" ,10);
        Program *kidneys = new Program("Kidneys","<<77 10>>" ,15);
        Program *joints = new Program("Joints","<<77 10>>" ,10);
        Program *nausea = new Program("Nausea","<<77 10>>" ,10);
        Program *asthma = new Program("Asthma","<<77 10>>" ,10);
        Program *back = new Program("Back","140Hz" ,15);
        Program *cold = new Program("Cold","77Hz" ,10);
        Program *cough = new Program("Cough","<<77 10>>" ,5);
        Program *diarrhea = new Program("Diarrhea","77Hz" ,10);
        Program *hypotonia = new Program("Hypotonia","60Hz" ,5);

        progVector = {allergy,hypertension,bloating,throat,pain,severePain
            ,gynaecology,head,muscles,constipation,kidneys,joints
            ,nausea,asthma,back ,cold,cough ,diarrhea,hypotonia};

    connect(timer, &QTimer::timeout, this, &MainWindow::onTimeOut);
    timer->start();


}

void MainWindow::onTimeOut(){
    int value = ui->progressBar->value();

    if (value <= 0){
        return;
    }
    if (value >= 100 and charging == true){
        return;
    }
    if (charging == false){
        value -= 1;
        timer->setInterval(15000);
    }
    else if (charging == true){
        value += 1;
        timer->setInterval(200);
    }
    if (value < 10 and charging == false){QMessageBox::about(this, "Battery low", "Please plug in charger!");}
    if (value <= 2){
        timer->stop();
        if (a != NULL){
            a->close();
        }
        ui->up->setDisabled(true);
        ui->right->setDisabled(true);
        ui->down->setDisabled(true);
        ui->left->setDisabled(true);
        ui->power->setDisabled(true);
        ui->mainMenu->setDisabled(true);
        ui->back->setDisabled(true);
        deviceOff();
    }
    ui->battery->display(value);
    ui->progressBar->setValue(value);
}

void MainWindow::charge(){

    ui->up->setDisabled(false);
    ui->right->setDisabled(false);
    ui->down->setDisabled(false);
    ui->left->setDisabled(false);
    ui->power->setDisabled(false);
    ui->mainMenu->setDisabled(false);
    ui->back->setDisabled(false);
    if (on == false){
        deviceOn();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
    delete timer;
    delete a;
}

int MainWindow::mainMenu(int n){

    switch (n) {
        case 0:{

            segueLevel2();
            break;
        }

        case 1:{
            //Frequency select
            segueLevel3();
            break;
        }
        case 2:{
            //med

            break;
        }
        case 3:{
            //baby doctor
            break;
        }
        case 4:{
            //children
            break;
        }
        case 5:{
            //settings
            QStringList set  = {"Sound", "Brightness","Economy","Storage of last settings", "Time",
                              "Alarm Clock"};
            ui->list->clear();
            for (int i = 0; i < set.length(); i++){
                ui->list->addItem(set[i]);
            } ui->list->setCurrentRow(0);
            segueLevel = 6;
            break;
        }
    }
    return 0;
}

void MainWindow::on_power_clicked()//event of pressing power button
{

    if (on == true){
        deviceOff();
    }else{
       deviceOn();
    }
}

void MainWindow::deviceOn(){//all events are turned on
    QPixmap turnOn(":/img/pwrOn.png");

    QIcon pow(turnOn);
    ui->power->setIcon(pow);
    ui->power->setIconSize(QSize(110,110));
    on = true;
    loadMainMenu();
    timer->start();
}

void MainWindow::deviceOff(){//all events are turned on
    QPixmap turnOff(":/img/pwrOff.png");

    QIcon pow(turnOff);
    ui->power->setIcon(pow);
    ui->power->setIconSize(QSize(110,110));
    on = false;
    ui->list->clear();
    timer->stop();
}

void MainWindow::loadMainMenu(){
    ui->list->addItem("Program");
    ui->list->addItem("Frequency");
    ui->list->addItem("Med");
    ui->list->addItem("Baby Doctor");
    ui->list->addItem("Children");
    ui->list->addItem("Settings");
    ui->list->setCurrentRow(0);
}

void MainWindow::on_up_clicked()
{
    int i = ui->list->currentRow();
    if(ui->list->currentRow() > 0){
        ui->list->setCurrentRow(i-1);
    }
}

void MainWindow::on_down_clicked()
{
    int i = ui->list->currentRow();
    if(ui->list->currentRow() < ui->list->count()){
        ui->list->setCurrentRow(i+1);
    }
}

void MainWindow::on_pushButton_clicked()
{
     QString holder;
    if (segueLevel == 1){
        int n = ui->list->currentRow();
        mainMenu(n);
    } else if(segueLevel == 2){
        //segue to treatment
        QString freq;
        int timeLimit =0;
        QString name = ui->list->currentItem()->text();
        for (int i = 0; i < progVector.count();i++){
            if (name == progVector[i]->getName()){
               freq = progVector[i]->getFreq();
               timeLimit = progVector[i]->getDuration();
            }
        }
            a = new ActiveTreatment;
            a->setFreq(freq);
            a->setTimeLimit(timeLimit);
            a->setModal(true);
            a->exec();

    }else if(segueLevel == 3){
        //segue to level 4
        QString freq = ui->list->currentItem()->text();
        holder = freq;
        ui->list->clear();
        getMatchingPrograms(freq);
        segueLevel = 4;

    }else if(segueLevel == 4){
        //segue to treatment
        QString freq;
        int timeLimit = 0;
        if (ui->list->count() > 0){
            QString name = ui->list->currentItem()->text();
            for (int i = 0; i<progVector.count();i++){
                if (name == progVector[i]->getName()){
                   freq = progVector[i]->getFreq();
                   timeLimit = progVector[i]->getDuration();

                }
            }
        }
        else{
            freq = holder;
        }
        a = new ActiveTreatment;
        a->setFreq(freq);
        if (ui->list->count() > 0){
            a->setTimeLimit(timeLimit);
        }else{
            a->setTimeLimit(4); //generic time limit
        }
        a->setModal(true);
        a->exec();

    }

}

void MainWindow::on_mainMenu_clicked()
{
    segueLevel1();
}

void MainWindow::on_right_clicked()
{
    if (powerLev <= 100){
        powerLev += 1;
        ui->powerLevel->display(powerLev);
    }
}

void MainWindow::on_left_clicked()
{
    if (powerLev >= 1){
        powerLev -= 1;
        ui->powerLevel->display(powerLev);
    }
}

void MainWindow::getMatchingPrograms(QString a){
    for (int i = 0; i<progVector.count();i++){
        if (a == progVector[i]->getFreq()){
            ui->list->addItem(progVector[i]->getName());
        }
    }
}

void MainWindow::segueLevel1(){

    ui->list->clear();
    segueLevel = 1;
    loadMainMenu();
}

void MainWindow::segueLevel2(){
    ui->list->clear();
    for (int i = 0;i < progVector.count();i++){
        ui->list->addItem(progVector[i]->getName());
    }
    ui->list->setCurrentRow(0);
    segueLevel = 2;
}

void MainWindow::segueLevel3(){
    QStringList fr  = {"1.0 - 9.9Hz", "10Hz"," 20Hz","60Hz", "77Hz",
                      "140Hz","200Hz", "<<77 10>>","<<77AM>>"};

    ui->list->clear();
    for (int i = 0; i < fr.length(); i++){
        ui->list->addItem(fr[i]);
    } ui->list->setCurrentRow(0);
    segueLevel = 3;
}

void MainWindow::segueLevel4(){} //reference on_pushButton_clicked(); implemented

void MainWindow::on_back_clicked()
{
    if (segueLevel == 1){}
    else if (segueLevel == 2){segueLevel1(); segueLevel = 1;}
    else if (segueLevel == 3){segueLevel1(); segueLevel = 1;}
    else if (segueLevel == 4){segueLevel3(); segueLevel = 3;}
    else if (segueLevel == 6){segueLevel1(); segueLevel = 1;}
}

void MainWindow::on_recharge_clicked()
{
    if (charging == true){
        ui->recharge->setText("RECHARGE : OFF");
        charging = false;
        return;
    } else if (charging == false){
        ui->recharge->setText("RECHARGE : ON");
        charging = true;
        charge();
        return;
    }
}
