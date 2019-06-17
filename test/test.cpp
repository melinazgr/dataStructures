//#include "test_minheap.h"
#include "test_maxheap.h"
#include "test_hash.h"
//#include "test_avl.h"
#include "test_graph.h"

int main(int argc, char **argv) 
{
   ::testing::InitGoogleTest(&argc, argv);
   return RUN_ALL_TESTS();
}