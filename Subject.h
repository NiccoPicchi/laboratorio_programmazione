//
// Created by nicco on 15/07/24.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
#define LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
class Subject{
public:
    virtual void subscribe(Observer* o)=0;
    virtual void unsubscribe(Observer* o)=0;
    virtual void notify()=0;
    virtual ~Subject()= default;
};
#endif //LABORATORIO_PROGRAMMAZIONE_SUBJECT_H
