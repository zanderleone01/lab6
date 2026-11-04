/////////////////////////////////////////////////////////////////////
// Name: Zander Leone
// Date: 11/4/2026
// Class: CSCI 1470.04
// Semester: Fall 2026
// CSCI 1470 Instructor: Dr. Jonatan Reyes
// Program Description: Loads an array from a dictionary text file
//                      and prints how many word were loead. With
//                      const DEBUG on, it prints how long it takes
//                      for funtions to run, and prints the
//                      dictionary array.
///////////////////////////////////////////////////////////////////// 

#include<iostream>
#include <string>
#include<fstream>
#include<iomanip>
#include <chrono>
using namespace std;
using namespace chrono;

void fillArray(string dictionArr[], int size);
void loadArray(string dictionArr[], int size);
int countArray(string dictionArr[], int size);
void printArray(string dictionArr[], int size);

const bool DEBUG = true;

int main() {
    const int NUM_WORDS = 1000;
    string dictionArr[NUM_WORDS];


    cout << "-----------------------------" << endl;
    cout << " Hello! I'm a Spell Checker! " << endl;
    cout << "-----------------------------" << endl << endl;
    
    auto start = high_resolution_clock::now();
    fillArray(dictionArr, NUM_WORDS);
    auto end = chrono::high_resolution_clock::now();
    if (DEBUG) {
        duration<double> elapsed = end - start;
        cout << setprecision(2) << fixed << showpoint;
        cout << "DEBUG: Initialization took " << elapsed.count() << " microseconds." << endl;
    }

    start = high_resolution_clock::now();
    loadArray(dictionArr, NUM_WORDS);
    end = chrono::high_resolution_clock::now();
    if (DEBUG) {
        duration<double> elapsed = end - start;
        cout << setprecision(2) << fixed << showpoint;
        cout << "DEBUG: Loading took " << elapsed.count() << " microseconds." << endl;

        auto start = high_resolution_clock::now();
        printArray(dictionArr, NUM_WORDS);
        auto end = chrono::high_resolution_clock::now();
        if (DEBUG) {
            duration<double> elapsed = end - start;
            cout << setprecision(2) << fixed << showpoint;
            cout << "DEBUGGING: Printing took " << elapsed.count() << " microseconds." << endl;
        }
    }

    start = high_resolution_clock::now();
    cout << "Loaded " << countArray(dictionArr, NUM_WORDS) << " words from dictionary." << endl;
    end = chrono::high_resolution_clock::now();
    if (DEBUG) {
        duration<double> elapsed = end - start;
        cout << setprecision(2) << fixed << showpoint;
        cout << "DEBUGGING: Word count took " << elapsed.count() << " microseconds." << endl;
    }

    return 0;
}

void fillArray(string dictionArr[], int size) {
    for (int i = 0; i < size; i++) {
        dictionArr[i] = "";
    }
}

void loadArray(string dictionArr[], int size) {
    ifstream fin("dictionary.txt");

    if (fin) {
        for (int i = 0; i < size; i++) {
            fin >> dictionArr[i];
        }
    } else {
        cout << "Error: No dictionary file found." << endl;
    }

    fin.close();
}

int countArray(string dictionArr[], int size) {
    int counter = 0;

    for (int i = 0; i < size; i++){
        if (dictionArr[i] != ""){
            counter++;
        }
    }

    return counter;
}

void printArray(string dictionArr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << i + 1 << " " << dictionArr[i] << endl;
    }
}