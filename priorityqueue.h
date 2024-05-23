// priorityqueue.h - the priorityqueue class
//
/* Name: Maria Guallpa
 * Class: CS 251 Fall 2022
 * Project 4: Priority Queue Class - Binary Tree Implementation
 * Machine Used: Clion on Mac
 * Date: 10/28/2022
 * */
#pragma once

#include <iostream>
#include <sstream>
#include <set>

using namespace std;

template<typename T>
class priorityqueue {
private:
    struct NODE {
        int priority;  // used to build BST
        T value;  // stored data for the p-queue
        bool dup;  // marked true when there are duplicate priorities
        NODE* parent;  // links back to parent
        NODE* link;  // links to linked list of NODES with duplicate priorities
        NODE* left;  // links to left child
        NODE* right;  // links to right child
    };
    NODE* root;  // pointer to root node of the BST (like pHead)
    int size;  // # of elements in the pqueue
    NODE* curr;  // pointer to next item in pqueue (see begin and next)
    //function below is used to print in an in order way
    void _inOrderTraversalPrinting(NODE *root, ostream &output)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            output << root->priority << " value: " << root->value << endl;
            _inOrderTraversalPrinting(root->left, output);
            _inOrderTraversalPrinting(root->link, output);
            _inOrderTraversalPrinting(root->right, output);
        }
    }
    //function below looks for the min priority
    NODE* minPriority(NODE *root)
    {
        NODE *begin = root;
        while (begin->left != nullptr)
        {
            begin = begin->left;
        }
        return begin;
    }
    //function below recursively goes and looks for the parent node. Used in next().
    NODE* parentRecursive(NODE *root)
    {
        NODE *begin = root;
        while (begin->parent != nullptr)
        {
            if (begin->priority < begin->parent->priority)
            {
                begin = begin->parent;
                return begin;
            }
            else
            {
                begin = begin->parent;
            }
        }
        return nullptr;
    }
    //function that copies a tree with a pre order traversal. Used in =operator.
    void _preOrderTraversalCopy(NODE *root, NODE *node)
    {
        if (root == nullptr)
        {
            return;
        }
        else
        {
            _preOrderTraversalCopy(root->left, node);
            enqueue(root->value, root->priority);
            _preOrderTraversalCopy(root->link, node);
            _preOrderTraversalCopy(root->right, node);
        }
    }
    //deletes all nodes
    void freeTree(NODE* node)
    {
        if (node == nullptr) return;
        freeTree(node->left);
        freeTree(node->right);
        freeTree(node->link);
        delete node;
    }
    //finds an equal
    bool _equal(NODE* node, NODE* other) const
    {
        if (node == nullptr && other == nullptr)
        {
            return true;
        }
        else if (node == nullptr)
        {
            return false;
        }
        else if (other == nullptr)
        {
            return false;
        }
        else {
            if (_equal(node->left, other->left) && node->priority == other->priority && _equal(node->link, other->link) && _equal(node->right, other->right))
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    //deletes node
    NODE* deletion(NODE *node)
    {
        if (node->left != nullptr)
        {
            NODE *temp = deletion(node->left);
            node->left = temp;
            return node;
        }
        else if (node->link != nullptr)
        {
            node->link->right = node->right;
            return node->link;
        }
        return node->right;
    }
public:
    //
    // default constructor: sets all data members to default values
    //
    // Creates an empty priority queue.
    // O(1)
    //
    priorityqueue()
    {
        // TO DO: write this function.
        root = nullptr;
        curr = nullptr;
        size = 0;
    }

    //
    // operator=
    //
    // Clears "this" tree and then makes a copy of the "other" tree.
    // Sets all member variables appropriately.
    // O(n), where n is total number of nodes in custom BST
    //
    priorityqueue& operator=(const priorityqueue& other)
    {
        // TO DO: write this function.
        if (this == &other)
            return *this;
        this->clear();
        this->root = nullptr;
        _preOrderTraversalCopy(other.root, root);
        return *this;
    }

    //
    // clear:
    //
    // Frees the memory associated with the priority queue but is public.
    // O(n), where n is total number of nodes in custom BST
    //
    void clear()
    {
        //DONE: write this function.
        if (root!= nullptr)
        {
            freeTree(root);
            root = nullptr;
        }
        if (curr != nullptr)
        {
            freeTree(curr);
            curr = nullptr;
        }
        size = 0;

    }

    //
    // destructor:
    //
    // Frees the memory associated with the priority queue.
    // O(n), where n is total number of nodes in custom BST
    //
    ~priorityqueue()
    {
        // TO DO: write this function.
        freeTree(curr);
    }

    //
    // enqueue:
    //
    // Inserts the value into the custom BST in the correct location based on
    // priority.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    void enqueue(T value, int priority)
    {
        // DONE: write this function.
        NODE *prev = nullptr;
        NODE *cur = root;
        while(cur != nullptr)
        {
            if (priority == cur->priority)
            {
                prev = cur;
                cur = cur->link;
            }
            else if (priority < cur->priority)
            {
                prev = cur;
                cur = cur->left;
            }
            else
            {
                prev = cur;
                cur = cur->right;
            }
        }
        NODE *n = new NODE();
        n->value = value;
        n->priority = priority;
        n->left = nullptr;
        n->right = nullptr;
        n->parent = nullptr;
        n->link = nullptr;
        if (prev == nullptr)
        {
            root = n;
        }
        else if(priority < prev->priority)
        {
            prev->left = n;
            n->parent = prev;
        }
        else if(priority > prev->priority)
        {
            prev->right = n;
            n->parent = prev;
        }
        else
        {
            prev->link = n;
            prev->dup = true;
            n->parent = prev;
        }
        size++;
    }

    //
    // dequeue:
    //
    // returns the value of the next element in the priority queue and removes
    // the element from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T dequeue()
    {
        T valueOut = peek();
        if (root != nullptr)
        {
            root = deletion(root);
            return valueOut;
        }
        return valueOut; // TO DO: update this return
    }

    //
    // Size:
    //
    // Returns the # of elements in the priority queue, 0 if empty.
    // O(1)
    //
    int Size()
    {
        return size;
    }

    //
    // begin
    //
    // Resets internal state for an inorder traversal.  After the
    // call to begin(), the internal state denotes the first inorder
    // node; this ensure that first call to next() function returns
    // the first inorder node value.
    //
    // O(logn), where n is number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (tree.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    void begin()
    {
        // TO DO: write this function.
        curr = minPriority(root);
    }

    //
    // next
    //
    // Uses the internal state to return the next inorder priority, and
    // then advances the internal state in anticipation of future
    // calls.  If a value/priority are in fact returned (via the reference
    // parameter), true is also returned.
    //
    // False is returned when the internal state has reached null,
    // meaning no more values/priorities are available.  This is the end of the
    // inorder traversal.
    //
    // O(logn), where n is the number of unique nodes in tree
    //
    // Example usage:
    //    pq.begin();
    //    while (pq.next(value, priority)) {
    //      cout << priority << " value: " << value << endl;
    //    }
    //    cout << priority << " value: " << value << endl;
    //
    bool next(T& value, int &priority)
    {
        // TO DO: write this function.
        NODE *temp = nullptr;
        NODE *temp2 = nullptr;
        while(curr != nullptr)
        {
            priority = curr->priority;
            value = curr->value;
            if (curr->link != nullptr)
            {
                temp = curr->right;
                temp2 = curr->parent;
                curr = curr->link;
                curr->right = temp;
                curr->parent = temp2;
                return true;
            }
            else if (curr->right != nullptr)
            {
                curr=curr->right;
                curr = minPriority(curr);
                return true;
            }
            else
            {
                curr = parentRecursive(curr);
                return true;
            }
        }
        return false; // TO DO: update this return


    }

    //
    // toString:
    //
    // Returns a string of the entire priority queue, in order.  Format:
    // "1 value: Ben
    //  2 value: Jen
    //  2 value: Sven
    //  3 value: Gwen"
    //
    string toString()
    {
        // TO DO: write this function.
        string str = " ";
        if (root == nullptr)
            return str;
        stringstream s;
        _inOrderTraversalPrinting(root, s);
        str = s.str();
        return str; // TO DO: update this return
    }

    //
    // peek:
    //
    // returns the value of the next element in the priority queue but does not
    // remove the item from the priority queue.
    // O(logn + m), where n is number of unique nodes in tree and m is number of
    // duplicate priorities
    //
    T peek()
    {
        // TO DO: write this function.
        T valueOut;
        curr = minPriority(curr);
        valueOut = curr->value;
        return valueOut; // TO DO: update this return
    }

    //
    // ==operator
    //
    // Returns true if this priority queue as the priority queue passed in as
    // other.  Otherwise returns false.
    // O(n), where n is total number of nodes in custom BST
    //
    bool operator==(const priorityqueue<int> *other) const
    {
        if (_equal(root, other->root) || (this = other))
        {
            return true;
        }
        return false; // TO DO: update this return
    }

    //
    // getRoot - Do not edit/change!
    //
    // Used for testing the BST.
    // return the root node for testing.
    //
    void* getRoot() {
        return root;
    }
};
