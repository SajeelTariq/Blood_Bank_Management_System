#ifndef RECORDS_H
#define RECORDS_H
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

template <typename T>
class records
{
public:
    static void updatePassword(string oldpass)
    {
        string newpass, temppass, username;
        cout << "Enter new password: ";
        cin >> newpass;
        if (verification::checkPassword(newpass))
        {
            fstream myfile;
            myfile.open("citizen.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("!ERROR: Cannot open file.");
            }
            fstream temp;
            temp.open("temp.txt", ios::out);
            if (!temp)
            {
                throw runtime_error("!ERROR: Cannot open file.");
            }
            newpass = encryption(newpass);
            while (myfile >> username >> temppass)
            {
                oldpass = encryption(oldpass);
                if (temppass == oldpass)
                {
                    temppass = newpass;
                    temp << username << " " << temppass << endl;
                }
                else
                {
                    temp << username << " " << temppass << endl;
                }
            }
            myfile.close();
            temp.close();
            remove("citizen.txt");
            rename("temp.txt", "citizen.txt");
        }
    }

    static void input(T &c)
    {
        char gender;
        int age, pulse;
        float weight, hb, SBP, DBP;
        string name, blood_type, contact;
        cout << "\n\nEnter your Name: ";
        getline(cin, name);
        c.setname(name);
        cout << "Enter your Contact No.: ";
        getline(cin, contact);
        c.setcontact(contact);
        cout << "Enter your age (Range: 18-65): ";
        cin >> age;
        c.setage(age);
        cout << "Enter your gender (M/F): ";
        cin >> gender;
        c.setgender(gender);
        cout << "Enter your Weight in kg: ";
        cin >> weight;
        c.setweight(weight);
        cout << "Enter your blood type(A-,A+,B-,B+,AB-,AB+,O-,O+): ";
        cin >> blood_type;
        c.setbloodtype(blood_type);
        cout << "Enter your Hemoglobin Level (Range for 'M': 13-16 , Range for 'F': 12.5-19 ): ";
        cin >> hb;
        c.sethb(hb);
        cout << "Enter your pulse rate (Range: 50-100): ";
        cin >> pulse;
        c.setpulse(pulse);
        cout << "Enter your systolic Blood Pressure (Range:90-120): ";
        cin >> SBP;
        c.setsbp(SBP);
        cout << "Enter your diastolic Blood Pressure (Range:60-80): ";
        cin >> DBP;
        c.setdbp(DBP);
    }

