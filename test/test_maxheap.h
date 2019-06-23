#include "gtest/gtest.h"
#include "maxheap.h"
#include "heap.h"

using namespace std;

   class maxHeapTest : public ::testing::Test 
   {
      protected:
         maxHeapTest() {}
         ~maxHeapTest() override{}
   };

   TEST_F(maxHeapTest, maxHeapInsert900)
   {
      maxHeap maxheap;

      for(int i = 100; i < 1000; i++)
      {
         maxheap.insert(i);
      }

      EXPECT_EQ(maxheap.getSize(), 900);
      EXPECT_EQ(maxheap.getData(0), 999);
      EXPECT_EQ(maxheap.findRoot(), 999);

      maxheap.insert(131);
      EXPECT_EQ(maxheap.findRoot(), 999);
      EXPECT_EQ(maxheap.getSize(), 901);

      maxheap.insert(2000);

      EXPECT_EQ(maxheap.findRoot(), 2000);
      EXPECT_EQ(maxheap.getSize(), 902);
   } 
