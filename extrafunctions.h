#ifndef EXTRAFUNCTIONS_H
#define EXTRAFUNCTIONS_H
#include <iostream>
#include <fstream>
#include <vector>
#include <exception>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cmath>
#include <time.h>
#include <string.h>
#include <conio.h>
#include <Windows.h>
#define PI 3.141
#define encryptionvalue 10;

using namespace std;

string encryption(string pass)
{
    for (int i = 0; i < pass.length(); i++)
    {
        pass[i] = pass[i] - encryptionvalue;
    }
    return pass;
}

string decryption(string pass)
{
    for (int i = 0; i < pass.length(); i++)
    {
        pass[i] = pass[i] + encryptionvalue;
    }
    return pass;
}
void pressKey()
{
    cout << "\nPress any key to continue." << endl;
    getch();
}
time_t convertDate(const string &dateStr)
{
    struct tm tm = {0};
    istringstream iss(dateStr);
    iss >> get_time(&tm, "%d-%m-%Y");
    return mktime(&tm);
}

void exitprog()
{
    system("cls");
    cout << "\n\n\n\n\n\n\n\n\n\n\t\t\t\tThank You for using our Blood Bank management system!\n\n\n\n\n\t\t\t\t\t\tProgrammed by:\n\n\t\t\t\t\t\tSajeel Tariq (CTAI-029)\n\t\t\t\t\t\tFaraz Ahmed (CTAI-028)\n\t\t\t\t\t\tFaisal Shahid (CTAI-011)\n\t\t\t\t\t\tHunaiza Khan (CTAI-007)\n\n\n\n\n\n"
         << endl;
    exit(0);
}

void showCompatibility(string grp)
{
    if (grp == "O+")
    {
        cout << "\nTry requesting for other compatible types for your blood group: O+ , O-";
    }
    else if (grp == "A+")
    {
        cout << "\nTry requesting for other compatible types for your blood group: O+ , O- , A+ , A-";
    }
    else if (grp == "A-")
    {
        cout << "\nTry requesting for other compatible types for your blood group: A- , O-";
    }
    else if (grp == "B+")
    {
        cout << "\nTry requesting for other compatible types for your blood group: O+ , O- , B+ , B-";
    }
    else if (grp == "B-")
    {
        cout << "\nTry requesting for other compatible types for your blood group: B- , O-";
    }
    else if (grp == "AB-")
    {
        cout << "\nTry requesting for other compatible types for your blood group: A- , B- , AB- , O-";
    }
}

#endif