// g++ -pedantic -Wall -Wextra -std=c++14 randomNamePicker.cpp -o OutputTest
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
#include <algorithm>
using namespace std;

/**
    Randomly picks a number with the range of maxIndex
    Param maxIndex: Maximum size to randomly choose from
    Return: Random number between 1-maxIndex
*/
int randomNumber(int maxIndex);

/*
    Reads a list of names from a text file seperated by line & Stores them into a vector
    Additionally, keeps amount of names stored
    Param inputFile: File to read from
    Param n: Reference to int to store max size
    Return: Vector with all the names stored inside
*/
vector<string> readFile(string inputFile, int& n);

/*
    Generates a random list of names from the stored names
    Param names: Vector to pull names from
*/
void randomOrder(vector<string> names);

/*
    Rigs the random order by choosing who goes first
    Param names: Vector to pull names from
    Param rigged: Person to put at the top of the list
*/
void riggedOrder(vector<string> names, string rigged);

/*
    Pauses the console
    Param dur: Duration to pause the console for
*/
void pause(int dur);

int main(){
    string inputFile;
    cout << "\nFile Name to pull names from: ";
    cin >> inputFile;
    
    int totalNames = 0;
    vector<string> listOfNames = readFile(inputFile, totalNames);
    string userChoice;

    cout << "\nPress Enter to Continue\n";
    cout << "CTRL + C to Quit or close window\n\n\n";
    cin.get();
    while(true){
        string name;
        getline(cin, name);
        cout << "\n";
        riggedOrder(listOfNames, name);
    }
    return 0;
}

int randomNumber(int maxIndex){
    srand((int)time(0));
    return (rand() % maxIndex);
}

vector<string> readFile(string inputFile, int& n){
    vector<string> listOfNames;
    ifstream input;
    n = 0;
    input.open(inputFile);
    if(input.is_open()){
        string fromFile;
        do{
            input >> fromFile;
            listOfNames.push_back(fromFile);
            n++;
        }while(!input.eof());
        cout << "File Loaded\n\n";
        input.close();
        return listOfNames;
    }
    else{
        cout << "Error with Input File\n";
        exit(0);
    }
}

void randomOrder(vector<string> names){
    while(!names.empty()){
        int rand = randomNumber(names.size());
        cout << names[rand] << ", it's your turn!\n";
        for(int i = 0; i < (int)names[rand].length() + 17; i++){
            cout << "~";
        }     
        cout << "\n";
        names.erase(names.begin() + rand);
    }
    cout << "End of List.\n\n";
    pause(1);
}

void riggedOrder(vector<string> names, string rigged){
    vector<string>::iterator it;
    it = find(names.begin(), names.end(), rigged);
    if(it != names.end()){        
        names.erase(it);
        cout << rigged << ", it's your turn!\n";
        for(int i = 0; i < (int)rigged.length() + 17; i++){
            cout << "~";
        }
        cout << "\n";
    }
    randomOrder(names);
    
}

void pause(int dur){
    int temp = time(0) + dur;
    while(temp > time(0));
}