#ifndef VERIFICATION_H
#define VERIFICATION_H
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
#include "extrafunctions.h"

#define PI 3.141
#define encryptionvalue 10;

using namespace std;

class verification
{
public:
    static bool checkPassword(string pass)
    {

        string tempPass;
        fstream myfile;
        myfile.open("citizen.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: Cannot open file.");
        }
        while (!myfile.eof())
        {
            myfile >> tempPass;
            tempPass = decryption(tempPass);
            if (tempPass == pass)
            {
                return false;
            }
        }
        return true;
    }

    static bool checkUsername(string user)
    {
        string tempUser;
        fstream myfile;
        myfile.open("citizen.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: Cannot open file.");
        }
        while (!myfile.eof())
        {
            myfile >> tempUser;
            if (tempUser == user)
            {
                return false;
            }
        }
        return true;
    }
};

#endif