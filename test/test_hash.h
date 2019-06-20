#include "gtest/gtest.h"
#include "hashTable.cpp"
#include "driver.h"

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

TEST_F(hastableTest, testDriver)
{
    hashTable hash;

    hashDriver hashTableBuilder(hash);
    hashTableBuilder.readSingle("..\\testfiles\\1K.txt");

    cout<<"capacity: "<< hash.getCapacity() <<endl;;

    EXPECT_EQ(hash.getSize(), 1000);

    EXPECT_EQ(hash.search(1000000), false);
    EXPECT_EQ(hash.search(998), true);

    hash.insert(101);
    EXPECT_EQ(hash.getSize(), 1001);
    EXPECT_EQ(hash.search(101), true);
}

