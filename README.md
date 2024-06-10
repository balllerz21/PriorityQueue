# PriorityQueue
This is the first implemnation I have ever made with a priority queue. The usage of the priority queue is implemented by a Binary Search Tree. The queue uses a inorder traversal method to tranverse through the queue. The unique aspect of this 
implemantation of the priority queue is that the items that repeat aren't  
deleted, instead it's linked into the same branch in the order that it was 
inserted from the oldest to the most recent by a linked list. 

This priority queue has constructors, destructors, an enqueue, a dequeue, size, and peek functions as well as operator overloads 

This project also comes with Google tests that test the funcionality of the priority queue.

Changes Done in 2024:
Originally, this program was made in Clion. 
In order to make this code work in VSCode, I had to make a json pre-tests file. This a simple file that sets the Configuration for MacOS. In order to make the tests run in VSCode, you have to use the CMake extension tool. You first configure default, then set a build with the project name, finally, you launch. 

An Error I wish to fix: I want to figure out how to use googletests as a folder in my project so the when I run the project in C++ mode, 