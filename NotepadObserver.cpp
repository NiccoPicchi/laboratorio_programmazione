//
// Created by nicco on 15/07/24.
//

#include <iostream>
#include "NotepadObserver.h"

void NotepadObserver::update() {
    collectionTitles = subject->getCollectionTitle();
    noteNumberInCollection = subject->getNotesNumber();
    displayInfo();
}

NotepadObserver::NotepadObserver(Notepad *subject) : subject(subject) {
    subject->subscribe(this);
}

NotepadObserver::~NotepadObserver() {
    subject->unsubscribe(this);
}

void NotepadObserver::displayInfo() {
    for (int i = 0; i < subject->getCollectionNumber(); ++i) {
        std::cout<<"Nella collezione "<< collectionTitles[i]<< " ci sono "<< noteNumberInCollection[i]<< " note"<<std::endl;
    }
}
