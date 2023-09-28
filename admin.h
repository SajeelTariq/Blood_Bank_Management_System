#ifndef ADMIN_H
#define ADMIN_H
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
#include "extrafunctions.h"
#define PI 3.141
#define encryptionvalue 10;

using namespace std;
class admin : public user
{
public:
    admin()
    {
        set_username("admin");
        set_password("fWii");
    }
    admin(string un, string pass) : user(un, pass) {}

    bool login()
    {
        string un, pass;
        cout << "\t\t\tEnter Username: ";
        cin >> un;
        cout << "\n\t\t\tEnter Password: ";
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

        if (get_username() == un && get_password() == pass)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif