# PriorityQueue
A simple implmentation of my own priority queue

# Purpose
This is the first implementation I have ever made with a priority queue. The usage of the priority queue is implemented by a Binary Search Tree. The queue uses a inorder traversal method to tranverse through the queue. The unique aspect of this 
implemantation of the priority queue is that the items that repeat aren't  
deleted, instead it's linked into the same branch in the order that it was 
inserted from the oldest to the most recent by a linked list. 

# Implementation
The Node Structure is as follows: 

Each node (NODE) contains:

priority: The priority of the element.

value: The value of the element.

dup: A boolean indicating if there are duplicates.

parent: Pointer to the parent node.

link: Pointer to the next node with the same priority. (the special thing about this queue)

left and right: Pointers to left and right child nodes.


This priority queue has constructors, destructors, an enqueue, a dequeue, size, and peek functions as well as operator overloads. It uses private methods that uses recursive methods for enqueue, dequeue, operator overloaders, and next functions. 

# Tests
This project also comes with Google tests that test the funcionality of the priority queue. It was my first time using any kind of testing
framework that wasn't the old debugging method. I implemented many asserts and used CMake to compile everything.

# Recent Changes
Changes Done in 2024:
Originally, this program was made in Clion. 
In order to make this code work in VSCode, I had to make a json pre-tests file. This a simple file that sets the Configuration for MacOS. In order to make the tests run in VSCode, you have to use the CMake extension tool. You first configure default, then set a build with the project name, finally, you launch. 

# Future Changes
An Error I wish to fix: I want to figure out how to use googletests as a folder in my project so the when I run the project in C++ mode, there won't be an error. However, I do realize that this error is only in the VSCode and CLion enviroments in which aren't set up correctly.
