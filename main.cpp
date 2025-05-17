#include <iostream>
#include <infoware/system.hpp>
#include <infoware/cpu.hpp>

using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::to_string;

int Menu_Interface();
int SystemInfo_Interface();
string strip(string& input);
string addSpace(string& inputText, int maxSpace);

int main(){

    return 0;
}

int Menu_Interface(){
    cout << "+=========================================================+" << endl;
    cout << "|                        SimpleKit                        |" << endl;
    cout << "+=========================================================+" << endl;
    cout << "|   1. Get System Info                                    |" << endl;
    cout << "|   2. Get Memory Status                                  |" << endl;
    cout << "|   3. Get Network Status                                 |" << endl;
    cout << "|   4. Get Current Timestamp                              |" << endl;
    cout << "|   0. Exit App                                           |" << endl;
    cout << "+=========================================================+" << endl;
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

int SystemInfo_Interface(){
    string Info[5];

    Info[0] = iware::system::OS_info().full_name + " " + to_string(iware::system::OS_info().major) + "." + to_string(iware::system::OS_info().minor);
    Info[1] = iware::cpu::model_name();
    Info[2] = to_string(iware::cpu::quantities().physical);
    Info[3] = to_string(iware::cpu::quantities().logical);
    Info[4] = to_string(iware::system::memory().physical_total /(1024*1024)) + "MB";


    cout << "+=========================================================+" << endl;
    cout << "|                       System Info                       |" << endl;
    cout << "+=========================================================+" << endl;
    cout << "|                                                         |" << endl;
    cout << "| OS: " << Info[0] << string(addSpace(Info[0], 52)) << "|" << endl;
    cout << "| Model: " << Info[1] << string(addSpace(Info[1], 49)) << "|" << endl;
    cout << "| CPU Cores: " << Info[2] << string(addSpace(Info[2], 45)) << "|" << endl;
    cout << "| CPU Threads: " << Info[3] << string(addSpace(Info[3], 43)) << "|" << endl;
    cout << "| RAM Width: " << Info[4] << string(addSpace(Info[4], 45)) << "|" << endl;
    cout << "+=========================================================+" << endl;

    return 1;
}
string strip(string& input){
    string newString;
    for (int i = 0; i < input.length(); i++) {
        if (input[i] != ' ') {
            newString += input[i];
        }
    }
    return newString;
}
string addSpace(string& inputText, int maxSpace){
    int space2Fill = maxSpace - inputText.length();
    if (space2Fill > 0) { return string(space2Fill, ' '); }
    return "";
}