#include "gtest/gtest.h"
#include "minheap.cpp"
#include "avl.cpp"
#include "heap.cpp"


namespace {
   // The fixture for testing class minHeap.
   class minHeapTest : public ::testing::Test 
   {
      protected:
      // You can remove any or all of the following functions if its body
      // is empty.

      minHeapTest() 
      {
         // You can do set-up work for each test here.
      }

      ~minHeapTest() override 
      {
         // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      void SetUp() override 
      {
         // Code here will be called immediately after the constructor (right
         // before each test).
      }

      void TearDown() override 
      {
         // Code here will be called immediately after each test (right
         // before the destructor).
      }

      // Objects declared here can be used by all tests in the test case for Foo.
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

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         minheap.insert(data[i]);
      }

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData[i]);
      }
   }

   TEST_F(minHeapTest, minHeapBuild30)
   {
      minHeap minheap;

      int data[] = { 3, 2, 1, 7, 8, 4, 10, 16, 12 };
      int expectedData[] = {1, 3, 2, 7, 8, 4, 10, 16, 12};

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         minheap.insert(data[i]);
      }

      for (int i=0; i<sizeof(data) / sizeof(int); i++)
      {
         EXPECT_EQ(minheap.getData(i), expectedData[i]);
      }
   }

///////////////////////////////////////////////////////////////////////////////////////////
class avlTest : public ::testing::Test 
   {
      protected:
      // You can remove any or all of the following functions if its body
      // is empty.

      avlTest() 
      {
         // You can do set-up work for each test here.
      }

      ~avlTest() override 
      {
         // You can do clean-up work that doesn't throw exceptions here.
      }

      // If the constructor and destructor are not enough for setting up
      // and cleaning up each test, you can define the following methods:

      void SetUp() override 
      {
         // Code here will be called immediately after the constructor (right
         // before each test).
      }

      void TearDown() override 
      {
         // Code here will be called immediately after each test (right
         // before the destructor).
      }

      // Objects declared here can be used by all tests in the test case for Foo.
   };

   TEST_F(avlTest, avlInsert)
   {
      avlTree avl;

         avl.insert(5);
         avl.insert(2);
         avl.insert(8);
         avl.insert(1);
         avl.insert(4);
         avl.insert(7);
         avl.insert(3);

      

      EXPECT_EQ(avl.getSize(), 7);

      avlNode* root = avl.getRoot(); 
      EXPECT_EQ(root->data, 5);
      EXPECT_EQ(root->height, 3);

      //left subtree
      EXPECT_EQ(root->left->data, 2);
      EXPECT_EQ(root->left->height, 2);

      EXPECT_EQ(root->left->left->data, 1);
      EXPECT_EQ(root->left->left->height, 0);

      EXPECT_EQ(root->left->right->data, 4);
      EXPECT_EQ(root->left->right->height, 1);

      EXPECT_EQ(root->left->right->left->data, 3);
      EXPECT_EQ(root->left->right->left->height, 0);

      //right subtree
      EXPECT_EQ(root->right->data, 8);
      EXPECT_EQ(root->right->height, 1);

      EXPECT_EQ(root->right->left->data, 7);
      EXPECT_EQ(root->right->left->height, 0);

      //RR rotation
      avl.insert(6);
      
      EXPECT_EQ(root->data, 5);

      EXPECT_EQ(root->left->data, 2);
      EXPECT_EQ(root->left->left->data, 1);
      EXPECT_EQ(root->left->right->data, 4);
      EXPECT_EQ(root->left->right->left->data, 3);

      EXPECT_EQ(root->right->data, 7);
      EXPECT_EQ(root->right->left->data, 6);
      EXPECT_EQ(root->right->right->data, 8);

      //delete
      avl.deleteNode(2);

      EXPECT_EQ(root->data, 5);

      EXPECT_EQ(root->left->data, 3);
      EXPECT_EQ(root->left->left->data, 1);
      EXPECT_EQ(root->left->right->data, 4);

      EXPECT_EQ(root->right->data, 7);
      EXPECT_EQ(root->right->left->data, 6);
      EXPECT_EQ(root->right->right->data, 8);


   }
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}