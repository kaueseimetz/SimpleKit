#include <iostream>
#include <infoware/system.hpp>
#include <infoware/cpu.hpp>
#include <cstdlib>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::to_string;
using std::exit;

void Menu();
void SystemInfo();
void MemoryStatus();
void NetworkStatus();
void CurrentTimestamp();

void clearScreen();
string strip(string& input);
string relSpace(string& inputText, int maxSpace);

string response;

int main(){
    Menu();
    return 0;
}

void Menu(){
    clearScreen();

    cout << "███████╗██╗███╗   ███╗██████╗ ██╗     ███████╗     ██╗  ██╗██╗████████╗" << endl;
    cout << "██╔════╝██║████╗ ████║██╔══██╗██║     ██╔════╝     ██║ ██╔╝██║╚══██╔══╝" << endl;
    cout << "███████╗██║██╔████╔██║██████╔╝██║     █████╗       █████╔╝ ██║   ██║   " << endl;
    cout << "╚════██║██║██║╚██╔╝██║██╔═══╝ ██║     ██╔══╝       ██╔═██╗ ██║   ██║   " << endl;
    cout << "███████║██║██║ ╚═╝ ██║██║     ███████╗███████╗     ██║  ██╗██║   ██║   " << endl;
    cout << "╚══════╝╚═╝╚═╝     ╚═╝╚═╝     ╚══════╝╚══════╝     ╚═╝  ╚═╝╚═╝   ╚═╝   " << endl;
    
    cout << endl << endl;

    cout << "          ╔═════════════════════════════════════════════════╗          " << endl;
    cout << "          ║                                                 ║          " << endl;
    cout << "          ║                      MENU                       ║          " << endl;
    cout << "          ║                                                 ║          " << endl;
    cout << "          ║═════════════════════════════════════════════════║          " << endl;
    cout << "          ║                                                 ║          " << endl;
    cout << "          ║   1. Get System Info                            ║          " << endl;
    cout << "          ║   2. Get Memory Status                          ║          " << endl;
    cout << "          ║   3. Get Network Status                         ║          " << endl;
    cout << "          ║   4. Get Current Timestamp                      ║          " << endl;
    cout << "          ║   0. Exit App                                   ║          " << endl;
    cout << "          ║                                                 ║          " << endl;
    cout << "          ╚═════════════════════════════════════════════════╝          " << endl;
    cout << "\nWhat you wanna do?" << endl << ">";
    cin >> response;

    //Shall have a better way to do this, but i don't know it...
    if (response == "1"){
        SystemInfo();

    } else if (response == "2"){
        MemoryStatus();

    } else if (response == "3"){
        NetworkStatus();

    } else if (response == "4"){
        CurrentTimestamp();

    } else if (response == "0"){
        exit(0);

    } else {
        Menu();
    
    }
}

