#include "avl.h"

avlTree::avlTree()
{
    size = 0;
    root = NULL;
}

avlTree::~avlTree()
{
    cleanup();
}

void avlTree::cleanup()
{
    cleanup(root);
}

void avlTree::cleanup(avlNode* p)
{
    if(p)
    {
        cleanup(p->left);
        cleanup(p->right);
        delete p;
    }
}

avlNode* avlTree::insert(int data, avlNode* p)
{
    avlNode* t;

    if (p == NULL)
    {
        size++;
        t = new avlNode(data);
    }

    else if(data < p->data)
    {
        t = insert(data, p->left);
    }

    else
    {
        t = insert(data, p->right);
    }

    balance(p);

    return t;
}

void avlTree::insert(int data)
{
    if (root == NULL)
    {
        root = insert(data, root);
    }

    else
    {
        insert(data, root);
    }
}

int avlTree::height(avlNode* p)
{
    return p == NULL ? 0 : p->height;
}

//            O
//          O   O
//            O
//
void avlTree::rotateLL(avlNode* &a)
{
    avlNode* b = a->left;

    a->left = b->right;
    a->height = max(height(a->left), height(a->right)) + 1;

    b->right = a;
    b->height = max(height(b->left), height(b->right)) + 1;
    
    a = b;
}

void avlTree::rotateLR(avlNode* &a)
{
    rotateLL(a->left);
    rotateRR(a);
}

void avlTree::rotateRR(avlNode* &a)
{
    avlNode* b = a->right;

    a->right = b->left;
    a->height = max(height(a->right), height(a->left)) + 1;

    b->left = a;
    b->height = max(height(b->right), height(b->left)) + 1;
    
    a = b;
}

void avlTree::rotateRL(avlNode* &a)
{
    rotateRR(a->right);
    rotateLL(a);
}

void avlTree::balance(avlNode* &p)
{
    if (p == NULL)
    {
        return;
    }

    int balanceFactor = height(p->left) - height(p->right);

    if (balanceFactor == 2) // left heavy subtree
    {
        // check if we have to do LL or LR
        //
        // RR- child is left heavy
        // RL - child is right heavy

        if ((height(p->left->left) -  height(p->left->right)) > 0) 
        {
            rotateRR(p);
        }

        else
        {
            rotateRL(p);
        }
    }

    else if (balanceFactor == -2)
    {
        // check if we have to do RR or RL
        //
        // LL - child is right heavy
        // LR - child is left heavy

        if (height(p->right->right) - (height(p->right->left)) > 0) 
        {
            rotateLL(p);
        }

        else
        {
            rotateLR(p);
        }
    }

    p->height = max(height(p->left), height(p->right)) + 1;
}