//
// Created by winters on 2021/1/2.
//

#include "gtest/gtest.h"

extern "C" {
#include "linked_list.h"
}

#define LIST list

#define INIT_LIST() LINKED_LIST *LIST = init_linked_list();\
int obj_1 = 1;\
int obj_2 = 2;\
int obj_3 = 3;                                     \

#define FREE_LIST() free(LIST);


TEST(LINKED_LIST, add_last_and_pop) {
    INIT_LIST()

    add_last(LIST, &obj_1);
    add_last(LIST, &obj_2);
    add_last(LIST, &obj_3);
    EXPECT_EQ(pop(LIST), &obj_3);
    EXPECT_EQ(pop(LIST), &obj_2);
    EXPECT_EQ(pop(LIST), &obj_1);
    EXPECT_TRUE(pop(LIST) == NULL);

    FREE_LIST()
}

TEST(LINKED_LIST, add_last_and_remove_first) {
    INIT_LIST()

    add_last(LIST, &obj_1);
    add_last(LIST, &obj_2);
    add_last(LIST, &obj_3);
    EXPECT_EQ(remove_first(LIST), &obj_1);
    EXPECT_EQ(remove_first(LIST), &obj_2);
    EXPECT_EQ(remove_first(LIST), &obj_3);
    EXPECT_TRUE(remove_first(LIST) == NULL);

    FREE_LIST()
}

TEST(LINKED_LIST, add_first_and_pop) {
    INIT_LIST()

    add_first(LIST, &obj_1);
    add_first(LIST, &obj_2);
    add_first(LIST, &obj_3);
    EXPECT_EQ(pop(LIST), &obj_1);
    EXPECT_EQ(pop(LIST), &obj_2);
    EXPECT_EQ(pop(LIST), &obj_3);
    EXPECT_TRUE(pop(LIST) == NULL);

    FREE_LIST()
}

TEST(LINKED_LIST, add_first_and_remove_first) {
    INIT_LIST()

    add_first(LIST, &obj_1);
    add_first(LIST, &obj_2);
    add_first(LIST, &obj_3);
    EXPECT_EQ(remove_first(LIST), &obj_3);
    EXPECT_EQ(remove_first(LIST), &obj_2);
    EXPECT_EQ(remove_first(LIST), &obj_1);
    EXPECT_TRUE(remove_first(LIST) == NULL);

    FREE_LIST()
}

