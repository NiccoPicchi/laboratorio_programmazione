//
// Created by nicco on 15/07/24.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
#define LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
class Observer{
public:
    virtual void update()=0;
    virtual ~Observer()= default;
};

#endif //LABORATORIO_PROGRAMMAZIONE_OBSERVER_H
