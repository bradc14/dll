/*
Filename: iterator.h 
Section: OOP344C
Description: Attempt at a doubly linked list
Name: Brad Clement
Student Id: 062-310-107
Date Modified: October, 20th 2013
*/

class IteratorDLL
{
private:
   Node* current;
   IteratorDLL(const IteratorDLL&);
   IteratorDLL& operator=(const IteratorDLL&);
public:
   IteratorDLL();
   void copyNode(Node* n);
   IteratorDLL& operator--();
   IteratorDLL& operator++();
   int getCurrent();
   ~IteratorDLL();
};