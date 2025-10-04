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
    cout << "Y((our project is ready to go!" << endl;
    Sequence s(6);
    s.push_back("hello");
    s.push_back("bye");
    s.push_back("hi");
    cout << s ;
    cout << s.back() << endl;
    s.pop_back();
    cout << s ;
    cout << s.front() << endl;
    cout << s.back() << endl;
    cout << s.empty() << endl;
    cout << s.size() << endl;
    s.erase(0);
    cout << s ;
    s.erase(0);
    cout << s;
    s.push_back("HI");
    s.push_back("OK");
    s.push_back("NO");
    cout << s;
    s.erase(2);
    cout << s;
    s.push_back("OH");
    s.push_back("KO");
    cout << s;
    s.erase(0,4);
    cout << s;
    s.insert(0,"HELLO");
    cout << s;
    s.insert(0,"BYE");
    cout << s;
    cout << s.size() << endl;
    s.insert(1,"OK");
    cout << s;
    cout << s.size() << endl;
    s.insert(3,"KO");
    cout << s;

    //
    s[0] = "HELLO";
    s[1] = "BYE";
    cout << s;
    return 0;
}