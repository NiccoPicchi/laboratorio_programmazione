//
// Created by nicco on 15/07/24.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "Note.h"


void Note::displayNote(const std::string& name) {
    std::cout<<"Showing the note..."<<std::endl;
    std::cout<<"Title: "<< title<<std::endl;
    std::cout<<"Testo: "<<std::endl;
    text.open(name);
    std::string line;
    while (std::getline(text, line)){
        if (text.is_open())
            std::cout<<line<<std::endl;
        else
            std::cout<<"Impossibile leggere la nota"<<std::endl;
    }
    text.close();

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

void Note::writeOnNote(const std::string& name) {
    if (!blocked){
        text.open(name, std::ios_base::app );
        if(!text)
            std::cerr<<"Errore nell'apertura del file"<<std::endl;
        else{
            std::string input;
            std::cout << "Inserisci il testo: "<<std::endl;
            std::getline(std::cin, input);
            text<< input<<std::endl;
            text.close();
        }
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

void Note::modifyNote(const std::string &name) {
    if (!blocked){
        std::string target;
        std::cout<<"Inserire la parte di testo da modificare"<<std::endl;
        std::getline(std::cin, target);
        std::string replacement;
        std::cout<<"Inserire la parte di testo con cui sostituirla"<<std::endl;
        std::getline(std::cin, replacement);

        std::vector<std::string> lines;
        std::string line;

        text.open(name);
        if (text.is_open()) {
            while (std::getline(text, line)) {
                lines.push_back(line);
            }
            text.close();
        } else {
            std::cerr << "Errore nell'apertura del file " << fileName << std::endl;
        }

        for (auto &line : lines) {
            size_t pos = line.find(target);
            if (pos != std::string::npos) {
                line.replace(pos, target.length(), replacement);
            }
        }

        text.open(name);
        if (text.is_open()) {
            for (const auto &line : lines) {
                text << line << std::endl;
            }
            text.close();
        } else {
            std::cerr << "Errore nell'apertura del file " << fileName << std::endl;
        }

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

Note::Note(const std::string &title, const std::string &fileName, bool blocked, bool important) : title(title),
                                                                                                  blocked(blocked),
                                                                                                  important(important),
                                                                                                  fileName(fileName) {
    text = std::fstream (fileName);
}

const std::string &Note::getFileName() const {
    return fileName;
}
