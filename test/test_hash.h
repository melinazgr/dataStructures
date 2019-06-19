#include "gtest/gtest.h"
#include "hashTable.cpp"

using namespace std;

class hastableTest : public ::testing::Test 
{
    protected:
        hastableTest() {}
        ~hastableTest() override{}
};

TEST_F(hastableTest, hashInsert)
{
    hashTable hash;

    hash.insert(5);
    hash.insert(100);
    hash.insert(14);
    hash.insert(24);
    hash.insert(52);
    hash.insert(75);
    hash.insert(24);
    hash.insert(74);
    hash.insert(16);
    hash.insert(86);

    EXPECT_EQ(hash.getSize(), 10);

    EXPECT_EQ(hash.search(5), true);
    EXPECT_EQ(hash.search(10), false);

    hash.insert(101);
    EXPECT_EQ(hash.getSize(), 11);
    EXPECT_EQ(hash.search(101), true);
}