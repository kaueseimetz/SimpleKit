#include <iostream>

using std::cout;
using std::endl;
using std::string;

void menu();

int main(){
    menu();

    return 0;
}

void menu(){
cout << "+===================================+" << endl;
cout << "|             SimpleKit             |" << endl;
cout << "+===================================+" << endl;
cout << "|  1. Get System Info               |" << endl;
cout << "|  2. Get Memory Status             |" << endl;
cout << "|  3. Get Network Status            |" << endl;
cout << "|  4. Get Current Timestamp         |" << endl;
cout << "+===================================+" << endl;
}