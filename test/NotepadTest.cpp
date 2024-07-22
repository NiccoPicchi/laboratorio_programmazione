#include "gtest/gtest.h"
#include "../Notepad.h"

TEST(Notepad, createNote) {
    Notepad notepad;
    std::string collectionTitle = "note a caso";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle);
    ASSERT_EQ(notepad.getEmailInACollection(collectionTitle), 1);
}


TEST(Notepad, removeNote){
    Notepad notepad;
    std::string collectionTitle = "note a caso";
    notepad.setCollectionTitle(collectionTitle);
    notepad.createNote(collectionTitle);
    notepad.removeNote(collectionTitle, "titolo");
    ASSERT_EQ(notepad.getEmailInACollection(collectionTitle), 0);
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