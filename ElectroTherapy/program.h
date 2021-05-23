#ifndef PROGRAM_H
#define PROGRAM_H

#include "QString"

class Program{
public:
    Program(QString, QString, int);
    ~Program();
    QString getName();
    QString getFreq();
    int getDuration();
    void displayProgramList();

private:
    QString name;
    QString frequency;
    int duration; //in minutes

};

#endif // PROGRAM_H

