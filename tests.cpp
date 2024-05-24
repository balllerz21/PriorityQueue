/* Name: Maria Guallpa
 * Class: CS 251 Fall 2022
 * Project 4: Priority Queue Class - Binary Tree Implementation
 * Machine Used: Clion on Mac
 * Date: 10/28/2022
 * */

#include <gtest/gtest.h>
#include "priorityqueue.h"
#include <iostream>
#include <sstream>
#include <set>
#include <map>
#include <vector>

using namespace std;
TEST(priorityqueue, SizeAndEnqueueAndDefaultConstructor)
{
    /*Size tests: These tests test the size of a priority queue. It also shows that the priority can have many
     *data types as values...*/
    //pq has 9 elements
    priorityqueue<int> pq;
    //pq2 has zero elements
    priorityqueue<int> pq2;
    //pq3 has 2 elements
    priorityqueue<string> pq3;
    //pq4 has 9 elements
    priorityqueue<char> pq4;
    //pq5 has 2 elements
    priorityqueue<double> pq5;
    //pq6 has 3 elements
    priorityqueue<int> pq6;
    //pq7 has 9 elements
    priorityqueue<int> pq7;
    //pq8 has 10 elements
    priorityqueue<int> pq8;
    int size = 9, size2 = 2, size3 = 3, size4 = 10;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    string vals2[] = {"Hello", "World"};
    double vals4[] = {21.1, 26.9};
    char vals3[] = {'A', 'b', 'c', 'd', 'e', 'q', 'q', 'w', 'r'};
    int vals5[] = {15, 16, 17, 6, 7, 8, 9, 2, 1, 20};
    int prs[] = {1, 2, 2, 2, 2, 5, 6, 7, 8};
    int prs2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int prs3[] = {3, 2, 6, 4, 5, 6, 7, 8, 9, 2};

    /*The use of the for loops to populate the queues with enqueue() proves that the enqueue() function works as there is a
     * size integer present ready to be compared in the size test asserts*/
    for (int i = 0; i < size; i++)
    {
        pq.enqueue(vals[i], prs[i]);
        pq8.enqueue(vals[i], prs[i]);
        pq4.enqueue(vals3[i], prs[i]);
    }
    for (int i = 0; i < size2; i++)
    {
        pq3.enqueue(vals2[i], prs[i]);
        pq5.enqueue(vals4[i], prs[i]);
    }
    for (int i = 0; i < size3; i++)
    {
        pq6.enqueue(vals[i], prs2[i]);
    }
    for (int i = 0; i < size4; i++)
    {
        pq7.enqueue(vals5[i], prs3[i]);
    }
    EXPECT_EQ(pq.Size(), 9);
    EXPECT_EQ(pq2.Size(), 0);
    EXPECT_EQ(pq3.Size(), 2);
    EXPECT_EQ(pq4.Size(), 9);
    EXPECT_EQ(pq5.Size(), 2);
    EXPECT_EQ(pq6.Size(), 3);
    EXPECT_EQ(pq7.Size(), 10);
    EXPECT_EQ(pq8.Size(), 9);
}

/*Tests clear() */
TEST(priorityqueue, Clear)
{
    priorityqueue<int> pq;
    priorityqueue<int> pq2;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 0; i < 3; i++)
    {
        pq.enqueue(vals[i], prs2[i]);
    }
    pq.clear();
    pq2.clear();
    EXPECT_EQ(pq.Size(), 0);
    EXPECT_EQ(pq2.Size(), 0);

    //repopulating the queue for double checking if clear works after it was called
    for (int i = 0; i < 3; i++)
    {
        pq.enqueue(vals[i], prs2[i]);
        pq2.enqueue(vals[i], prs2[i]);
    }
    pq.clear();
    pq2.clear();
    EXPECT_EQ(pq.Size(), 0);
    EXPECT_EQ(pq2.Size(), 0);
}

