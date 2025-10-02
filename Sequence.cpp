#include <iostream>
#include "Sequence.h"
using namespace std;

// default constructor
Sequence::Sequence() {
    this->head = nullptr;
    this->tail = nullptr;
}
Sequence::Sequence(size_t len) {
    length = 0;
    int i = 0;
    this->head = nullptr;
    this->tail = nullptr;
    while (i < len) {
        push_back("");
        i++;
    }
}
// creates copy of constructor
Sequence::Sequence(const Sequence &other) {

}

// deconstructor
Sequence::~Sequence() {

}

//
Sequence &Sequence::operator=(const Sequence &other) {

}


string &Sequence::operator[](size_t index) {
    Node *curr = head;
    int count = 0;
    while (count != index) {
        curr = curr->next;
        count++;
    }

}

//
void Sequence::push_back(string item) {
    Node *newNode = new Node(item);


    if (head == nullptr) {
        head = newNode;
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
        tail = newNode;
    }
    length++;

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
        tail = nullptr;
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
        tail = curr;
        delete nodeToDelete;
    }
    length--;
}

// Need to work on this
void Sequence::insert(size_t index, string item) {

    Node *newNode = new Node(item);
    size_t count = 0;
    Node *curr = head;
    if (head == nullptr && index == 0) {
        head = newNode;
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        tail = newNode;
    }
    if (index == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        if (curr != nullptr) {
            curr->prev = newNode;
        }
        head = newNode;

    }
    else {
        while (curr->next != nullptr && count < index) {
            curr = curr->next;
            count++;
        }

        // prevoius pointer
        Node* previousPointer = curr->prev;
        curr->prev = newNode;
        previousPointer->next = newNode;
    }
    length++;

}

//
string Sequence::front() const {
    if (head == nullptr) {
        throw exception();
    }
    else {
        return head->item;
    }
}

//
string Sequence::back() const {
    Node* curr = head;
    if (curr == nullptr) {
        throw exception();
    }
    else {
        while (curr != nullptr) {
            if (curr->next == nullptr) {
                break;
            }
            curr = curr->next;
        }
    }
    return curr->item;
}

//
bool Sequence::empty() const {
    if (head != nullptr) {
        return 0;
    }
    return 1;
}

//
size_t Sequence::size() const{
    size_t size = 0;
    Node *curr = head;
    while (curr != nullptr) {
        curr = curr->next;
        size++;
    }
        return size;
}

//
void Sequence::clear() {
            Node *curr = head;
    while (curr != nullptr) {
        Node *nodeToDelete = curr;
        curr = curr->next;
        delete nodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
}

//
void Sequence::erase(size_t position) {
    size_t count = 0;
    Node *curr = head;
    while (curr != nullptr &&  count < position) {
        curr = curr->next;
        count++;
    }
    // if no items in there
    if (curr == nullptr) {
        throw exception();
    }
    // if first item is getting removed
    else if (curr == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

    }
    else if (curr == tail) {
        tail = curr->prev;
        tail->next = nullptr;
    }
    else {
        Node *posPrev = curr->prev;
        Node *posNext = curr->next;
        posPrev->next = posNext;
        posNext->prev = posPrev;

    }
    delete curr;
}

// Looks good for now
void Sequence::erase(size_t position, size_t count) {
    int tempCount = count;
    Node *curr = head;
    size_t index = 0;
    while(curr != nullptr && index < position + count -1) {
        curr = curr->next;
        index++;
    }
    if (curr == nullptr) {
        throw exception();
    }
    else if (position == 0) {
        curr = head;
        while (count != 0) {
            count--;
            if (count == 0 && head->next == nullptr) {
                head = nullptr;
                tail = nullptr;
                delete curr;
            }
            else {
                head = head->next;
                delete curr;
                curr = head;
            }
        }
    }
    else {
        // Center node to be connected to the last after deleting between node
        if(curr->next != nullptr) {
            Node *nodeToConnected = curr->next;
            Node *nodeToDelete = curr;
            while (tempCount != 0) {
                curr = curr->prev;
                delete nodeToDelete;
                nodeToDelete = curr;
                tempCount--;
            }
            curr->next = nodeToConnected;
        }
        else {
            Node *nodeToDelete = curr;
            while (tempCount != 0) {
                curr = curr->prev;
                delete nodeToDelete;
                nodeToDelete = curr;
                tempCount--;
            }
            curr->next = nullptr;
            tail = curr;
        }

    }
}

//

ostream &operator<<(ostream &os, const Sequence &seq) {
  Node* newNode = seq.head;
    os << "[";
    while (newNode != nullptr) {
        if (newNode->next != nullptr) {
            os << newNode->item << ", ";
        }
        else {
            os << newNode->item ;
        }
        newNode = newNode->next;

    }
    os << "]" << endl;
    return os;
}