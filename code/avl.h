#pragma once

struct avlNode
{
    int data;
    int height;
    avlNode *left;
    avlNode *right;

    avlNode():avlNode(0){};

    avlNode(int x)
    {
        data = x;
        height = 0;
        left = NULL;
        right = NULL;
    }
};

class avlTree
{
    private:    
        int size;
        avlNode* root;

        void cleanup();
        void cleanup(avlNode* root);

        void balance(avlNode* &p);

        avlNode* insert(int data, avlNode* p);

    public:
        avlTree();

        ~avlTree();

        void insert(int data);

        void deleteNode(int data);
        
        int getSize();

        int findMin();

        bool search();

        int height(avlNode* p);

        void rotateLL(avlNode* &p);

        void rotateLR(avlNode* &p);

        void rotateRR(avlNode* &p);

        void rotateRL(avlNode* &p);

};