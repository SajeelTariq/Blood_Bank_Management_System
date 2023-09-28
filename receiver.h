#ifndef RECIEVER_H
#define RECIEVER_H
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
#include "citizen.h"
#include "exception.h"

#define PI 3.141
#define encryptionvalue 10;

using namespace std;

class reciever : public citizen
{
public:
    int bloodPackets()
    {
        int amount;
        cout << "How many Blood Packets You Want? (1-5)";
        cin >> amount;
        if (amount < 1 || amount > 5)
        {
            throw BloodPacketException();
        }
        return amount;
    }
    bool checkLastRecieve()
    {
        int found = 0, current = 0;
        string line;
        fstream myfile;
        myfile.open("reciever.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: Cannot open file.");
        }
        while (!myfile.eof())
        {
            current++;
            getline(myfile, line);
            if (line.find(getname()) != string::npos)
            {
                found = 1;
                break;
            }
        }
        myfile.close();
        if (found == 1)
        {
            int target = current + 10;
            current = 0;
            string line, temp, temp2, filedate, currentdate;
            myfile.open("reciever.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("!ERROR: Cannot open file.");
            }
            while (1)
            {
                current++;
                if (current == target)
                {
                    myfile >> temp >> temp2 >> filedate;
                    break;
                }
                else
                {
                    getline(myfile, line);
                }
            }
            time_t targetTime = convertDate(filedate);
            time_t currentDate = time(nullptr);
            double diffInSeconds = difftime(currentDate, targetTime);
            double seconds56 = 7 * 24 * 60 * 60;
            if (diffInSeconds > seconds56)
            {
                return true;
            }
            else
            {
                cout << "SORRY YOU CAN NOT RECEIVE BLOOD, YOU HAVE TO WAIT 7 DAYS AFTER YOUR LAST RECEIPT" << endl;
                return false;
            }
            myfile.close();
        }
    }
};

#endif