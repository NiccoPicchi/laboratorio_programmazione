//
// Created by nicco on 15/07/24.
//

#include <iostream>
#include "Notepad.h"

void Notepad::setCollectionTitle(const std::string& collectionTitle) {
    if(notepad.find(collectionTitle) == notepad.end())
        notepad[collectionTitle]=std::vector<Note*>();
    else
        std::cout<<"è già presente una collezione di note con questo nome"<<std::endl;


}

void Notepad::showNote(const std::string &collectionTitle, const std::string& noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            std::cout<<"Mostrando la nota dalla collezione:"<< collectionTitle <<std::endl;
            (notepad[collectionTitle])[i]->displayNote((notepad[collectionTitle])[i]->getFileName());
            found = true;
        }
    }
}

void Notepad::removeNote(const std::string &collectionTitle, const std::string& noteTitle) {
    for (auto it = notepad[collectionTitle].begin(); it != notepad[collectionTitle].end(); it++)
        if ((*it)->getTitle() == noteTitle) {
            notepad[collectionTitle].erase(it);
            std::cout << "Nota eliminata con successo" << std::endl;
            notify();
            break;
        }
        else
            std::cout << "Impossibile eliminatre la nota! Nota non trovata!" << std::endl;
}

void Notepad::createNote(const std::string& collectionTitle) {
    if (notepad.find(collectionTitle) != notepad.end()){
        std::string noteTitle;
        std::cout<<"Inserire il titolo della nota"<<std::endl;
        std::getline(std::cin, noteTitle);
        std::string fileName;
        std::cout<<"Inserire il nome del file"<<std::endl;
        std::getline(std::cin, fileName);
        notepad[collectionTitle].push_back(new Note(noteTitle, fileName));
        notepad[collectionTitle][notepad[collectionTitle].size()-1]->writeOnNote(fileName);
        notify();

    }
    else
        std::cout<<"Impossibile trovare la collezione di note"<<std::endl;
}

void Notepad::modifyNote(const std::string& collectionTitle, const std::string& noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            std::cout<<"Modificando la nota dalla collezione:"<< collectionTitle <<std::endl;
            (notepad[collectionTitle])[i]->modifyNote((notepad[collectionTitle])[i]->getFileName());
            found = true;
            std::cout<<"Nota modificata con successo!"<<std::endl;
        }
    }

}


std::vector<int> Notepad::getEmailNumber() {
    std::vector<int> noteInCollection;
    noteInCollection.clear();
    for (const auto& element: notepad)
        noteInCollection.push_back(element.second.size());
    return noteInCollection;
}

int Notepad::getCollectionNumber() {
    return notepad.size();
}

std::vector<std::string> Notepad::getCollectionTitle() {
    std::vector<std::string> collectionTitles;
    collectionTitles.reserve(notepad.size());
    for(const auto& element: notepad)
        collectionTitles.push_back(element.first);
    return collectionTitles;
}

void Notepad::deleteCollection(const std::string& collectionTitle) {
    auto it =notepad.find(collectionTitle);
    if (it != notepad.end()){
        it->second.clear();
        notepad.erase(it);
        std::cout<<"La collezione "<< collectionTitle<< " è stata cancellata con successo!"<<std::endl;
    }
    else
        std::cout<<"Impossibile trovare la collezione!"<<std::endl;
}

void Notepad::subscribe(Observer *o) {
    observers.push_back(o);
}

void Notepad::unsubscribe(Observer *o) {
    observers.remove(o);
}

void Notepad::notify() {
    for (auto element: observers)
        element->update();
}

void Notepad::lockNote(const std::string &collectionTitle, const std::string &noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            (notepad[collectionTitle])[i]->setBlocked(true);
            std::cout<<"Nota bloccata con successo! Ora è impossibile modificarla" <<std::endl;
            found = true;
        }
    }
}

void Notepad::unlockNote(const std::string &collectionTitle, const std::string &noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            (notepad[collectionTitle])[i]->setBlocked(false);
            std::cout<<"Nota sbloccata con successo! Ora è possibile modificarla" <<std::endl;
            found = true;
        }
    }
}
