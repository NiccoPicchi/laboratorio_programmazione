//
// Created by nicco on 15/07/24.
//

#ifndef LABORATORIO_PROGRAMMAZIONE_NOTE_H
#define LABORATORIO_PROGRAMMAZIONE_NOTE_H


#include <string>
#include <fstream>

class Note {
private:
    std::string title;
    bool blocked;
    std::string text;
    bool important;
public:
    Note(const std::string &title , const std::string &text, bool blocked = false, bool important = false);

    void displayNote();
    // Note* createNote ();
    void writeOnNote(const std::string &newText);

    void setBlocked(bool blocked);

    bool isBlocked() const;

    void setTitle(const std::string &title);

    bool isImportant() const;

    const std::string &getTitle() const;

    void setImportant(bool important);

    void modifyNote(const std::string &newText);
};


#endif //LABORATORIO_PROGRAMMAZIONE_NOTE_H
