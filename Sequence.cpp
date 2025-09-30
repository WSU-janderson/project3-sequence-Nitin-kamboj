#include <iostream>
#include "Sequence.h"
using namespace std;

// default constructor
Sequence::Sequence(size_t size) {
}
// creates copy of constructor
Sequence::Sequence(const Sequence &other) {

}

//
Sequence &Sequence::operator=(const Sequence &other) {

}

//
string &Sequence::operator[](size_t index) {

}

//
void Sequence::push_back(string item) {
    Node *newNode = new Node(item);


    if (head == nullptr) {
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else {
        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

}


//
void Sequence::pop_back() {

    Node *curr = head;
    if (curr == nullptr) {
        throw exception();
    }

    if (curr->next == nullptr) {
        delete head;
        head = nullptr;
    }
    else {
        while (curr ->next != nullptr) {
            curr = curr -> next;
        }

        Node* nodeToDelete = curr;
        // last value if done push_back
        curr = curr->prev;
        // so that value next points to nullptr
        curr->next = nullptr;
        delete nodeToDelete;
    }
}

//
void Sequence::insert(size_t index, string item) {

    Node *newNode = new Node(item);
    size_t count = 0;
    Node *curr = head;
    if (head == nullptr) {

    }
    if (index == 0) {
        newNode->item = item;
        newNode->next = curr;
        curr->prev = newNode;


        newNode->next = head;

    }
    else {
        while (curr != nullptr && count < index) {
            curr = curr->next;
            count++;
        }

        // prevoius pointer
        Node* previousPointer = curr->prev;
        curr->prev = newNode;
        previousPointer->next = newNode;
    }
}

//
string Sequence::front() const {

}

//
string Sequence::back() const {

}

//
bool Sequence::empty() const {

}

//
size_t Sequence::size() const{

}

//
void Sequence::clear() {

}

//
void Sequence::erase(size_t position) {

}

//
void Sequence::erase(size_t position, size_t count) {

}

//
// friend ostream &operator<<(ostream &os, const Sequence &seq) {
//
// }

