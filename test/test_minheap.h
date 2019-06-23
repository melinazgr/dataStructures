#include "gtest/gtest.h"
#include "minheap.h"
#include "heap.h"

using namespace std;

   class minHeapTest : public ::testing::Test 
   {
      protected:
         minHeapTest() {}
         ~minHeapTest() override{}
   };

   TEST_F(minHeapTest, minHeapInsert900)
   {
      minHeap minheap;

      for(int i = 1000; i > 100; i--)
      {
         minheap.insert(i);
      }

      EXPECT_EQ(minheap.getSize(), 900);
      EXPECT_EQ(minheap.getData(0), 101);
      EXPECT_EQ(minheap.findRoot(), 101);

      minheap.insert(10000);
      EXPECT_EQ(minheap.findRoot(), 101);
      EXPECT_EQ(minheap.getSize(), 901);

      minheap.insert(10);

      EXPECT_EQ(minheap.findRoot(), 10);
      EXPECT_EQ(minheap.getSize(), 902);
   } 

   TEST_F(minHeapTest, minHeapBuild9)
   {
      minHeap minheap;

      int data[] = { 3, 2, 1, 7, 8, 4, 10, 16, 12 };
      int expectedData[] = {1, 3, 2, 7, 8, 4, 10, 16, 12};

      for (int i = 0; i < sizeof(data) / sizeof(int); i++)
      {
         minheap.insert(data[i]);
      }

      for (int i = 0; i < sizeof(data) / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData[i]);
      }

      EXPECT_EQ(minheap.findRoot(), 1);


      minheap.deleteRoot();

      int expectedData1[] = {2, 3, 4, 7, 8, 12, 10, 16};

      for (int i = 0; i < minheap.getSize() / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData1[i]);
      }

         EXPECT_EQ(minheap.getSize(), 8);
      
   }

   TEST_F(minHeapTest, minHeapBuild20)
   {
      minHeap minheap;

      int data[] = { 29,25,2,13,9,3,10,18,31,19,26,8,30,27,22,12,23,28,24,17};
      int expectedData[] = {2,9,3,12,13,8,10,18,24,17,26,25,30,27,22,29,23,31,28,19};

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         minheap.insert(data[i]);
      }

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData[i]);
      }

      EXPECT_EQ(minheap.getSize(), 20);
      
      minheap.insert(100);
      EXPECT_EQ(minheap.getData(20), 100);
      EXPECT_EQ(minheap.getSize(), 21);

      minheap.insert(1);
      EXPECT_EQ(minheap.findRoot(), 1);
      EXPECT_EQ(minheap.getSize(), 22);

      minheap.deleteRoot();
      EXPECT_EQ(minheap.findRoot(), 2);
      EXPECT_EQ(minheap.getSize(), 21);

      int expectedData1[] = {2,9,3,12,13,8,10,18,24,17,26,25,30,27,22,29,23,31,28,19,100};
      
      for (int i=0; i < minheap.getSize() / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData1[i]);
      }
   } 
