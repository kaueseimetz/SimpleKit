#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::cin;

int GetMenuResponse();
string strip(string &input);

int main(){

    return 0;
}

int GetMenuResponse(){
    cout << "+===================================+" << endl;
    cout << "|             SimpleKit             |" << endl;
    cout << "+===================================+" << endl;
    cout << "|  1. Get System Info               |" << endl;
    cout << "|  2. Get Memory Status             |" << endl;
    cout << "|  3. Get Network Status            |" << endl;
    cout << "|  4. Get Current Timestamp         |" << endl;
    cout << "|  0. Exit App                      |" << endl;
    cout << "+===================================+" << endl;
    cout << "\n";
    cout << "What you gonna do? >" << endl;
    string response;
    std::cin >> response;

    if (response == "1"){
        return 1;
    } else if (response == "2"){
        return 2;
    } else if (response == "3"){
        return 3;
    } else if (response == "4"){
        return 4;
    } else if (response == "0"){
        return 0;
    } else {
        return -1;
    }
}

string strip(string &input){
    string newString;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            newString += input[i];
        }
    }
    return newString;
}