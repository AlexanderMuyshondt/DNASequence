//  main.cpp
//  DNASequence
//
//  Created by Alexander Muyshondt on 8/24/17.
//  Copyright © 2017 Alexander Muyshondt. All rights reserved.
//
//Reversing recombining


#include <iostream>
#include <cstdlib>
#include <string>
#include "DNASequence.h"
using namespace std;

// PROTOTYPE FUNCTIONS
void print_menu();
// Pre:  (none)
// Post: A menu of choices for this program is written to cout.
char get_user_command();
// Pre:  (none)
// Post: The user is prompted to enter a one character command.
//       The next character is read (skipping blanks and newline
//       characters).

int main() {
    char command;
    Sequence dnaTest;
    
    // Input and verify strand
    do {
    dnaTest.getString();
    }while(!dnaTest.verifyString());
    
    dnaTest.BuildStrand();
    
    do {
        print_menu();
        command = get_user_command();
        
        if (command == '1') {
            cout << "\nMutating DNA sequence...\n";
        }
        else if (command == '2') {
            cout << "\nSplicing DNA sequence...\n";
        }
        else if (command == '3') {
            cout << "\nTranscribing DNA sequence...\n";
        }
        else if (command == '4') {
            cout << "\nTranslate a mRNA sequence...\n";
        }
        else if (command == '5') {
            cout << "\nPrinting the DNA sequence...\n";
            dnaTest.PrintBoth();
        }
        else {
            if (command == '6')
                cout << "\nTerminating the program...\n\n";
            else
                cout << "\nInvalid choice. Please select a valid option from the menu.\n";
        }
    } while(command != '6');
    cout << "***************************************************************\n";
    cout << "*                                                             *\n";
    cout << "*                      PROGRAM TERMINATED                     *\n";
    cout << "*                                                             *\n";
    cout << "***************************************************************\n";

    return 0;
}

void print_menu() {
    cout << "******************** MENU ********************\n\n";
    cout << "1.) Mutate the DNA strand.\n";
    cout << "2.) Splice the DNA strand.\n";
    cout << "3.) Transcribe the DNA strand.\n";
    cout << "4.) Translate a mRNA strand.\n";
    cout << "5.) Display the complete DNA sequence.\n";
    cout << "6.) Terminate program.\n";
}

char get_user_command() {
    char command;
    
    cout << "Enter command: ";
    cin >> command;
    
    return command;
}


//for splicing
// Restriction enzymes cut a strand of DNA into two pieces at a
// specific location (the "binding site")
