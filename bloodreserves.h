#ifndef BLOODRESERVES_H
#define BLOODRESERVES_H
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
class bloodreserves
{
public:
    static void seeBloodPackets()
    {
        vector<string> bloods;
        string temp;
        fstream myfile;
        myfile.open("blood.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: File not found.");
            Beep(800, 1000);
        }
        while (!myfile.eof())
        {
            myfile >> temp;
            bloods.push_back(temp);
        }

        cout << "Group A-   =  " << bloods[0] << endl;
        cout << "Group A+   =  " << bloods[1] << endl;
        cout << "Group B-   =  " << bloods[2] << endl;
        cout << "Group B+   =  " << bloods[3] << endl;
        cout << "Group AB-  =  " << bloods[4] << endl;
        cout << "Group AB+  =  " << bloods[5] << endl;
        cout << "Group O-   =  " << bloods[6] << endl;
        cout << "Group O+   =  " << bloods[7] << endl;
    }
    static void increasepackets(string type)
    {
        string blood;
        fstream myfile;
        myfile.open("blood.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: File not found.");
            Beep(800, 1000);
        }
        fstream temp;
        temp.open("temp.txt", ios::out);
        if (!temp)
        {
            throw runtime_error("!ERROR: File not found.");
            Beep(800, 1000);
        }
        int var, target, current = 0;
        if (type == "A-" || type == "a-")
        {
            target = 1;
        }
        else if (type == "A+" || type == "a+")
        {
            target = 2;
        }
        else if (type == "B-" || type == "b-")
        {
            target = 3;
        }
        else if (type == "B+" || type == "b+")
        {
            target = 4;
        }
        else if (type == "AB-" || type == "ab-")
        {
            target = 5;
        }
        else if (type == "AB+" || type == "ab+")
        {
            target = 6;
        }
        else if (type == "O-" || type == "o-")
        {
            target = 7;
        }
        else
        {
            target = 8;
        }
        while (!myfile.eof())
        {
            getline(myfile, blood);
            current++;
            if (current == target)
            {
                var = stoi(blood);
                var++;
                temp << var << endl;
            }
            else
            {
                temp << blood << endl;
            }
        }
        myfile.close();
        temp.close();
        remove("blood.txt");
        rename("temp.txt", "blood.txt");
    }

    static void decreasepackets(int num, string type)
    {
        string blood;
        fstream myfile;
        myfile.open("blood.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("!ERROR: Cannot open file.");
            Beep(800, 1000);
        }
        fstream temp;
        temp.open("temp.txt", ios::out);
        if (!temp)
        {
            throw runtime_error("!ERROR: Cannot open file.");
            Beep(800, 1000);
        }
        int var, target, current = 0;
        if (type == "A-" || type == "a-")
        {
            target = 1;
        }
        else if (type == "A+" || type == "a+")
        {
            target = 2;
        }
        else if (type == "B-" || type == "b-")
        {
            target = 3;
        }
        else if (type == "B+" || type == "b+")
        {
            target = 4;
        }
        else if (type == "AB-" || type == "ab-")
        {
            target = 5;
        }
        else if (type == "AB+" || type == "ab+")
        {
            target = 6;
        }
        else if (type == "O-" || type == "o-")
        {
            target = 7;
        }
        else
        {
            target = 8;
        }
        while (!myfile.eof())
        {
            getline(myfile, blood);
            current++;
            if (current == target)
            {
                var = stoi(blood);
                if (var < num)
                {
                    throw "SORRY WE DO NOT HAVE ENOUGH PACKETS OF THE BLOOD GROUP YOU WANT";
                }
                else
                {
                    var = var - num;
                }
                temp << var << endl;
            }
            else
            {
                temp << blood << endl;
            }
        }
        myfile.close();
        temp.close();
        remove("blood.txt");
        rename("temp.txt", "blood.txt");
    }
};

#endif