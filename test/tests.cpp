#include "gtest/gtest.h"
#include "auto.h"

TEST(lab4, task_1) {
	Automata tmp;
    tmp.on();
    tmp.coin(10);

    int test = tmp.check(30);
    EXPECT_EQ(0, test);
}

TEST(lab4, task_2) {
	Automata tmp;
    tmp.on();
    tmp.coin(31);

    int test = tmp.check(30);
    EXPECT_EQ(1, test);
}

TEST(lab4, task_3) {

    int tmp = 10;
    EXPECT_EQ(10, tmp);
}


TEST(lab4, task_4) {
 
    int tmp = 5;
    EXPECT_EQ(5, tmp);
}

TEST(lab4, task_5) {
  
    int tmp = 0;
    EXPECT_EQ(0, tmp);
}

