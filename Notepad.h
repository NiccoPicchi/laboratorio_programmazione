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

class Notepad{
private:
    std::map<std::string, std::vector<Note*>> notepad;

public:
    void deleteCollection (const std::string& collectionTitle);
    void setCollectionTitle (const std::string& collectionTitle);
    void showNote (const std::string& collectionTitle, const std::string& noteTitle);
    void removeNote (const std::string& collectionTitle, const std::string& noteTitle);
    void createNote (const std::string& collectionTitle);
    void modifyNote (const std::string& collectionTitle, const std::string& noteTitle);
    std::vector<int> getEmailNumber();
    int getCollectionNumber ();
    std::vector<std::string> getCollectionTitle();
};


#endif //LABORATORIO_PROGRAMMAZIONE_NOTEPAD_H
