#include "activetreatment.h"
#include "ui_activetreatment.h"
#include <QTimer>
#include "qmovie.h"
#include "qpixmap.h"

ActiveTreatment::ActiveTreatment(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ActiveTreatment)
{
    ui->setupUi(this);
    ui->therapyTime->display(0);
    ui->skinTouch->setText("Touch Here");
    ui->warning->setText(" ");
    is_therapy = false;
    time=0;

     timer = new QTimer(this);
     timer->setInterval(1000);

     movie = new QMovie(":/img/shock.gif");
     ui->shock->setMovie(movie);

     connect(timer, &QTimer::timeout, this, &ActiveTreatment::onTimeOut);

     connect(movie, &QMovie::finished, movie, &QMovie::stop);

     connect(movie, &QMovie::finished,
                 this, [&](){
             QPixmap image(":/img/shock.gif");
             ui->shock->setPixmap(image);
             ui->shock->show();
         });


}

void ActiveTreatment::setFreq(QString f){

    this->freq = f;
    ui->frequency->setText(this->freq) ;
}

void ActiveTreatment::setTimeLimit(int tl){
    this->timeLimit = tl;

}

QString ActiveTreatment::convert(int a){
    int f = 0;
    int l = 0;
    f = a/60;
    l = a%60;
    QString m;
    if (l < 10){
        m = QString("%1:0%2").arg(f).arg(l);
    }
    else{
        m = QString("%1:%2").arg(f).arg(l);

    }
    return m;

}

void ActiveTreatment::onTimeOut(){

    time += 1;
    QString c = convert(time);
    ui->therapyTime->display(c);
    if (time/60 >= timeLimit){
        timer->stop();
        movie->stop();
        ui->warning->setText("Therapy Over :)");
    }
}

ActiveTreatment::~ActiveTreatment()
{
    delete ui;
    delete movie;
    delete timer;
}

void ActiveTreatment::on_skinTouch_clicked()
{
    if(is_therapy == false){
        ui->skinTouch->setText("Stop Therapy");
        is_therapy = true;
        timer->start();
        movie->start();
        ui->warning->setText("");



    } else {
        ui->skinTouch->setText("Touch Here");
        is_therapy = false;
        timer->stop();
        movie->stop();
        QString d = QString("PLACE NODE ON SKIN!!!");

        ui->warning->setText(d);
    }
}
