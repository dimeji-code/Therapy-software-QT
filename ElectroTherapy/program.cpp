#include "program.h"



Program::Program(QString n, QString f, int d){
    this->name = n;
    this->frequency = f;
    this->duration = d;

}

Program::~Program(){

}

QString Program::getName(){
    return name;
}

QString Program::getFreq(){
    return frequency;
}

int Program::getDuration(){
    return duration;
}

void Program::displayProgramList(){

}
