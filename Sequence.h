#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
using namespace std;

// this is the node of the sequence which contain item, next and prev.
struct SequenceNode {
public:
    string item;
    SequenceNode *next;
    SequenceNode *prev;
    SequenceNode(): next(nullptr), prev(nullptr) {}
    SequenceNode(string item): item(item), next(nullptr), prev(nullptr) {}
};

class Sequence {
public:
    // length of sequence
    size_t length = 0;
    // first node is head
    SequenceNode* head;
    // last node is tail
    SequenceNode* tail;
    // default constructor
    Sequence();
    // deconstructor
    ~Sequence();
    // constructor with size
    Sequence(size_t size);
    // copy constructor
    Sequence(const Sequence &other);
    // equal opeartor function
    Sequence &operator=(const Sequence &other);
    // [] opeartor function
    string &operator[](size_t index);
    // push back function to push item at the last node.
    void push_back(string item);
    // pop back function to remove item of last node.
    void pop_back();
    // insert function to insert items at index size.
    void insert(size_t index, string item);
    // returns head the first node.
    string front() const;
    // returns tails the last node.
    string back() const;
    // check whether sequence is empty
    bool empty() const;
    // returns size of sequence
    size_t size() const;
    // to delete all the nodes
    void clear();
    // to erase specific node at index.
    void erase(size_t index);
    // to erase node from index till count.
    void erase(size_t index, size_t count);
    // << cout operator
    friend ostream &operator<<(ostream &os, const Sequence &seq);

};
#endif
