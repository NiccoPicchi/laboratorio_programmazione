//
// Created by nicco on 15/07/24.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_NOTEPADOBSERVER_H
#define LABORATORIO_PROGRAMMAZIONE_NOTEPADOBSERVER_H

#include "Observer.h"
#include "Notepad.h"

class NotepadObserver: public Observer{
private:
    Notepad* subject;
    std::vector<int> noteNumberInCollection;
    std::vector<std::string> collectionTitles;
public:
    explicit NotepadObserver(Notepad *subject);
    void update() override;
    ~NotepadObserver() override;
    void displayInfo();
};

#endif //LABORATORIO_PROGRAMMAZIONE_NOTEPADOBSERVER_H
