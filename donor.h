#ifndef DONOR_H
#define DONOR_H
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
#define PI 3.141
#define encryptionvalue 10;

using namespace std;
class donor : public citizen
{
public:
    bool CheckDonorHealthProfile()
    {
        int criteria = 0;
        if (getgender() == 'F' || getgender() == 'f')
        {
            if (gethb() >= 12.5 && gethb() <= 19.0)
                criteria++;
        }
        else if (getgender() == 'M' || getgender() == 'm')
        {
            if (gethb() >= 13.0 && gethb() <= 16.0)
                criteria++;
        }
        if (getweight() > 45)
            criteria++;

        if (getpulserate() >= 50 && getpulserate() <= 100)
            criteria++;

        if (getage() >= 18 && getage() <= 65)
            criteria++;

        if (getdbp() < 80 && getdbp() > 60)
            criteria++;
        if (criteria == 5)
        {
            cout << "\n\t\t\tYOUR HEALTH PROFILE HAS BEEN VERIFIED SUCCESSFULLY\n";
            Sleep(1500);
            return true;
        }
        else
        {
            cout << "\n\t\t\tWE REGRET TO INFORM YOU THAT YOUR HEALTH PROFILE HAS NOT BEEN VERIFIED\n";

            Sleep(1500);
            return false;
        }
    }
    bool checkLastDonate()
    {
        int found = 0, current = 0;
        string line;
        fstream myfile;
        myfile.open("donor.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: Cannot open file.");
            Beep(800, 1000);
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
            myfile.open("donor.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("!ERROR: Cannot open file.");
                Beep(800, 1000);
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
            double seconds56 = 56 * 24 * 60 * 60;
            if (diffInSeconds > seconds56)
            {
                return true;
            }
            else
            {
                cout << "SORRY YOU CAN NOT DONATE BLOOD, YOU HAVE TO WAIT 58 DAYS AFTER YOUR LAST DONATION" << endl;
                return false;
            }
            myfile.close();
        }
    }
};

#endif