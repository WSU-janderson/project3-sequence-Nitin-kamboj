#include <iostream>
#include "Sequence.h"
using namespace std;

// default constructor
// Initializes an empty sequence with head and tail as nullptr
// and sets the initial length to 0.
Sequence::Sequence() {
    this->head = nullptr;
    this->tail = nullptr;
    length = 0;
}
// constructor with given length
// Creates a sequence of given length 'len' where each node
// initially contains the string "???" as its item value.
Sequence::Sequence(size_t len) {
    length = len;
    int i = 0;
    this->head = nullptr;
    this->tail = nullptr;
    while (i < len) {
        // item of newnode is set to "???"
        SequenceNode *newNode = new SequenceNode("???");

        // check first node
        if (head == nullptr) {
            head = newNode;
            // newNode->item = "???";
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
// Creates a deep copy of another Sequence object.
// Each node from 'other' is copied into a new node.
Sequence::Sequence(const Sequence &other) {
SequenceNode *curr = other.head;

        while (curr != nullptr) {
            push_back(curr->item);
            curr = curr->next;
    }
}

// deconstructor
// Frees all dynamically allocated memory and clears the list.
Sequence::~Sequence() {
    clear();
    delete head;
    delete tail;
}
// Assignment Operator
// Clears the current sequence and deep copies another sequence.
Sequence &Sequence::operator=(const Sequence &other) {
    SequenceNode *otherCurr = other.head;
    // clear the sequence first so that we may copy from first to other sequence.
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

// Operator [] Overload
// Provides access to the element at a given index.
// Throws exception if index is invalid.
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

// push_back()
// Adds a new node containing 'item' at the end of the list.
void Sequence::push_back(string item) {
    SequenceNode *newNode = new SequenceNode(item);


    if (head == nullptr) {
        // First node case
        head = newNode;
        tail = newNode;
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
    }
    else {
        // Traverse to the end and attach new node
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


// pop_back()
// Removes the last node from the list.
// Throws exception if list is empty.
void Sequence::pop_back() {

    SequenceNode *curr = head;
    if (curr == nullptr) {
        throw exception();
    }

    if (curr->next == nullptr) {
        // Only one node in the list
        delete head;
        head = nullptr;
        tail = nullptr;
    }
    else {
        // Traverse to last node
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

// insert()
// Inserts a new node with 'item' at the given index.
void Sequence::insert(size_t index, string item) {
    if (index > length) {
        throw out_of_range("Sequence is out of range");
    }

    SequenceNode *newNode = new SequenceNode(item);
    size_t count = 0;
    SequenceNode *curr = head;
    // Insert at beginning
    if (head == nullptr && index == 0) {
        head = newNode;
        newNode->item = item;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        tail = newNode;
    }
    // Insert before current head
    else if (index == 0) {
        newNode->next = head;
        newNode->prev = nullptr;
        curr->prev = newNode;
        head = newNode;

    }
    // Insert in the middle or end
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
            // Insert at end
            tail = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
    length++;

}

// Returns the item at the beginning of the list.
string Sequence::front() const {
    if (head == nullptr) {
        throw exception();
    }
        return head->item;
}

// Returns the item at the end of the list.
string Sequence::back() const {
    SequenceNode* curr = head;
    if (curr == nullptr) {
        throw exception();
    }
        while (curr != nullptr) {
            if (curr->next == nullptr) {
                break;
            }
            curr = curr->next;
    }
    return curr->item;
}

// Returns true if the list is empty, false otherwise.
bool Sequence::empty() const {
    if (head != nullptr) {
        return false;
    }
    return true;
}

// Returns the number of elements in the list by traversal.
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

// Deletes all nodes and resets the sequence.
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

// Deletes the node at the given position.
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
     if (curr == head) {
        head = head->next;
        if (head != nullptr) {
            head->prev = nullptr;
        }
        else {
            tail = nullptr;
        }

    }
    else if (curr == tail) {
        // Deleting the last node
        tail = curr->prev;
        tail->next = nullptr;
    }
    else {
        // Deleting a middle node
        SequenceNode *posPrev = curr->prev;
        SequenceNode *posNext = curr->next;
        posPrev->next = posNext;
        posNext->prev = posPrev;

    }
    delete curr;
    length--;
}

// Removes 'count' nodes starting from 'position'.
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
    if (position == 0) {
        // Deleting from the start
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
            nodeToConnected->prev = curr;
        }
        else {
            // Deleting till end
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

// Prints the sequence in a readable format like [a, b, c]
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