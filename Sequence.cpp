#include <iostream>
#include "Sequence.h"
using namespace std;

// default constructor
Sequence::Sequence() {
    this->head = nullptr;
    this->tail = nullptr;
    length = 0;
}
Sequence::Sequence(size_t len) {
    length = len;
    int i = 0;
    this->head = nullptr;
    this->tail = nullptr;
    while (i < len) {
        SequenceNode *newNode = new SequenceNode("???");


        if (head == nullptr) {
            head = newNode;
            newNode->item = "???";
            newNode->next = nullptr;
            newNode->prev = nullptr;
        }
        else {
            SequenceNode* curr = head;
            while (curr->next != nullptr) {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
            tail = newNode;
        }
        i++;
    }
}
// creates copy of constructor
Sequence::Sequence(const Sequence &other) {
SequenceNode *curr = other.head;

        while (curr != nullptr) {
            push_back(curr->item);
            curr = curr->next;
    }
    head = nullptr;
    tail = nullptr;
}

// deconstructor
Sequence::~Sequence() {
    clear();
    delete head;
    delete tail;
}
//
Sequence &Sequence::operator=(const Sequence &other) {
    SequenceNode *otherCurr = other.head;
    clear();

        while (otherCurr != nullptr) {

            SequenceNode *newNode = new SequenceNode();
            if (otherCurr->prev == nullptr) {
                // first node
                newNode->item = otherCurr->item;
                newNode->next = nullptr;
                newNode->prev = nullptr;
                this->head = newNode;
                this->tail = newNode;
            }
            else {
                SequenceNode *curr = head;
                while (curr->next!= nullptr) {
                    curr = curr->next;
                }
                curr->next = newNode;
                newNode->prev = curr;
                newNode->next = nullptr;
                newNode->item = otherCurr->item;
                this->tail= newNode;
            }
            otherCurr = otherCurr->next;
        }
        length = other.length;
    // while (curr != nullptr) {
    //     push_back(curr->item);
    //     curr = curr->next;
    // }
    return *this;
}


string& Sequence::operator[](size_t index) {
    SequenceNode *curr = head;
    int count = 0;
    while (curr != nullptr && count != index) {
        curr = curr->next;
        count++;
    }

    if (curr == nullptr) {
        throw out_of_range("Sequence is out of range");
    }
    return curr->item;
}

//
void Sequence::push_back(string item) {
    SequenceNode *newNode = new SequenceNode(item);


    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else {
        SequenceNode* curr = head;
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

    SequenceNode *curr = head;
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

        SequenceNode* nodeToDelete = curr;
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
    if (index > length-1) {
        throw out_of_range("Sequence is out of range");
    }

    SequenceNode *newNode = new SequenceNode(item);
    size_t count = 0;
    SequenceNode *curr = head;
    if (head == nullptr && index == 0) {
        head = newNode;
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        tail = newNode;
    }
    else if (index == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        curr->prev = newNode;
        head = newNode;

    }
    else {
        while (curr->next != nullptr && count < index) {
            curr = curr->next;
            count++;
        }

        // prevoius pointer
        if (index < length) {
            SequenceNode* previousPointer = curr->prev;
            curr->prev = newNode;
            previousPointer->next = newNode;
            newNode->next = curr;
            newNode->prev = previousPointer;
        }
        else  {
            tail = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
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
    SequenceNode* curr = head;
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
        return false;
    }
    return true;
}

//
size_t Sequence::size() const{
    size_t size = 0;
    SequenceNode *curr = head;
    while (curr != nullptr) {
        curr = curr->next;
        size++;
    }
    // cout << length << endl;
        return size;
}

//
void Sequence::clear() {
            SequenceNode *curr = head;
    while (curr != nullptr) {
        SequenceNode *nodeToDelete = curr;
        curr = curr->next;
        delete nodeToDelete;
    }
    head = nullptr;
    tail = nullptr;
    length = 0;
}

//
void Sequence::erase(size_t position) {
    size_t count = 0;
    SequenceNode *curr = head;
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
        SequenceNode *posPrev = curr->prev;
        SequenceNode *posNext = curr->next;
        posPrev->next = posNext;
        posNext->prev = posPrev;

    }
    delete curr;
    length--;
}

// Looks good for now
void Sequence::erase(size_t position, size_t count) {
    int tempCount = count;
    SequenceNode *curr = head;
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
                length--;
            }
            else {
                head = head->next;
                delete curr;
                length--;
                curr = head;
            }
        }
    }
    else {
        // Center node to be connected to the last after deleting between node
        if(curr->next != nullptr) {
            SequenceNode *nodeToConnected = curr->next;
            SequenceNode *nodeToDelete = curr;
            while (tempCount != 0) {
                curr = curr->prev;
                delete nodeToDelete;
                nodeToDelete = curr;
                tempCount--;
            }
            curr->next = nodeToConnected;
        }
        else {
            SequenceNode *nodeToDelete = curr;
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
  SequenceNode* newNode = seq.head;
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