    static void addData(int op, T &c)
    {
        if (op == 0)
        {
            bloodreserves::increasepackets(c.getbloodtype());
            int found = 0;
            string line;
            fstream myfile;
            myfile.open("donor.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("Cannot open file.");
            }
            while (!myfile.eof())
            {
                getline(myfile, line);
                if (line.find(c.getname()) != string::npos)
                {
                    found = 1;
                }
            }
            myfile.close();
            if (found == 1)
            {
                myfile.open("donor.txt", ios::in);
                if (!myfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                int foundflag = 0, delFlag = 0;
                fstream tempfile;
                tempfile.open("tempfile.txt", ios::out);
                if (!tempfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                while (getline(myfile, line))
                {
                    if (delFlag == 0)
                    {
                        if (line.find(c.getname()) != string::npos)
                        {
                            foundflag = 1;
                        }
                        if (foundflag == 0)
                        {
                            tempfile << line << endl;
                        }
                        if (foundflag == 1)
                        {
                            if (line.find("Donation") != string::npos)
                            {
                                delFlag = 1;
                            }
                        }
                    }
                    else
                    {
                        tempfile << line << endl;
                    }
                }
                tempfile << "Name: " << c.getname() << endl;
                tempfile << "Contact: " << c.getcontact() << endl;
                tempfile << "Age: " << c.getage() << endl;
                tempfile << "Gender: " << c.getgender() << endl;
                tempfile << "Weight: " << c.getweight() << endl;
                tempfile << "Blood type: " << c.getbloodtype() << endl;
                tempfile << "hb: " << c.gethb() << endl;
                tempfile << "Pulse rate: " << c.getpulserate() << endl;
                tempfile << "Systolic Blood Pressure: " << c.getsbp() << endl;
                tempfile << "Diastolic Blood Pressure: " << c.getdbp() << endl;
                time_t currentTime = time(nullptr);
                tm *localTime = localtime(&currentTime);
                char dateBuffer[11];
                strftime(dateBuffer, sizeof(dateBuffer), "%d-%m-%Y", localTime);
                tempfile << "Donation date: " << dateBuffer << endl;

                myfile.close();
                tempfile.close();
                remove("donor.txt");
                rename("tempfile.txt", "donor.txt");
            }
            else
            {
                myfile.open("donor.txt", ios::out | ios::app);
                if (!myfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                myfile << "Name: " << c.getname() << endl;
                myfile << "Contact: " << c.getcontact() << endl;
                myfile << "Age: " << c.getage() << endl;
                myfile << "Gender: " << c.getgender() << endl;
                myfile << "Weight: " << c.getweight() << endl;
                myfile << "Blood type: " << c.getbloodtype() << endl;
                myfile << "hb: " << c.gethb() << endl;
                myfile << "Pulse rate: " << c.getpulserate() << endl;
                myfile << "Systolic Blood Pressure: " << c.getsbp() << endl;
                myfile << "Diastolic Blood Pressure: " << c.getdbp() << endl;
                time_t currentTime = time(nullptr);
                tm *localTime = localtime(&currentTime);
                char dateBuffer[11];
                strftime(dateBuffer, sizeof(dateBuffer), "%d-%m-%Y", localTime);
                myfile << "Donation date: " << dateBuffer << endl;
                myfile.close();
            }
        }
        else
        {
            bloodreserves::decreasepackets(op, c.getbloodtype());
            int found = 0;
            fstream myfile;
            string line;
            myfile.open("reciever.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("Cannot open file.");
            }
            while (!myfile.eof())
            {
                getline(myfile, line);
                if (line.find(c.getname()) != string::npos)
                {
                    found = 1;
                }
            }
            myfile.close();
            if (found == 1)
            {
                myfile.open("reciever.txt", ios::in);
                if (!myfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                int foundflag = 0, delFlag = 0;
                fstream tempfile;
                tempfile.open("tempfile.txt", ios::out);
                if (!tempfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                while (getline(myfile, line))
                {
                    if (delFlag == 0)
                    {
                        if (line.find(c.getname()) != string::npos)
                        {
                            foundflag = 1;
                        }
                        if (foundflag == 0)
                        {
                            tempfile << line << endl;
                        }
                        if (foundflag == 1)
                        {
                            if (line.find("Recieving") != string::npos)
                            {
                                delFlag = 1;
                            }
                        }
                    }
                    else
                    {
                        tempfile << line << endl;
                    }
                }
                tempfile << "Name: " << c.getname() << endl;
                tempfile << "Contact: " << c.getcontact() << endl;
                tempfile << "Age: " << c.getage() << endl;
                tempfile << "Gender: " << c.getgender() << endl;
                tempfile << "Weight: " << c.getweight() << endl;
                tempfile << "Blood type: " << c.getbloodtype() << endl;
                tempfile << "hb: " << c.gethb() << endl;
                tempfile << "Pulse rate: " << c.getpulserate() << endl;
                tempfile << "Systolic Blood Pressure: " << c.getsbp() << endl;
                tempfile << "Diastolic Blood Pressure: " << c.getdbp() << endl;
                time_t currentTime = time(nullptr);
                tm *localTime = localtime(&currentTime);
                char dateBuffer[11];
                strftime(dateBuffer, sizeof(dateBuffer), "%d-%m-%Y", localTime);
                tempfile << "Recieving date: " << dateBuffer << endl;

                myfile.close();
                tempfile.close();
                remove("reciever.txt");
                rename("tempfile.txt", "reciever.txt");
            }
            else
            {
                myfile.open("reciever.txt", ios::out | ios::app);
                if (!myfile)
                {
                    throw runtime_error("Cannot open file.");
                }
                myfile << "Name: " << c.getname() << endl;
                myfile << "Contact: " << c.getcontact() << endl;
                myfile << "Age: " << c.getage() << endl;
                myfile << "Gender: " << c.getgender() << endl;
                myfile << "Weight: " << c.getweight() << endl;
                myfile << "Blood type: " << c.getbloodtype() << endl;
                myfile << "hb: " << c.gethb() << endl;
                myfile << "Pulse rate: " << c.getpulserate() << endl;
                myfile << "Systolic Blood Pressure: " << c.getsbp() << endl;
                myfile << "Diastolic Blood Pressure: " << c.getdbp() << endl;
                time_t currentTime = time(nullptr);
                tm *localTime = localtime(&currentTime);
                char dateBuffer[11];
                strftime(dateBuffer, sizeof(dateBuffer), "%d-%m-%Y", localTime);
                myfile << "Recieving date: " << dateBuffer << endl;
                myfile.close();
            }
        }
    }

    static void show()
    {
        string line;
        int showFlag = 0;
        fstream myfile;
        myfile.open("donor.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        cout << "\n\t\t\t---DATA OF DONORS---" << endl
             << endl;
        while (!myfile.eof())
        {
            showFlag = 1; // for exception
            getline(myfile, line);
            cout << line << endl;
            if (line.find("Donation") != string::npos)
            {
                cout << endl;
            }
        }
        cout << endl;
        myfile.close();
        myfile.open("reciever.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        cout << "\n\t\t\t---DATA OF RECIEVERS---" << endl
             << endl;
        while (!myfile.eof())
        {
            showFlag = 1; // for exception
            getline(myfile, line);
            cout << line << endl;
            if (line.find("Recieving") != string::npos)
            {
                cout << endl;
            }
        }
        if (showFlag == 0)
        {
            cout << "\n\t\t\tNO RECORDS IN THE FILES YET" << endl;
        }
        myfile.close();
    }

    static void search()
    {
        string name, line;
        int searchFlag = 0, flag = 0, searchflag2 = 0;
        ;
        cout << "Enter username to search: ";
        getline(cin, name);

        system("cls");
        fstream myfile;
        myfile.open("donor.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        while (!myfile.eof())
        {
            getline(myfile, line);
            if (line.find(name) != string::npos)
            {
                flag = 1;
                searchflag2 = 1;
                searchFlag = 1;
            }
            if (flag == 1)
            {
                cout << "\n\t\t\t---RECORD FOUND IN DONORS---" << endl
                     << endl;
                flag = 0;
            }
            if (searchFlag == 1)
            {
                cout << line << endl;
            }
            if (line.find("Donation") != string::npos)
            {
                searchFlag = 0;
            }
        }
        myfile.close();
        myfile.open("reciever.txt", ios::in);
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        if (!myfile)
        {
            throw runtime_error("Cannot open file.");
        }
        while (!myfile.eof())
        {
            getline(myfile, line);
            if (line.find(name) != string::npos)
            {
                flag = 1;
                searchflag2 = 1;
                searchFlag = 1;
            }
            if (flag == 1)
            {
                cout << "\n\t\t\t---RECORD FOUND IN RECIEVERS---" << endl
                     << endl;
                flag = 0;
            }
            if (searchFlag == 1)
            {
                cout << line << endl;
            }
            if (line.find("Recieving") != string::npos)
            {
                searchFlag = 0;
            }
        }
        if (searchflag2 == 0)
        {
            cout << "\n\t\t\tDATA WITH USERNAME " << name << " NOT FOUND" << endl;
        }
        myfile.close();
    }

    static void del()
    {
        string name, line;
        int delFlag = 0, foundflag = 0, foundflag2 = 0, op;
        system("cls");
        cout << "\n\t\t\tWhich Record you want to delete?" << endl;
        cout << "\n\t\t\t1)Donors\n\t\t\t2)Recievers" << endl;
        cout << "\t\t\tYour Choice: ";
        cin >> op;
        fflush(stdin);

        if (op == 1)
        {
            system("cls");
            cout << "Enter username to remove: ";
            cin >> name;
            fstream myfile;
            myfile.open("donor.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("Cannot open file.");
            }
            fstream tempfile;
            tempfile.open("tempfile.txt", ios::out);
            if (!tempfile)
            {
                throw runtime_error("Cannot open file.");
            }
            while (!myfile.eof())
            {
                getline(myfile, line);
                if (delFlag == 0)
                {
                    if (line.find(name) != string::npos)
                    {
                        foundflag = 1;
                        foundflag2 = 1;
                    }
                    if (foundflag == 0)
                    {
                        tempfile << line << endl;
                    }
                    if (foundflag == 1)
                    {
                        if (line.find("Donation") != string::npos)
                        {
                            delFlag = 1;
                        }
                    }
                }
                else
                {
                    tempfile << line << endl;
                }
            }
            if (foundflag2 == 0)
            {
                cout << "\n\t\t\tDATA WITH USERNAME " << name << " NOT FOUND" << endl;
            }
            else
            {
                cout << "\n\t\t\tDATA REMOVED SUCCESSFULLY" << endl;
            }
            myfile.close();
            tempfile.close();
            remove("donor.txt");
            rename("tempfile.txt", "donor.txt");
        }
        else if (op == 2)
        {

            system("cls");
            cout << "Enter username to remove: ";
            cin >> name;
            fstream myfile;
            myfile.open("donor.txt", ios::in);
            if (!myfile)
            {
                throw runtime_error("Cannot open file.");
            }
            fstream tempfile;
            tempfile.open("tempfile.txt", ios::out);
            if (!tempfile)
            {
                throw runtime_error("Cannot open file.");
            }
            while (!myfile.eof())
            {
                getline(myfile, line);
                if (delFlag == 0)
                {
                    if (line.find(name) != string::npos)
                    {
                        foundflag = 1;
                        foundflag2 = 1;
                    }
                    if (foundflag == 0)
                    {
                        tempfile << line << endl;
                    }
                    if (foundflag == 1)
                    {
                        if (line.find("Recieving") != string::npos)
                        {
                            delFlag = 1;
                        }
                    }
                }
                else
                {
                    tempfile << line << endl;
                }
            }
            if (foundflag2 == 0)
            {
                cout << "\n\t\t\tDATA WITH USERNAME " << name << " NOT FOUND" << endl;
            }
            else
            {
                cout << "\n\t\t\tDATA REMOVED SUCCESSFULLY" << endl;
            }
            myfile.close();
            tempfile.close();
            remove("reciever.txt");
            rename("tempfile.txt", "reciever.txt");
        }
        else
        {
            cout << "Invalid Option!" << endl;
            Beep(800, 1000);
            Sleep(2000);
        }
    }
};

#endif