void SystemInfo(){
    string Info[5];

    Info[0] = iware::system::OS_info().full_name + " " + to_string(iware::system::OS_info().major) + "." + to_string(iware::system::OS_info().minor);
    Info[1] = iware::cpu::model_name();
    Info[2] = to_string(iware::cpu::quantities().physical);
    Info[3] = to_string(iware::cpu::quantities().logical);
    Info[4] = to_string(iware::system::memory().physical_total /(1024*1024)) + "MB";

    clearScreen();

    cout << "      ╔═════════════════════════════════════════════════════════╗      " << endl;
    cout << "      ║                       System Info                       ║      " << endl;
    cout << "      ║═════════════════════════════════════════════════════════║      " << endl;
    cout << "      ║                                                         ║      " << endl;
    cout << "      ║ OS: " << Info[0] << string(relSpace(Info[0], 52)) << "║      " << endl;
    cout << "      ║ Model: " << Info[1] << string(relSpace(Info[1], 49)) << "║      " << endl;
    cout << "      ║ CPU Cores: " << Info[2] << string(relSpace(Info[2], 45)) << "║      " << endl;
    cout << "      ║ CPU Threads: " << Info[3] << string(relSpace(Info[3], 43)) << "║      " << endl;
    cout << "      ║ RAM Width: " << Info[4] << string(relSpace(Info[4], 45)) << "║      " << endl;
    cout << "      ║                                                         ║      " << endl;
    cout << "      ║ 1. Previous Page                                        ║      " << endl;
    cout << "      ║ 0. Exit app                                             ║      " << endl;
    cout << "      ╚═════════════════════════════════════════════════════════╝      " << endl;
    cout << "\nWhat you wanna do?" << endl << ">";

    cin >> response;

    if (response == "1"){
        Menu();
    }else if (response == "0"){
        exit(0);
    }else {
        SystemInfo();
    }
}
void MemoryStatus(){
    clearScreen();
    const auto memory = iware::system::memory();
    string info[4];
    info[0] = to_string(memory.physical_available / (1024*1024)) + "MB";
    info[1] = to_string(memory.physical_total / (1024*1024)) + "MB"; 
    info[2] = to_string(memory.virtual_available / (1024*1024)) + "MB";
    info[3] = to_string(memory.virtual_total / (1024*1024)) + "MB";

    cout << "      ╔═════════════════════════════════════════════════════════╗      " << endl;
    cout << "      ║                      Memory Status                      ║      " << endl;
    cout << "      ║═════════════════════════════════════════════════════════║      " << endl;
    cout << "      ║                                                         ║      " << endl;
	cout << "      ║    Physical:                                            ║      " << endl;
	cout << "      ║        Available: " << string(info[0]) << string(relSpace(info[0], 38)) << "║      " << endl;
	cout << "      ║        Total: " << info[1]  << string(relSpace(info[1], 42)) << "║      " << endl;
	cout << "      ║    Virtual:                                             ║      " << endl;
	cout << "      ║        Available: " << info[2]  << string(relSpace(info[2], 38)) << "║      " << endl;
	cout << "      ║        Total: " << info[3]  << string(relSpace(info[3], 42)) << "║      " << endl;
    cout << "      ║                                                         ║      " << endl;
    cout << "      ║ 1. Previous Page                                        ║      " << endl;
    cout << "      ║ 0. Exit app                                             ║      " << endl;
    cout << "      ╚═════════════════════════════════════════════════════════╝      " << endl;
    cout << "\nWhat you wanna do?" << endl << ">";

    cin >> response;

    if (response == "1"){
        Menu();
    }else if (response == "0"){
        exit(0);
    }else {
        MemoryStatus();
    }
}
void NetworkStatus(){
    clearScreen();

    
    cout << "      ╔═════════════════════════════════════════════════════════╗      " << endl;
    cout << "      ║                     Network Status                      ║      " << endl;
    cout << "      ║═════════════════════════════════════════════════════════║      " << endl;
    cout << "      ║                                                         ║      " << endl;
    
    cout << "      ║                                                         ║      " << endl;
    cout << "      ║ 1. Previous Page                                        ║      " << endl;
    cout << "      ║ 0. Exit app                                             ║      " << endl;
    cout << "      ╚═════════════════════════════════════════════════════════╝      " << endl;
    cout << "\nWhat you wanna do?" << endl << ">";

    cin >> response;

    if (response == "1"){
        Menu();
    }else if (response == "0"){
        exit(0);
    }else {
        NetworkStatus();
    }
}
void CurrentTimestamp(){
    clearScreen();


    cout << "      ╔═════════════════════════════════════════════════════════╗      " << endl;
    cout << "      ║                    Current Timestamp                    ║      " << endl;
    cout << "      ║═════════════════════════════════════════════════════════║      " << endl;
    cout << "      ║                                                         ║      " << endl;
    
    cout << "      ║                                                         ║      " << endl;
    cout << "      ║ 1. Previous Page                                        ║      " << endl;
    cout << "      ║ 0. Exit app                                             ║      " << endl;
    cout << "      ╚═════════════════════════════════════════════════════════╝      " << endl;
    cout << "\nWhat you wanna do?" << endl << ">";

    cin >> response;

    if (response == "1"){
        Menu();
    }else if (response == "0"){
        exit(0);
    }else {
        CurrentTimestamp();
    }
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
string relSpace(string& inputText, int maxSpace){
    int space2Fill = maxSpace - inputText.length();
    if (space2Fill > 0) { return string(space2Fill, ' '); }
    return "";
}
void clearScreen(){
    #if defined(_WIN32) || defined(WIN32)
        system("cls");
    #else
        system("clear");
    #endif
}