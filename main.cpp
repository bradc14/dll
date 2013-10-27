/*
Filename: main.cpp 
Section: OOP344C
Description: Attempt at a doubly linked list
Name: Brad Clement
Student Id: 062-310-107
Date Modified: October, 26th 2013
*/

#include <iostream>
#include "list.h"

int main()
{
   LinkedList test;
   IteratorDLL distance,node1,node2;

   int forward=0,backward=0;

   // loading of values
   std::cout << "We are adding 0,10,20,30,40,50,60,70 into the list" << std::endl;

   // adding values both to the front and to the back of the node
   test.addFront(30);
   test.addFront(20);
   test.addFront(10);
   test.addBack(40);
   test.addBack(50);
   test.addFront(0);
   test.addBack(60);
   test.addBack(70);
   test.display();
   std::cout << "----------------------------" << std::endl;

   std::cout << "We are now removing the first two items from the list" << std::endl;
   // remove nodes from the front
   test.removeFront();
   test.removeFront();
   test.display();
   std::cout << "----------------------------" << std::endl;

   std::cout << "We are now removing the last two items from the list" << std::endl;
   // remove nodes from the back
   test.removeBack();
   test.removeBack();
   test.display();
   std::cout << "----------------------------" << std::endl;

   // loading of values
   std::cout << "We are now adding 80,90,10 into the list" << std::endl;

   // adding values both to the front and to the back of the node
   test.addBack(80);
   test.addBack(90);
   test.addBack(100);
   test.display();
   std::cout << "----------------------------" << std::endl;

   //copy node over
   test.frontList(node1);
   test.frontList(node2);
   //end copy node

   //moving the first node
   std::cout << "NODE 1 IS CURRENTLY AT " << node1.getCurrent() << std::endl;
   std::cout << "How many nodes over do you want to go?" << std::endl;
   std::cin >> forward;

   for(int i=0;i<forward;i++)
      node1++;

   std::cout << "The current node is " << node1.getCurrent() << std::endl;
   std::cout << "----------------------------" << std::endl;

   std::cout << "How many nodes backwards do you want to go?" << std::endl;
   std::cin >> backward;
   for(int i=0;i<backward;i++)
      node1--;

   std::cout << "The current node is " << node1.getCurrent() << std::endl;
   std::cout << "----------------------------" << std::endl;
   //ending moving of first node

   //moving of second node
   std::cout << "NODE 2 IS CURRENTLY AT " << node2.getCurrent() << std::endl;
   std::cout << "How many nodes over do you want to go?" << std::endl;
   std::cin >> forward;

   for(int i=0;i<forward;i++)
      node2++;

   std::cout << "The current node is " << node2.getCurrent() << std::endl;
   std::cout << "----------------------------" << std::endl;
 
   std::cout << "How many nodes backwards do you want to go?" << std::endl;
   std::cin >> backward;
   for(int i=0;i<backward;i++)
      node2--;

   std::cout << "The current node is " << node2.getCurrent() << std::endl;
   std::cout << "----------------------------" << std::endl;
    //end of moving second node

   //finding the difference of both nodes
   std::cout << "The distance between the two iterators is " << distance.getDistance(node1,node2) << std::endl;
   std::cout << "----------------------------" << std::endl;
   //end finding difference

   //deleting nodes
   std::cout << "The current node is " << node1.getCurrent() << " in the first iterator and we will be deleting this node" << std::endl;
   test.deleteNode(node1);
   test.display();

   std::cout << "The current node is " << node2.getCurrent() << " in the second iterator and we will be deleting this node" << std::endl;
   test.deleteNode(node2);
   test.display();
   //end deleting nodes

   //adding nodes
   test.addNode(node1,1000,2);
   test.display();

   test.addNode(node2,500,4);
   test.display();
   //end adding nodes

	getchar();
}
