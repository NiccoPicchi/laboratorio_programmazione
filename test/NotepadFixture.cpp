#include "gtest/gtest.h"

#include "../Notepad.h"


class GameCharacterSuite : public ::testing::Test {

protected:
    virtual void SetUp() {
        c = new GameCharacter(10);
        c->setXPos(10);
        c->setYPos(10);
        c->setFighting(true);
    }


    void TearDown() override {
    delete c;
    }


    GameCharacter* c = nullptr;  // XXX C++11 standard initialization
};

TEST_F(GameCharacterSuite, TestMove) {
    c->move(12,14);
    ASSERT_EQ(c->getXPos(), 22);
    ASSERT_EQ(c->getYPos(), 24);
    ASSERT_FALSE(c->isFighting());
}

TEST_F(GameCharacterSuite, TestFight) {
    GameCharacter enemy(3);
    // GameCharacters can not have negative HP !!!
    c->fight(enemy);
    ASSERT_EQ(enemy.getHP(), 2);
    c->fight(enemy);
    ASSERT_EQ(enemy.getHP(), 1);
    c->fight(enemy);
    ASSERT_EQ(enemy.getHP(), 0);
    c->fight(enemy);
    ASSERT_EQ(enemy.getHP(), 0);
}