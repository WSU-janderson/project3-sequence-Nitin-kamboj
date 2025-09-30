#include <iostream>
using namespace std;
class Sequence {
    public:
    string value;
    Sequence *next;
    Sequence *prev;
    Sequence();
    ~Sequence();
    Sequence(size_t size);
    Sequence(const Sequence &other);
    Sequence &operator=(const Sequence &other);
    Sequence &operator[](size_t index);
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