/*Tests toString()*/
TEST(priorityqueue, toString)
{
    priorityqueue<int> pq;
    priorityqueue<int> pq2;
    map<int, vector<int>> maps;
    map<int, vector<int>> maps2;
    map<int, vector<int>> maps3;
    map<int, vector<int>> maps4;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {1, 2, 2, 2, 2, 5, 6, 7, 8};
    int prs2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int prs3[] = {2, 3, 3, 5, 5, 6, 7, 8, 12};
    int prs4[] = {2, 5, 5, 5, 5, 5, 5, 5, 12};
    for (int i = 0; i < 9; i++)
    {
        pq.enqueue(vals[i], prs[i]);
        maps[prs[i]].push_back(vals[i]);
    }
    stringstream ss;
    for (auto e: maps) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            ss << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), ss.str());

    pq.clear();
    for (int i = 0; i < 9; i++)
    {
        pq.enqueue(vals[i], prs2[i]);
        maps2[prs2[i]].push_back(vals[i]);
    }

    stringstream aa;
    for (auto e: maps2) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            aa << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), aa.str());

    pq.clear();
    for (int i = 0; i < 9; i++)
    {
        pq.enqueue(vals[i], prs3[i]);
        maps3[prs3[i]].push_back(vals[i]);
    }
    stringstream bb;
    for (auto e: maps3) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            bb << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), bb.str());

    pq.clear();
    for (int i = 0; i < 9; i++)
    {
        pq.enqueue(vals[i], prs4[i]);
        maps4[prs4[i]].push_back(vals[i]);
    }
    stringstream cc;
    for (auto e: maps4) {
        int priority = e.first;
        vector <int> values = e.second;
        for (size_t j = 0; j < values.size(); j++){
            cc << priority << " value: " << values[j] << endl;
        }
    }
    EXPECT_EQ(pq.toString(), cc.str());
}

/*Tests =Operator*/
TEST(priorityqueue, equalsOperator)
{
    priorityqueue<int> pq;
    priorityqueue<int> pq2, pq3, pq4, pq5;
    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
    int prs[] = {1, 2, 2, 2, 2, 5, 6, 7, 8};

    for (int i = 0; i < 9; i++)
    {
        pq.enqueue(vals[i], prs[i]);
    }
    pq2 = pq;
    pq3 = pq2;
    pq4 = pq4;
    pq5 = pq4;

    EXPECT_EQ(pq.toString(), pq2.toString());
    EXPECT_EQ(pq2.toString(), pq3.toString());
    EXPECT_EQ(pq4.toString(), pq4.toString());
    EXPECT_EQ(pq5.toString(), pq4.toString());
}



/*I decided to test next and begin below....Just comment out the tests above and uncomment the ones below for
 * visual representation/confirmation plus extra tests made for functions as well*/
//int main()
//{
//    map<int, vector<int>> maps;
//    map<int, vector<string>> maps2;
//    int n = 9;
//    int vals[] = {15, 16, 17, 6, 7, 8, 9, 2, 1};
//    string vals2[] = {"Hi", "I'm", "testing", "strings", "with", "my", "priority", "queue", "...."};
//    int prs[] = {1, 2, 2, 2, 2, 5, 6, 7, 8};
//    int prs2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//    priorityqueue<int> pq;
//    priorityqueue<string> pq2;
//    for (int i = 0; i < n; i++)
//    {
//        pq.enqueue(vals[i], prs[i]);
//        pq2.enqueue(vals2[i], prs2[i]);
//        //maps[prs[i]].push_back(vals[i]);
//        //maps2[prs2[i]].push_back(vals2[i]);
//    }
//    cout << "Size: " << pq.Size() << endl;
//    string test = pq.toString();
//    cout << "Size: " << pq2.Size() << endl;
//    string test2 = pq2.toString();
//    cout << test2 << endl;
//    cout << "ans" << endl;
//    for (auto e: maps)
//    {
//        int priority = e.first;
//        vector <int> values = e.second;
//        for (size_t j = 0; j < values.size(); j++)
//        {
//            cout << priority << " value: " << values[j] << endl;
//        }
//    }
//    cout << "Size for pq: " << pq.Size() << endl;
//    cout << test << endl;
//    priorityqueue<int> pq3;
//    pq3 = pq;
//
//    cout << "Size for pq3: " << pq3.Size() << endl;
//    string test3 = pq3.toString();
//    cout << "Testing =operator" << endl;
//    cout << test3 << endl;
//    cout << "Testing begin() " << endl;
//    int value = 0;
//    int priority = 0;
//    pq.begin();
//    cout << "Testing next() " << endl;
//    while (pq.next(value, priority))
//    {
//        cout << priority << " value: " << value << endl;
//    }
//    cout << priority << " value: " << value << endl;
//
//    //system("leaks --list Project4");
//    return 0;
//}







