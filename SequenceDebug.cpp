/**
 * SequenceDebug.cpp
 * Project 3
 * CS 3100
 *
 * In this file, you will write your tests as you implement Sequence. If you are using CLion, you need to select
 * SequenceDebug from the drop-down menu next to the Build (hammer icon) if it is on SequenceTestHarness
 */
#include <iostream>
#include "Sequence.h"
using namespace std;

int main() {
    cout << "Your project is ready to go!" << endl;
    Sequence s(8);
    s.push_back("hello");
    s.push_back("bye");
    s.push_back("hi");
    s.push_back("hello");
    s.push_back("bye");
    s.push_back("hi");
    cout << s << endl;
    cout << s.size() << endl;
    s.pop_back();
    cout << s << endl;
    cout << s.size() << endl;
    s.erase(1);
    cout << s << endl;
    cout << s.size() << endl;
    s[0] = "hello";
    s[1] = "bye";
    s[2] = "hi";
    cout << s << endl;
    cout << s.size() << endl;
    s[3] = "he";
    cout << s << endl;
    cout << s.size() << endl;
    s.erase(2,2);
    cout << s << endl;
    cout << s.size() << endl;
    s.erase(0);
    cout << s << endl;
    cout << s.size() << endl;
    // s.erase(5);
    // cout << s << endl;
    // cout << s.size() << endl;
    s.clear();
    cout << s << endl;
    cout << s.size() << endl;
    s.push_back("hello");
    s.push_back("bye");
    cout << s << endl;
    cout << s.size() << endl;
    s.insert(0, "llo");
    cout << s << endl;
    cout << s.size() << endl;
    s.insert(1, "bye");
    cout << s << endl;
    cout << s.size() << endl;
    s.insert(3, "hello");
    cout << s << endl;
    cout << s.size() << endl;
    Sequence s1;
    s1 = s;
    cout << s1 << endl;
    cout << s1.front() << endl;
    cout << s1.back() << endl;
    cout << s1.size() << endl;
    cout << s1.empty() << endl;
    s1.erase(0,2);
    cout << s1 << endl;
    s1.erase(1,2);
    cout << s1<< endl;
    s1.push_back("hj");
    cout << s1 << endl;
    Sequence data(3);
    for (int i = 0; i < 3; i++) {
        data[i] = "1";
    }
    cout << data << endl;
    // data.insert(5, "hdj");
    cout << data << endl;
    // cout << s.back() << endl;
    // s.pop_back();
    // cout << s ;
    // cout << s.front() << endl;
    // cout << s.back() << endl;
    // cout << s.empty() << endl;
    // cout << s.size() << endl;
    // s.erase(0);
    // cout << s ;
    // s.erase(0);
    // cout << s;
    // s.push_back("HI");
    // s.push_back("OK");
    // s.push_back("NO");
    // cout << s;
    // s.erase(2);
    // cout << s;
    // s.push_back("OH");
    // s.push_back("KO");
    // cout << s;
    // s.erase(0,4);
    // cout << s;
    // s.insert(0,"HELLO");
    // cout << s;
    // s.insert(0,"BYE");
    // cout << s;
    // cout << s.size() << endl;
    // s.insert(1,"OK");
    // cout << s;
    // cout << s.size() << endl;
    // s.insert(12,"KO");
    // cout << s;
    // //
    // s[0] = "HELLO";
    // s[1] = "BYE";
    // cout << s;
    return 0;
}