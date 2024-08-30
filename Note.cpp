//
// Created by nicco on 15/07/24.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Note.h"


void Note::displayNote() {
    std::cout<<"Showing the note..."<<std::endl;
    std::cout<<"Title: "<< title<<std::endl;
    std::cout<<"Testo: "<< text<<std::endl;
}

void Note::setBlocked(bool blocked) {
    Note::blocked = blocked;
}

void Note::setImportant(bool important) {
    Note::important = important;
}

void Note::modifyNote(const std::string &newText) {
    if (!blocked){
        text = newText;
        std::cout << "La nota è stata modificata con successo." << std::endl;
    } else
        std::cout<<"Nota bloccata! Impossibile modificarla!"<<std::endl;
}

const std::string &Note::getTitle() const {
    return title;
}

void Note::setTitle(const std::string &title) {
    Note::title = title;
}

Note::Note(const std::string &title, const std::string& text, bool blocked, bool important)
        : title(title), text(text), blocked(blocked), important(important){}


bool Note::isBlocked() const {
    return blocked;
}

bool Note::isImportant() const {
    return important;
}

const std::string &Note::getText() const {
    return text;
}

Note::Note(const std::string &title, bool blocked, const std::string &text, bool important): title(title), blocked(blocked), text(text), important(important) {}
