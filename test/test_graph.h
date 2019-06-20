#include "gtest/gtest.h"
#include "graph.cpp"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class graphTest : public ::testing::Test 
{
    protected:
        graphTest() {}
        ~graphTest() override{}
};

TEST_F(graphTest, graphInsert2)
{
    Graph gr;

    gr.insertEdge(100, 100);
    EXPECT_EQ(gr.getSize(), 1);
    EXPECT_EQ(gr.connectedComponents(), 1)<<"error 1";

    gr.insertEdge(101, 101);
    EXPECT_EQ(gr.getSize(), 2);
    EXPECT_EQ(gr.connectedComponents(), 2)<<"error 2";

    gr.insertEdge(100, 101);
    EXPECT_EQ(gr.getSize(), 2);
    ASSERT_EQ(gr.connectedComponents(), 1)<<"error 3";

    gr.deleteEdge(100,101);
    EXPECT_EQ(gr.getSize(), 2);
    EXPECT_EQ(gr.connectedComponents(), 2);
}

TEST_F(graphTest, graphInsert5)
{
    Graph gr;

    vector<int> st; 

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
    gr.spanningTree(st);

    EXPECT_EQ(st[0], 4);
    
    EXPECT_EQ(gr.shortestPath(100, 103), 2);

    gr.deleteEdge(101,102);
    gr.deleteEdge(102,103);

    gr.print("graphInsert5b.txt");
    
    st.clear();

    gr.spanningTree(st);
    EXPECT_EQ(st[0], 3);
    EXPECT_EQ(st[1], 0);
}

TEST_F(graphTest, shortestWeight)
{
    Graph gr;

    vector<int> st; 

    gr.insertEdge(0, 1);
    gr.insertEdge(1, 2);
    gr.insertEdge(2, 3);
    gr.insertEdge(4, 5);
    gr.insertEdge(5, 3);
    gr.insertEdge(5, 2);
    gr.insertEdge(5, 6);
    gr.insertEdge(1, 7);
    gr.insertEdge(7, 8);
    gr.insertEdge(8, 6);
    gr.insertEdge(8, 2);

    gr.print("graphWeight.txt");

    EXPECT_EQ(gr.shortestPath(0, 8), 3);
    
    gr.spanningTree(st);
    EXPECT_EQ(st[0], 8);
}
