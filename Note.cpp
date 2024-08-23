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

/*Note* Note::createNote() {
    std::string titolo;
    std::cout<<"Inserire il titolo della nota"<<std::endl;
    std::cin>>titolo;
    setTitle(titolo);
    text = std::fstream ();
    if (!text)
        std::cerr<<"Errore nell'apertura del file"<<std::endl;
    else {
        std::cout<<"Scrivere il testo da inserire nella nota"<<std::endl;
        std::string newString;
        std::cin>>newString;
        text <<newString;
        text.close();
    }
    return this;
}
 */

void Note::writeOnNote(const std::string &newText) {
    if (!blocked){
        text = newText;
    }
    else
        std::cout<<"Nota bloccata! Impossibile modificarla!"<<std::endl;
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
