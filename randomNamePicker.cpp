// g++ -pedantic -Wall -Wextra -std=c++14 randomNamePicker.cpp -o randomNamePicker
#include <iostream>
#include <fstream>
#include <ctime>
#include <vector>
using namespace std;

int randomNumber(int maxIndex);
vector<string> readFile(string inputFile, int& n);
void randomOrder(vector<string> names);
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
        randomOrder(listOfNames);
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
        
        pause(1);
        cin.get();        
        names.erase(names.begin() + rand);
    }
    cout << "End of List.\n\n";
    pause(1);
    cin.get();
}

void pause(int dur){
    int temp = time(0) + dur;
    while(temp > time(0));
}