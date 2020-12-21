//
// Created by winters on 2020/12/21.
//

#include "gtest/gtest.h"
extern "C"{
#include "sds.h"
}
TEST(sds, test)
{
    EXPECT_STREQ(sds_init_with_str("test"),"test");
}

