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
    std::fstream text;
    bool important;
    std::string fileName;
public:
    Note(const std::string &title,const std::string &fileName, bool blocked= false, bool important= false );

    void displayNote (const std::string& name);
    // Note* createNote ();
    void writeOnNote (const std::string& name);

    void setBlocked(bool blocked);

    bool isBlocked() const;

    const std::string &getFileName() const;

    void setTitle(const std::string &title);

    bool isImportant() const;

    const std::string &getTitle() const;

    void setImportant(bool important);

    void modifyNote(const std::string &name);
};


#endif //LABORATORIO_PROGRAMMAZIONE_NOTE_H
