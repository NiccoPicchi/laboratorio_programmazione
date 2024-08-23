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