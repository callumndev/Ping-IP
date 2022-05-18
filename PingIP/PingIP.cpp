#include <iostream>
#include <string>
#include <windows.h>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Enter the target to ping: ";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::string ip;
    cin >> ip;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout << "Ping the specified host until stopped? ";

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
    std::string forever;
    cin >> forever;

    transform(forever.begin(), forever.end(), forever.begin(), [](unsigned char c) { return tolower(c); });;
    if (forever == "yes") {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "Pinging the specified host until stopped... ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        system(("ping -t " + ip).c_str());

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        system("pause");
    }
    else {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        cout << "Pinging the specified host... ";

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
        system(("ping " + ip).c_str());

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);
        system("pause");
    };
    
    return 0;

}