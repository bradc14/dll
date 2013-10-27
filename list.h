/*
Filename: list.h 
Section: OOP344C
Description: Attempt at a doubly linked list
Name: Brad Clement
Student Id: 062-310-107
Date Modified: October, 25th 2013
*/

#include "node.h"

class IteratorDLL;

class LinkedList
{
private:
   Node* front;
   Node* back;
   int size;
public:
   LinkedList();
   void addFront(int data);
   void addBack(int data);
   void removeFront();
   void removeBack();
   int getFront();
   int getBack();
   int sizeOf();
   void frontList(IteratorDLL& iterf);
   void backList(IteratorDLL& iterb);
   void deleteNode(IteratorDLL& source);
   void addNode(IteratorDLL& source,int newdata,int pos);
   void display();
   bool isEmpty();
   ~LinkedList();
};


class IteratorDLL
{
private:  
   Node* current;
public:
   IteratorDLL();
   IteratorDLL& operator--(int);
   IteratorDLL& operator++(int);
   int getDistance(IteratorDLL& n1,IteratorDLL& n2);
   int getCurrent();
   void copyNode(Node* n);
   ~IteratorDLL();
   friend class LinkedList;
};