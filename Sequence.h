#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <iostream>
using namespace std;

struct Node {
public:
    string item;
    Node *next;
    Node *prev;
    Node(): next(nullptr), prev(nullptr) {}
    Node(string item): item(item), next(nullptr), prev(nullptr) {}
};

class Sequence {
public:
    size_t length;
    Node* head;
    Node* tail;
    Sequence();
    ~Sequence();
    Sequence(size_t size);
    Sequence(const Sequence &other);
    Sequence &operator=(const Sequence &other);
    string &operator[](size_t index);
    void push_back(string item);
    void pop_back();
    void insert(size_t index, string item);
    string front() const;
    string back() const;
    bool empty() const;
    size_t size() const;
    void clear();
    void erase(size_t index);
    void erase(size_t index, size_t count);
    friend ostream &operator<<(ostream &os, const Sequence &seq);

};
#endif
