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
        left = nullptr;
        right = nullptr;
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

        void insert(int data, avlNode* &p);

        avlNode* search(int data, avlNode* p);

        avlNode* findMin(avlNode* p);
        
        void rotateLL(avlNode* &p);

        void rotateLR(avlNode* &p);

        void rotateRR(avlNode* &p);

        void rotateRL(avlNode* &p);


    public:
        avlTree();

        ~avlTree();

        void insert(int data);

        bool search(int data);
        
        void deleteNode(int data);
        
        int getSize();

        int findMin();

        int height(avlNode* p);
        
        avlNode* getRoot(); // for test purposes

};