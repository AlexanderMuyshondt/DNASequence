//  DNASequence.cpp
//  DNASequence
//
//  Created by Alexander Muyshondt on 8/24/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.

#include <stdio.h>
#include <cstdlib>
#include <iostream>
#include "DNASequence.h"
using namespace std;

/*********************************** Constructor ***********************************/
Sequence::Sequence() {
    cout << "   DNA molecules consist of two biopolymer strands coiled around each other ";
    cout << "to form a double helix. The two DNA strands are composed of  simpler monomer ";
    cout << "units called nucleotides — cytosine (C), guanine (G), adenine (A), or thymine ";
    cout << "(T). The bases are bound together, according to base pairing rules (A with T, ";
    cout << "and C with G).\n";
    cout << "   This program accepts a valid DNA strand and displays a menu of options ";
    cout << "for the user.\n\n";
    
    head = nullptr;
    curr = nullptr;
    temp = nullptr;
}

/*********************************** Destructor ***********************************/
Sequence::~Sequence() {
    curr = head;
    
    while (curr != nullptr) {
        temp = curr->next;
        delete curr;
        curr = temp;
    }
    head = nullptr;
}

/********************************* getStringPrivate *********************************/
void Sequence::getStringPrivate() {
    cout << "Enter a valid DNA strand: ";
    cin >> strand;
    
    for (int i = 0; i < strand.length(); ++i) {
        strand[i] = toupper(strand[i]);
    }
}

/******************************* verifyStringPrivate *******************************/
bool Sequence::verifyStringPrivate(string strand) {
    
    cout << "Verifying that " << strand << " is a valid DNA strand...\n";
    
    bool status = false;
    
    for (int i = 0; i < strand.length(); ++i) {
        
        if(strand[i] == 'C') {
            status = true;
        }
        else if(strand[i] == 'G') {
            status = true;
        }
        else if(strand[i] == 'A') {
            status = true;
        }
        else if(strand[i] == 'T') {
            status = true;
        }
        else {
            cout << "\nInvalid strand.\n\n";
            status = false;
            return status;
        }
    }
    
    cout << "\nDNA sequence successfully validated.\n\n";
    return status;
}

/************************************* AddNode *************************************/
void Sequence::AddNode(char addData, char addData2) {
    // Creates a new nodePtr called n and creating a new node, and make nodePtr point
    // to the new node
    nodePtr n = new node;   // nodePtr is the same as node*
    n->next = nullptr;
    n->data = addData;      // Fills node with data that is passed into the function
    n->data2 = addData2;
    
    // Check if there is an existing linked list
    if (head != nullptr) {
        curr = head;
        // Check for end of list
        while (curr->next != nullptr) {
            curr = curr->next;
        }
        // Set last element to point to n
        curr->next = n;
    }
    // If no list exists
    else {
        head = n;
    }
}

/************************************ DeleteNode ************************************/
void Sequence::DeleteNode(char delData) {
    // Start at beginning of list, walk through until find data that was passed in
    nodePtr delPtr = nullptr;
    temp = head;
    curr = head;
    
    while (curr != nullptr && curr->data != delData) {
        temp = curr;
        curr = curr->next;
    }
    if (curr == nullptr) {
        cout << delData << " was not found.\n";
        delete delPtr;      // To avoid garbage
    }
    else {
        delPtr = curr;      // set deletion pointer to node to be deleted
        curr = curr->next;  // advance current
        temp->next = curr;  // Patch the linked list
        if(delPtr == head) {
            head = head->next;
            temp = nullptr;
        }
        delete delPtr;
        
        cout << delData << " was deleted.\n";
    }
}

/************************************ Print ************************************/
void Sequence::Print() {
    curr = head;
    if (curr == nullptr) {
        cout << "The list is empty.\n";
    }
    else {
        while(curr != nullptr) {
            cout << curr->data;
            curr = curr->next;
            }
        cout << endl;

    }
}

/************************************ Print2 ************************************/
void Sequence::Print2() {
    curr = head;
    if (curr == nullptr) {
        cout << "The list is empty.\n";
    }
    else {
        while (curr != nullptr) {
            cout << curr->data2;
            curr = curr->next;
            }
        cout << endl << endl;
    }
}

/****************************** BuildStrandPrivate ******************************/
void Sequence::BuildStrandPrivate() {
    
    for (int i = 0; i < strand.length(); i++) {
        if (strand[i] == 'C') {
            AddNode('C' , 'G');
        }
        else if (strand[i] == 'G') {
            AddNode('G' , 'C');
        }
        else if (strand[i] == 'A') {
            AddNode('A' , 'T');
        }
        else if (strand[i] == 'T') {
            AddNode('T' , 'A');
        }
        else {
            cout << "ERROR.\n";
        }
    }
}

/****************************** SplicePrivate ******************************/
void Sequence::SplicePrivate() {
    string base;
    
    cout << "Enter the target base: ";
    cin  >> base;

    
}

/***************************** BuildStrandPrivate_2 ****************************
 void BuildStrandPrivate_2();
 void BuildStrand_2() {
 return BuildStrandPrivate_2();
 }
void Sequence::BuildStrandPrivate_2() {
    nodePtr m = new node;   // nodePtr is the same as node*
    m->next = nullptr;
    
    curr = head;
    if(curr == nullptr) {
        cout << "ERROR.\n";
    }
    else {
        while(curr != nullptr) {
            if(curr->data == 'C') {
                AddNode('G');
            }
            else if(curr->data ==  'G') {
                AddNode('C');
            }
            else if(curr->data ==  'A') {
                AddNode('T');
            }
            else if(curr->data == 'T') {
                AddNode('A');
            }
            else {
                cout << "ERROR.\n";
            }
        }
    }
}
*/











