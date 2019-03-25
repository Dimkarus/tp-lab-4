#include "gtest/gtest.h"
#include "auto.h"

TEST(lab4, task_1) {
	std::vector<std::string> menu = { "Cap", "Tea", "Coffe","Espresso" };
	std::vector<double> price = { 30.0, 20.0, 25.0, 35.0 };
	Automata tmp(price, menu);
    tmp.on();
    tmp.coin(10.0);

    bool test = tmp.check(price[0]);
    EXPECT_EQ(0, tmp);
}

TEST(lab4, task_2) {
	std::vector<std::string> menu = { "Cap", "Tea", "Coffe","Espresso" };
	std::vector<double> price = { 30.0, 20.0, 25.0, 35.0 };
	Automata tmp(price, menu);
    tmp.on();
    tmp.coin(31.0);

    bool test = tmp.check(price[0]);
    EXPECT_EQ(1, tmp);
}


