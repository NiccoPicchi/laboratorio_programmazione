//
// Created by nicco on 15/07/24.
//

#include <iostream>
#include <memory>
#include "Notepad.h"

void Notepad::setCollectionTitle(const std::string& collectionTitle) {
    if(notepad.find(collectionTitle) == notepad.end())
        notepad[collectionTitle]=std::vector<std::shared_ptr<Note>>();
    else
        std::cout<<"è già presente una collezione di note con questo nome"<<std::endl;


}

void Notepad::showNote(const std::string &collectionTitle, const std::string& noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            std::cout<<"Mostrando la nota dalla collezione:"<< collectionTitle <<std::endl;
            (notepad[collectionTitle])[i]->displayNote();
            found = true;
        }
    }
}

void Notepad::removeNote(const std::string &collectionTitle, const std::string& noteTitle) {
    for (auto it = notepad[collectionTitle].begin(); it != notepad[collectionTitle].end(); it++)
        if ((*it)->getTitle() == noteTitle) {
            if (!(*it)->isBlocked()) {
                notepad[collectionTitle].erase(it);
                std::cout << "Nota eliminata con successo" << std::endl;
                notify();
                break;
            }
            else {
                std::cout << "Nota bloccata! Impossibile eliminarla" << std::endl;
                break;
            }
        }
        else
            std::cout << "Impossibile eliminare la nota! Nota non trovata!" << std::endl;
}

void Notepad::createNote(const std::string &collectionTitle, const std::string &noteText, const std::string &noteTitle) {
    if (notepad.find(collectionTitle) != notepad.end()){
        notepad[collectionTitle].push_back(std::make_shared<Note>(noteTitle, noteText));
        notify();

    }
    else
        std::cout<<"Impossibile trovare la collezione di note"<<std::endl;
}

void Notepad::modifyNoteText(const std::string &collectionTitle, const std::string &noteTitle, const std::string &noteText) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            if (notepad[collectionTitle][i]->isBlocked()== false){
                std::cout<<"Modificando la nota dalla collezione:"<< collectionTitle <<std::endl;
                (notepad[collectionTitle])[i]->modifyNote(noteText);
                found = true;
                std::cout<<"Nota modificata con successo!"<<std::endl;
            }
            else {
                std::cout<<"Nota bloccata! Impossibile modificarla"<<std::endl;
                found = true;
            }
        }
    }

}


std::vector<int> Notepad::getNotesNumber() {
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

void Notepad::setNoteImportant(const std::string &collectionTitle, const std::string &noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            (notepad[collectionTitle])[i]->setImportant(true);
            std::cout<<"Hai impostato la nota come importante!" <<std::endl;
            notepad["Note importanti"].emplace_back((notepad[collectionTitle])[i]);
            notify();
            found = true;
        }
    }
}

void Notepad::unsetNoteImportant(const std::string &collectionTitle, const std::string &noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            (notepad[collectionTitle])[i]->setImportant(false);
            std::cout<<"Hai impostato la nota come non importante!" <<std::endl;
            for (auto it = notepad["Note importanti"].begin(); it != notepad["Note importanti"].end(); it++)
                if ((*it)->getTitle() == noteTitle) {
                    notepad["Note importanti"].erase(it);
                    break;
                }
            notify();
            found = true;
        }
    }
}

int Notepad::getNotesInACollection(const std::string &collectionTitle) {
    return notepad[collectionTitle].size();
}

void Notepad::modifyNoteTitle(const std::string &collectionTitle, const std::string &noteTitle,
                              const std::string &newTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            if (notepad[collectionTitle][i]->isBlocked()== false){
                std::cout<<"Modificando il titolo della nota dalla collezione:"<< collectionTitle <<std::endl;
                (notepad[collectionTitle])[i]->setTitle(newTitle);
                found = true;
                std::cout<<"Nota modificata con successo!"<<std::endl;
            }
            else {
                std::cout<<"Nota bloccata! Impossibile modificarla"<<std::endl;
                found = true;
            }
        }
    }

}

const Note &Notepad::getNote(const std::string& collectionTitle, const std::string& noteTitle) {
    bool found = false;
    for (int i = 0; i < notepad[collectionTitle].capacity() || !found; ++i) {
        if ((notepad[collectionTitle])[i]->getTitle() == noteTitle) {
            return *(notepad[collectionTitle][i]);
        }
    }
}