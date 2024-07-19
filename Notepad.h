//
// Created by nicco on 15/07/24.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_NOTEPAD_H
#define LABORATORIO_PROGRAMMAZIONE_NOTEPAD_H

#include <map>
#include <string>
#include <vector>
#include <memory>
#include <list>
#include "Note.h"
#include "Subject.h"
#include "Observer.h"

class Notepad: public Subject{
private:
    std::map<std::string, std::vector<Note*>> notepad;
    std::list<Observer*> observers;

public:
    void removeFromImportant (const std::string& collectionTitle, const std::string& noteTitle);
    void putInImportant (const std::string& collectionTitle, const std::string& noteTitle);
    void lockNote (const std::string& collectionTitle, const std::string& noteTitle);
    void unlockNote (const std::string& collectionTitle, const std::string& noteTitle);
    void deleteCollection (const std::string& collectionTitle);
    void setCollectionTitle (const std::string& collectionTitle);
    void showNote (const std::string& collectionTitle, const std::string& noteTitle);
    void removeNote (const std::string& collectionTitle, const std::string& noteTitle);
    void createNote (const std::string& collectionTitle);
    void modifyNote (const std::string& collectionTitle, const std::string& noteTitle);
    std::vector<int> getEmailNumber();
    int getCollectionNumber ();
    std::vector<std::string> getCollectionTitle();
    void subscribe(Observer *o) override;
    void unsubscribe(Observer *o) override;
    void notify() override;
};


#endif //LABORATORIO_PROGRAMMAZIONE_NOTEPAD_H
