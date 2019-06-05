#include "avl.h"

#include <iostream>
#include <limits>
#include <cstdint>
#include <algorithm>
using namespace std;

avlTree::avlTree()
{
    size = 0;
    root = nullptr;
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

int avlTree::getSize()
{
    return size;
}

void avlTree::insert(int data, avlNode* &p)
{
    if (p == nullptr)
    {
        size++;
        p = new avlNode(data);
    }

    else if(data < p->data)
    {
        insert(data, p->left);
    }

    else
    {
        insert(data, p->right);
    }

    balance(p);
}

void avlTree::insert(int data)
{
    insert(data, root);
}

int avlTree::height(avlNode* p)
{
    return p == nullptr ? -1 : p->height; 
}

bool avlTree::search(int data)
{
    return search(data, root) != nullptr;
}


avlNode* avlTree::search(int data, avlNode* p)
{
    if (p == nullptr)
    {
        return nullptr;
    }

    // go left
    if(p->data > data)
    {
        return search(data, p->left);
    }

    // go right
    else if(p->data < data)
    {
        return search(data, p->right);
    }

    else
    {
        return p;
    }
}

/*void avlTree::deleteNode(int data)
{
    avlNode* p = search(data, root);
    
    if(!p)
    {
        return;
    }

    if(p->left && p->right)
    {
        avlNode* n = findMin(p);
        p->data = n->data;

        avlNode* temp = p;
        
        // delete node n
        while(temp->left != n)
        {
            temp = temp->left;
        }

        temp->left = nullptr;
        
        delete n;
    }

    else if(p->left)
    {
        p->data = p->left->data;

        avlNode* temp = p->left;

        p->left = temp->left;
        p->right = temp->right;

        p->height--;
        delete temp;
    }

    else if(p->right)
    { 
        p->data = p->right->data;

        avlNode* temp = p->right;

        p->left = temp->left;
        p->right = temp->right;

        p->height--;
        delete temp;
    }

    else
    {
        avlNode* temp = root;
        
        while(temp->left != p && temp->right != p)
        {
            if(temp->data > p->data )
            {
                temp = temp->left;
            }

            else if(temp->data < p->data)
            {
                temp = temp->right;
            }
        }

        if(temp->right == p)
        {
            temp->right = nullptr;
        }

        else if(temp->left == p)
        {
            temp->left = nullptr;
        }
        
        delete p;
        p = temp;

        p->height--;
    }
    
    
    balance(p);
}*/

void avlTree::deleteNode(int data)
{
    deleteNode(data, root);
}

void avlTree::deleteNode(int data, avlNode* &p)
{
    if(!p)
    {
        return;
    }

    // go left
    if(p->data > data)
    {
        deleteNode(data, p->left);
    }

    // go right
    else if(p->data < data)
    {
        deleteNode(data, p->right);
    }

    else if(p->left && p->right)
    {
        avlNode* n = findMin(p);
        p->data = n->data;
        
        avlNode* temp = p;
        
        // delete node n
        while(temp->left != n)
        {
            temp = temp->left;
        }

        temp->left = nullptr;
        
        delete n;
    }

    else if(p->left)
    {
        avlNode* temp = p;
        p = p->left;
        delete temp;
    }

    else if(p->right)
    { 
        avlNode* temp = p;
        p = p->right;
        delete temp;
    }

    else
    {
        avlNode* temp = p;
        p = nullptr;
        delete temp;
    }
    
    size--;
    
    balance(p);
}

avlNode* avlTree::findMin(avlNode* p)
{
    while(p->left)
    {
        p = p->left;
    }

    return p;
}

int avlTree::findMin()
{
    // if the tree is empty return the minimun possible integer (32 bits)
    if(!root)
    {
        return INT32_MIN;
    }

    avlNode* min = findMin(root);
    return min->data;
}

//
// https://www.hackerrank.com/challenges/self-balancing-tree/problem
// https://www.tutorialspoint.com/data_structures_algorithms/avl_tree_algorithm.htm
//
//            O
//          O   O
//            O 
//
void avlTree::rotateLL(avlNode* &a)
{
    if(a->left)
    {
        avlNode* b = a->left;

        a->left = b->right;
        a->height = max(height(a->left), height(a->right)) + 1;

        b->right = a;
        b->height = max(height(b->left), height(b->right)) + 1;
        
        a = b;
    }

    else
    {
        avlNode* b = a->right;

        b->left = a;
        a->right = nullptr;

        a->height = max(height(a->left), height(a->right)) + 1;
        b->height = max(height(b->left), height(b->right)) + 1;

        a = b;
    }
    
}

void avlTree::rotateLR(avlNode* &a)
{
    rotateLL(a->left);
    rotateRR(a);
}

void avlTree::rotateRR(avlNode* &a)
{
    if(a->right)
    {
        avlNode* b = a->right;

        a->right = b->left;
        a->height = max(height(a->right), height(a->left)) + 1;

        b->left = a;
        b->height = max(height(b->right), height(b->left)) + 1;
        
        a = b;
    }
    
     else
    {
        avlNode* b = a->left;

        b->right = a;
        a->left = nullptr;

        a->height = max(height(a->left), height(a->right)) + 1;
        b->height = max(height(b->left), height(b->right)) + 1;

        a = b;

    }
}

void avlTree::rotateRL(avlNode* &a)
{
    rotateRR(a->right);
    rotateLL(a);
}

void avlTree::balance(avlNode* &p)
{
    if (p == nullptr)
    {
        return;
    }

    int balanceFactor = height(p->left) - height(p->right);

    if (balanceFactor == 2) // left heavy subtree
    {
        // check if we have to do LL or LR
        //
        // RR- child is left heavy
        // LR - child is right heavy

        if ((height(p->left->left) -  height(p->left->right)) > 0) 
        {
            rotateRR(p);
        }

        else
        {
            rotateLR(p);
        }
    }

    else if (balanceFactor == -2)
    {
        // check if we have to do RR or RL
        //
        // LL - child is right heavy
        // RL - child is left heavy

        if (height(p->right->right) - (height(p->right->left)) > 0) 
        {
            rotateLL(p);
        }

        else
        {
            rotateRL(p);
        }
    }

    p->height = max(height(p->left), height(p->right)) + 1;
}

avlNode* avlTree::getRoot()
{
    return root;
}