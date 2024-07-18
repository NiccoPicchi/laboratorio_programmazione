#include "gtest/gtest.h"
#include "../Notepad.h"

TEST(Notepad, createNote) {
    Notepad notepad;
    std::string collectionTitle = "note a caso";
    notepad.createNote(collectionTitle);
    ASSERT_EQ(notepad[collectionTitle][0], Note("titolo", "filename"));
}




TEST(GameCharacter, FightingDisabled){
    GameCharacter test(5);
    test.setFighting (true);
    ASSERT_TRUE (test.isFighting());
    test.move(2,3);
    ASSERT_FALSE(test.isFighting());
}