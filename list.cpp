/*
Filename: list.cpp 
Section: OOP344C
Description: Attempt at a doubly linked list
Name: Brad Clement
Student Id: 062-310-107
Date Modified: October, 26th 2013
*/

#include <iostream>
#include "list.h"

/********************/
//Iterator DLL Class//
/********************/

IteratorDLL::IteratorDLL() : current(nullptr) {}

// move to the next node (if it exists)
IteratorDLL& IteratorDLL::operator++(int)
{
   if(current->next)
   {
      current=current->next;
   }
   return *this;
}

// move to the previous node (if it exists)
IteratorDLL& IteratorDLL::operator--(int)
{
   if(current->prev)
   {
      current=current->prev;
   }
   return *this;
}

// reuturns the current value in the node
int IteratorDLL::getCurrent()
{
   if(current)
   {
      return current->data;
   }
}

// determines the distance between the two Iterators
int IteratorDLL::getDistance(IteratorDLL& n1,IteratorDLL& n2)
{
   int firstD=0,secondD=0;
   int distance=0;

   //create temp node to revert to original
   Node* temp1=new Node();
   Node* temp2=new Node();
   temp1=n1.current;
   temp2=n2.current;

   //count the first itrator from current node
   while(n1.current->next!=nullptr)
   {
      n1.current=n1.current->next;
      firstD++;
   }

   //count the second itrator from current node
   while(n2.current->next!=nullptr)
   {
      n2.current=n2.current->next;
      secondD++;
   }

   if(firstD>secondD)
   {
      distance=firstD-secondD;
   }
   else
   {
      distance=secondD-firstD;
   }

   // reset to original
   n1.current=temp1;
   n2.current=temp2;

   return distance;
}

void IteratorDLL::copyNode(Node* n)
{
   if(n)
   {
      current=new Node();
      current=n;
   }
}

// destructor
IteratorDLL::~IteratorDLL()
{
   if(current!=nullptr)
   {
      delete current;
   }
}

/********************/
///LinkedList Class///
/********************/

LinkedList::LinkedList() : front(nullptr),back(nullptr), size(0) {}

// adds data to the front of the list
void LinkedList::addFront(int data)
{
   Node* n=new Node();
   n->data=data;
   n->next=front;

   if(!front)
   {
      front=n;
      back=n;
   }
   else
   {
      front->prev=n;
      n->next=front;
      front=n;
   }
   size++;
}

// adds data to the back of the list
void LinkedList::addBack(int data)
{
   Node* n=new Node();
   n->data=data;
   n->next=nullptr;

   if(!back)
   {
      front=n;
      back=n;
   }
   else
   {
      back->next=n;
      n->prev=back;
      back=n;
   }
   size++;
}

// removes data from the front of the list
void LinkedList::removeFront()
{
   if(front)
   {
      if(front == back)
      {
         front=nullptr;
         back=nullptr;
      }
      else
      {
         Node* n=front->next;
         n->prev=nullptr;
         delete front;
         front=n;
      }
      size--;
   }
}

// removes data from the back of the list
void LinkedList::removeBack()
{
   if(back)
   {
      if(front == back)
      {
         delete back;
         back=nullptr;
      }
      else
      {
         Node* n=back->prev;
         n->next=nullptr;
         delete back;
         back=n;
      }
      size--;
   }
}

// retrieves data stored at the front of the list
int LinkedList::getFront()
{
   return front->data;
}

// retrieves data stored at the back of the list
int LinkedList::getBack()
{
   return back->data;
}

// returns the size of the list
int LinkedList::sizeOf()
{
   return size;
}

// check to see if list is empty
bool LinkedList::isEmpty()
{
   return(!size);
}

// finds the front node and creates an iterator 
void LinkedList::frontList(IteratorDLL& iterf)
{
   if(front)
   {
      iterf.copyNode(front);
   }
}

// finds the back node and creates an iterator 
void LinkedList::backList(IteratorDLL& iterb)
{
   if(back)
   {
      iterb.copyNode(back);
   }
}

// deletes a node
void LinkedList::deleteNode(IteratorDLL& source)
{
   if(source.current)
   {
      // if there is only one node in the list
      if(front==back)
      {
         source.current=nullptr;
      }
      else if(source.current==front)
      {
         source.current=source.current->next;
      }
      else if(source.current==back)
      {
         source.current=source.current->prev;
      }
      else
      {
         source.current->prev->next=source.current->next;
         source.current->next->prev=source.current->prev;
      }
   }   
   size--;
}

// adds a node
void LinkedList::addNode(IteratorDLL& source,int newdata,int pos)
{
   if(source.current)
   {
      Node* newNode=new Node();

      for (int i=0;i<pos;i++)
      {
         source++;
      }

      if(source.current==front)
      {
         addFront(newdata);
      }
      else if(source.current==back)
      {
         addBack(newdata);
      }
      else
      {
         newNode->data=newdata;
         newNode->next=source.current;
         newNode->prev=source.current->prev;

         source.current->prev->next=newNode;
         source.current->next=newNode;
      }
   }
   size++;
}
// displats items in the list

void LinkedList::display() // displays data in order
{
   Node* n;
   int count=0;

   std::cout << "Current size of node is " << size << std::endl;

   for (n=front;n!=nullptr;n=n->next)
   {
      std::cout << "Data in node " << count << " is " << n->data << std::endl;
      count++;
   }
}

// destructor
LinkedList::~LinkedList()
{
   while(!isEmpty())
      removeFront();
}