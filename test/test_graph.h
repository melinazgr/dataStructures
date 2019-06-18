#include "gtest/gtest.h"
#include "graph.cpp"
#include <iostream>
#include <fstream>

using namespace std;

class graphTest : public ::testing::Test 
{
    protected:
        graphTest() {}
        ~graphTest() override{}
};

TEST_F(graphTest, graphInsert2)
{
    graph gr;

    gr.insertEdge(100, 100);
    EXPECT_EQ(gr.getSize(), 1);
    EXPECT_EQ(gr.connectedComponents(), 1);

    gr.insertEdge(101, 101);
    EXPECT_EQ(gr.getSize(), 2);
    EXPECT_EQ(gr.connectedComponents(), 2);

    gr.insertEdge(100, 101);
    EXPECT_EQ(gr.getSize(), 2);
    EXPECT_EQ(gr.connectedComponents(), 1);

    gr.deleteEdge(100,101);
    EXPECT_EQ(gr.getSize(), 2);
    EXPECT_EQ(gr.connectedComponents(), 2);
}

 TEST_F(graphTest, graphInsert5)
{
    graph gr;


    gr.insertEdge(100, 101);
    gr.insertEdge(100, 104);
    gr.insertEdge(101, 102);
    gr.insertEdge(101, 103);
    gr.insertEdge(101, 104);
    gr.insertEdge(102, 103);
    gr.insertEdge(103, 104);

    gr.print("graphInsert5a.txt");


    EXPECT_EQ(gr.getSize(), 5);
    EXPECT_EQ(gr.connectedComponents(), 1);
    EXPECT_EQ(gr.spanningTree(), 4);


    gr.deleteEdge(101,102);
    gr.deleteEdge(102,103);

    gr.print("graphInsert5b.txt");

    EXPECT_EQ(gr.connectedComponents(), 2);
    EXPECT_EQ(gr.spanningTree(), 3);
    

}
