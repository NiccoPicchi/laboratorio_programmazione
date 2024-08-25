#include "gtest/gtest.h"
#include "../Notepad.h"

TEST(Note, constructor) {
    Note nota("titolo", "testo");
    ASSERT_EQ(nota.getTitle(), "titolo");
    ASSERT_EQ(nota.getText(), "testo");
}

TEST(Note, modifyNote) {
    Note nota ("titolo", "testo");
    std::string nuovoTesto = "nuovo testo";
    nota.modifyNote(nuovoTesto);
    ASSERT_EQ(nota.getText(), "nuovo testo");
}



TEST(Notepad, createNote) {
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    ASSERT_EQ(notepad.getNotesInACollection(collectionTitle), 1);
}


TEST(Notepad, removeNote){
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    notepad.removeNote(collectionTitle, "titolo");
    ASSERT_EQ(notepad.getNotesInACollection(collectionTitle), 0);
}

TEST(Notepad, modifyNoteText) {
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    notepad.modifyNoteText(collectionTitle, "titolo", "nuovo testo" );
    auto nota = notepad.getNote(collectionTitle, "titolo");
    ASSERT_EQ(nota.getText(), "nuovo testo");
}

TEST(Notepad, modifyNoteTitle){
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    notepad.modifyNoteTitle(collectionTitle, "titolo", "nuovo titolo" );
    auto nota = notepad.getNote(collectionTitle, "nuovo titolo");
    ASSERT_EQ(nota.getTitle(), "nuovo titolo");
}

TEST(Notepad, setCollection){
    Notepad notepad;
    notepad.setCollectionTitle("collezione");
    ASSERT_EQ(notepad.getCollectionNumber(), 1);
}

TEST(Notepad, removeCollection){
    Notepad notepad;
    notepad.setCollectionTitle("collezione");
    notepad.deleteCollection("collezione");
    ASSERT_EQ(notepad.getCollectionNumber(), 0);
}

TEST(Notepad, lockNote){
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    notepad.lockNote(collectionTitle, "titolo");
    auto nota = notepad.getNote(collectionTitle, "titolo");
    ASSERT_EQ(nota.isBlocked(), true);
}

TEST(Notepad, unlockNote){
    Notepad notepad;
    std::string collectionTitle = "note";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle, "testo", "titolo");
    notepad.unlockNote(collectionTitle, "titolo");
    auto nota = notepad.getNote(collectionTitle, "titolo");
    ASSERT_EQ(nota.isBlocked(), false);
}

TEST(Notepad, setNoteImportant) {
    Notepad notepad;
    notepad.setCollectionTitle("Note importanti");
    notepad.setCollectionTitle("note");
    notepad.createNote("note", "testo", "titolo");
    notepad.setNoteImportant("note", "titolo");
    auto nota = notepad.getNote("note", "titolo");
    ASSERT_EQ(nota.isImportant(), true);
    ASSERT_EQ(notepad.getNotesInACollection("Note importanti"), 1);
}

TEST(Notepad, unsetNoteImportant) {
    Notepad notepad;
    notepad.setCollectionTitle("Note importanti");
    notepad.setCollectionTitle("note");
    notepad.createNote("note", "testo", "titolo");
    notepad.setNoteImportant("note", "titolo");
    notepad.unsetNoteImportant("note", "titolo");
    auto nota = notepad.getNote("note", "titolo");
    ASSERT_EQ(nota.isImportant(), false);
    ASSERT_EQ(notepad.getNotesInACollection("Note importanti"), 0);
}