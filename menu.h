#ifndef MENU_H
#define MENU_H
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
class menu
{
public:
     static void main_menu()
     {
          cout << "\n\n";
          cout << "\t\t\t====================================================" << endl;
          cout << "\t\t\t       WELCOME TO BLOOD BANK MANAGEMENT SYSTEM      " << endl;
          cout << "\t\t\t====================================================" << endl;
          cout << "\t\t\t||  1.Admin                                       ||" << endl;
          cout << "\t\t\t||  2.Citizen                                     ||" << endl;
          cout << "\t\t\t||  3.Hospital                                    ||" << endl;
          cout << "\t\t\t||  4.Exit                                        ||" << endl;
          cout << "\t\t\t||================================================||" << endl;
          cout << "\t\t\tEnter Your Choice: ";
     }

     static void admin_menu()
     {
          cout << "\n\n";
          
          cout << "\t\t\t=================================================" << endl;
          cout << "\t\t\t               ADMIN DASHBOARD                   " << endl;
          cout << "\t\t\t=================================================" << endl;
          cout << "\t\t\t||  1.See Records                              ||" << endl;
          cout << "\t\t\t||  2.Search Records                           ||" << endl;
          cout << "\t\t\t||  3.Remove Record                            ||" << endl;
          cout << "\t\t\t||  4.See blood reserves                       ||" << endl;
          cout << "\t\t\t||  5.Logout                                   ||" << endl;
          cout << "\t\t\t||=============================================||" << endl;
          cout << "\t\t\tEnter Your Choice: ";
     }

     static void citizen_menu()
     {
          cout << "\n\n";
          
          cout << "\t\t\t================================================================================" << endl;
          cout << "\t\t\t                                  CITIZEN MENU                                  " << endl;
          cout << "\t\t\t================================================================================" << endl;
          cout << "\t\t\t||  Welcome! Login if you have already registered otherwise select register   ||" << endl;
          cout << "\t\t\t||  1.Login                                                                   ||" << endl;
          cout << "\t\t\t||  2.Register                                                                ||" << endl;
          cout << "\t\t\t||  3.Go Back                                                                 ||" << endl;
          cout << "\t\t\t||============================================================================||" << endl;
          cout << "\t\t\tEnter Your Choice: ";
     }

     static void citizen_menu(string name)
     {
          cout << "\n\n";

          cout << "\t\t\t========================================================" << endl;
          cout << "\t\t\t                       WELCOME " << name << "               " << endl;
          cout << "\t\t\t========================================================" << endl;
          cout << "\t\t\t||  1.Donate Blood                                    ||" << endl;
          cout << "\t\t\t||  2.Request Blood                                   ||" << endl;
          cout << "\t\t\t||  3.Change Password                                 ||" << endl;
          cout << "\t\t\t||  4.Logout                                          ||" << endl;
          cout << "\t\t\t||====================================================||" << endl;
          cout << "\t\t\tEnter Your Choice: ";
     }

     static void hospital_menu(string name,bool temp)
     {
          cout << "\n\n";

          cout << "\t\t\t================================================================================" << endl;
          cout << "\t\t\t                          WELCOME " << name << " HOSPITAL                       " << endl;
          cout << "\t\t\t================================================================================" << endl;
          cout << "\t\t\t||Welcome! Login if you have already registered otherwise select register     ||" << endl;
          cout << "\t\t\t||  1.Update Emergency Status(Current Status: ";
          if (temp == false)
          {
               cout << "OFF";
          }
          else
          {
               cout << "ON";
          }
          cout << ")                             ||" << endl;
          cout << "\t\t\t||  2.Request Blood                                                           ||" << endl;
          cout << "\t\t\t||  3.Logout                                                                  ||" << endl;
          cout << "\t\t\t||============================================================================||" << endl;
          cout << "\t\t\tEnter Your Choice: ";
     }
};

#endif