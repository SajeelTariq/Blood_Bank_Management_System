#ifndef HOSPITAL_H
#define HOSPITAL_H
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
#include "user.h"
#include "exception.h"
#include "extrafunctions.h"
#include "bloodreserves.h"

#define PI 3.141
#define encryptionvalue 10;

using namespace std;
class hospital : public user
{
    string requiredBloodGroup;
    long double latitude, longitude;
    bool EmergencyStatus;

public:
    hospital()
    {
        latitude = 0;
        longitude = 0;
        EmergencyStatus = false;
    }
    void setLocation(string name)
    {
        if (name == "Indus")
        {
            latitude = 75.31152343750001;
            longitude = 30.123472222;
        }
        else if (name == "Liaquat")
        {
            latitude = 70.31152343750001;
            longitude = 31.123472222;
        }
        else if (name == "Dow")
        {
            latitude = 50.31152343750001;
            longitude = 21.123472222;
        }
        EmergencyStatus = false;
    }

    long double getLat() { return latitude; }
    long double getLong() { return longitude; }
    string getrequiredBloodGroup() { return requiredBloodGroup; }
    void setrequiredBloodGroup(string s) { requiredBloodGroup = s; }
    bool getEmergencyStatus() { return EmergencyStatus; }
    void setEmergencyStatus(bool EmergencyStatus)
    {
        if (EmergencyStatus == 0 || EmergencyStatus == 1)
        {
            this->EmergencyStatus = EmergencyStatus;
        }
    }

    bool login()
    {
        int flag = 0;
        string user, pass, cuser, cpass;
        system("cls");
        cout << "\n\n\t\t\tLOGIN ";
        cout << "\n\t\t\t-----";
        cout << "\n\n\t\t\tUSERNAME :";
        cin >> user;
        set_username(user);
        cout << "\n\t\t\tPASSWORD :";
        char ch;
        while (true)
        {
            ch = _getch();
            if (ch == '\r')
                break;
            if (ch == '\b' && !pass.empty())
            {
                pass.pop_back();
                cout << "\b \b";
            }
            else
            {
                pass.push_back(ch);
                cout << '*';
            }
        }
        pass = encryption(pass);
        set_password(pass);

        fstream input;
        input.open("hospital.txt", ios::in);
        while (input >> cuser >> cpass)
        {
            if (cuser == get_username() && cpass == get_password())
            {
                flag = 1;
                cout << "\n\n\t\t\tLogging In...";
                Sleep(1000);
                system("cls");
            }
        }
        input.close();

        if (flag == 1)
        {

            return true;
        }
        else
        {
            Beep(800, 1000);
            cout << "\n\n\t\t\tIncorrect Username or Password (We only have contracts with Liaquat, Indus and Dow Hospital)" << endl;
            Sleep(2500);
            return false;
        }
    }

    void orderBlood()
    {
        string type;
        int packets;
        cout << "\n\t\t\tEnter the Blood Group you want: ";
        cin >> type;
        setrequiredBloodGroup(type);
        cout << "\t\t\tEnter Number of Packets you want (1-10): ";
        cin >> packets;
        if (packets < 0 || packets > 10)
        {
            throw BloodPacketException();
            Beep(800, 1000);
        }
        bloodreserves::decreasepackets(packets, type);
    }
};

#endif