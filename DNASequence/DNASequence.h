//  DNASequence.h
//  DNASequence
//
//  Created by Alexander Muyshondt on 8/24/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.
//

#ifndef DNASequence_h
#define DNASequence_h
#include <string>
#include <iostream>

using namespace std;

class Sequence {
private:
    string strand;
    
    typedef struct node {
        
        char data;
        char data2;
        node *next;
        
    }* nodePtr; // nodePtr can be used as substitute for node*
    
    nodePtr head;
    nodePtr curr;
    nodePtr temp;
    
    // Private String Functions
    void getStringPrivate();
    void displayStringPrivate() {
        cout << strand;
    }
    bool verifyStringPrivate(string strand);
    
    // Private Node Functions
    void BuildStrandPrivate();
    void SplicePrivate();
    
public:
    Sequence();
    ~Sequence();
    
    // Public String Functions
    void getString() {
        getStringPrivate();
    }
    void displayString() {
        displayStringPrivate();
    }
    bool verifyString() {
        return verifyStringPrivate(strand);
    }
    
    // Public Node Functions
    void BuildStrand() {
        return BuildStrandPrivate();
    }
    void AddNode(char addData, char addData2);
    void DeleteNode(char delData);
    void Splice() {
        SplicePrivate();
    }
    void Print();
    void Print2();
    void PrintBoth() {
        Print();
        Print2();
    }
};


#endif /* DNASequence_h */
