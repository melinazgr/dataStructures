#include "gtest/gtest.h"
#include "avl.cpp"

class avlTest : public ::testing::Test 
{
   protected:
      avlTest() {}
      ~avlTest() override {}
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
/*   avl.deleteNode(2);

   EXPECT_EQ(root->data, 5);

   EXPECT_EQ(root->left->data, 3);
   EXPECT_EQ(root->left->left->data, 1);
   EXPECT_EQ(root->left->right->data, 4);

   EXPECT_EQ(root->right->data, 7);
   EXPECT_EQ(root->right->left->data, 6);
   EXPECT_EQ(root->right->right->data, 8);*/
}

/*TEST_F(avlTest, avlInsert10)
{
   avlTree avl;

   avl.insert(10);
   avl.insert(30);
   avl.insert(80);
   avl.insert(70);
   avl.insert(2);
   avl.insert(5);
   avl.insert(20);
   avl.insert(7);
   avl.insert(1);
   avl.insert(40);

   EXPECT_EQ(avl.getSize(), 10);

   avlNode* root = avl.getRoot(); 
   EXPECT_EQ(root->data, 30);
   EXPECT_EQ(root->height, 3);

   //left subtree
   EXPECT_EQ(root->left->data, 5);
   EXPECT_EQ(root->left->height, 2);

   EXPECT_EQ(root->left->left->data, 2);
   EXPECT_EQ(root->left->left->height, 1);

   EXPECT_EQ(root->left->right->data, 10);
   EXPECT_EQ(root->left->right->height, 1);

   EXPECT_EQ(root->left->right->left->data, 7);
   EXPECT_EQ(root->left->right->left->height, 0);

   EXPECT_EQ(root->left->right->right->data, 20);
   EXPECT_EQ(root->left->right->right->height, 0);

   //right subtree
   EXPECT_EQ(root->right->data, 70);
   EXPECT_EQ(root->right->height, 1);

   EXPECT_EQ(root->right->left->data, 40);
   EXPECT_EQ(root->right->left->height, 0);

   EXPECT_EQ(root->right->right->data, 80);
   EXPECT_EQ(root->right->right->height, 0);


}*/

TEST_F(avlTest, rotationLL)
{
   avlTree avl;

   avl.insert(50);
   avl.insert(100);
   avl.insert(200);

   EXPECT_EQ(avl.getSize(), 3);

   avlNode* root = avl.getRoot();

   EXPECT_EQ(root->data, 100);
   EXPECT_EQ(root->height, 1);

   EXPECT_EQ(root->left->data, 50);
   EXPECT_EQ(root->right->data, 200);
}

TEST_F(avlTest, rotationRR)
{
   avlTree avl;

   avl.insert(200);
   avl.insert(100);
   avl.insert(50);

   EXPECT_EQ(avl.getSize(), 3);

   avlNode* root = avl.getRoot();

   EXPECT_EQ(root->data, 100);
   EXPECT_EQ(root->height, 1);

   EXPECT_EQ(root->left->data, 50);
   EXPECT_EQ(root->right->data, 200);
}

TEST_F(avlTest, rotationLR)
{
   avlTree avl;

   avl.insert(200);
   avl.insert(50);
   avl.insert(100);

   EXPECT_EQ(avl.getSize(), 3);

   avlNode* root = avl.getRoot();

   EXPECT_EQ(root->data, 100);
   EXPECT_EQ(root->height, 1);

   EXPECT_EQ(root->left->data, 50);
   EXPECT_EQ(root->right->data, 200);
}

TEST_F(avlTest, rotationRL)
{
   avlTree avl;

   avl.insert(50);
   avl.insert(200);
   avl.insert(100);

   EXPECT_EQ(avl.getSize(), 3);

   avlNode* root = avl.getRoot();

   EXPECT_EQ(root->data, 100);
   EXPECT_EQ(root->height, 1);

   EXPECT_EQ(root->left->data, 50);
   EXPECT_EQ(root->right->data, 200);
}

TEST_F(avlTest, deletion)
{
   avlTree avl;

   avl.insert(100);
   avl.insert(50);
   avl.insert(200);
   avl.insert(20);


   EXPECT_EQ(avl.getSize(), 4);

   avlNode* root = avl.getRoot();

   EXPECT_EQ(root->data, 100);
   EXPECT_EQ(root->height, 2);

   EXPECT_EQ(root->left->data, 50);
   EXPECT_EQ(root->left->left->data, 20);
   EXPECT_EQ(root->right->data, 200);

   avl.deleteNode(20);

   EXPECT_EQ(root->data, 100);
   //EXPECT_EQ(root->height, 1);

   EXPECT_EQ(root->left->data, 50);
   //EXPECT_EQ(root->left->left, nullptr);




   EXPECT_EQ(root->right->data, 200);
}
