/*
Filename: iterator.cpp 
Section: OOP344C
Description: Attempt at a doubly linked list
Name: Brad Clement
Student Id: 062-310-107
Date Modified: October, 20th 2013
*/

#include <iostream>
#include "iterator.h"
#include "node.h"

IteratorDLL::IteratorDLL() : current(nullptr) {}

void IteratorDLL::copyNode(Node* n)
{
   if(n)
   {
      current=n;
   }
}

IteratorDLL& IteratorDLL::operator--()
{
   current=current->prev;
   return *this;
}

IteratorDLL& IteratorDLL::operator++()
{
   current=current->next;
   return *this;
}

int IteratorDLL::getCurrent()
{
   if(current)
   {
      return current->data;
   }
}

IteratorDLL::~IteratorDLL()
{
   if(current!=nullptr)
   {
      delete current;
   }
}