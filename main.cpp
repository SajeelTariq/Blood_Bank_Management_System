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
#include "exception.h"
#include "bloodreserves.h"
#include "verification.h"
#include "user.h"
#include "admin.h"
#include "hospital.h"
#include "citizen.h"
#include "donor.h"
#include "receiver.h"
#include "transport.h"
#include "records.h"
#include "menu.h"

int main()
{
    system("cls");
    cout << "\n\n\n\n\t\t\t\t\t\t B L O O D  B A N K\n\n\t\t\t\t\t\t  M A N A G M E N T\n\n\t\t\t\t\t\t     S Y S T E M";
    cout << "\n\n\n\t\t\t\t\t\t     loading.";
    Sleep(700);
    cout << ".";
    Sleep(700);
    cout << ".";
    Sleep(700);
    cout << ".";

    int choice, op, op2, flag = 1, flag2 = 1, temp = 0;
    string username, password;
    admin Admin;
    citizen Citizen;
    donor Donor;
    reciever Reciever;
    hospital Hospital;
    Transport transport;

    while (1)
    {

        system("cls");
        menu::main_menu();
        cin >> choice;
        flag = 1, flag2 = 1;
        switch (choice)
        {
        case 1: // admin
        {
            system("cls");
            cout << "\t\t\t------------------- LOGIN ------------------" << endl;
            if (Admin.login())
            {
                while (flag == 1)
                {
                    system("cls");
                    menu::admin_menu();
                    cin >> op;
                    fflush(stdin);
                    switch (op)
                    {
                    case 1: // show records
                    {
                        try
                        {
                            system("cls");
                            records<citizen>::show();
                        }
                        catch (const exception &ex)
                        {
                            cout << ex.what() << endl;
                            Beep(800, 1000);
                        }
                        pressKey();
                        break;
                    }
                    case 2: // search records
                    {
                        try
                        {
                            system("cls");
                            records<citizen>::search();
                        }
                        catch (const exception &ex)
                        {
                            cout << ex.what() << endl;
                            Beep(800, 1000);
                        }
                        pressKey();
                        break;
                    }
                    case 3: // del record
                    {
                        try
                        {
                            system("cls");
                            records<citizen>::del();
                        }
                        catch (const exception &ex)
                        {
                            cout << ex.what() << endl;
                            Beep(800, 1000);
                        }
                        pressKey();
                        break;
                    }
                    case 4: // see blood reserves
                    {
                        try
                        {
                            system("cls");
                            bloodreserves::seeBloodPackets();
                        }
                        catch (const exception &ex)
                        {
                            cout << ex.what() << endl;
                            Beep(800, 1000);
                        }
                        pressKey();
                        break;
                    }
                    case 5: // logout
                    {
                        system("cls");
                        flag = 0;
                        cout << "\n\n\n\t\t\t\tLOGGING OUT...." << endl;
                        Sleep(3000);
                        break;
                    }
                    default:
                    {
                        cout << "\n\t\t\t!ERROR: Invalid Option!Please Enter again" << endl;
                        Beep(800, 1000);
                        Sleep(2000);
                    }
                    }
                }
            }
            else
            {
                cout << "\n\t\t\tIncorrect Username or Password" << endl;
                Beep(800, 1000);
                Sleep(3000);
            }
            break;
        }

        case 2: // citizen
        {
            while (flag == 1)
            {
                system("cls");
                menu::citizen_menu();
                cin >> op;
                fflush(stdin);
                switch (op)
                {
                case 2: // register
                {
                    try
                    {
                        system("cls");
                        cout << "\t\t\t---------------- REGISTRATION ---------------" << endl;
                        Citizen.registration();
                        cout << "\n\t\t\tRegistration Successful" << endl;
                    }
                    catch (const exception &ex)
                    {
                        cout << ex.what() << endl;
                        Beep(800, 1000);
                    }
                    Sleep(2500);
                    break;
                }
                case 1: // login
                {
                    system("cls");
                    cout << "\t\t\t------------------- LOGGIN ------------------" << endl;
                    try
                    {
                        if (Citizen.login())
                        {
                            while (flag2 == 1)
                            {

                                system("cls");
                                menu::citizen_menu(Citizen.get_username());
                                cin >> op2;
                                fflush(stdin);
                                switch (op2)
                                {
                                case 1: // donate
                                {
                                    system("cls");
                                    records<donor>::input(Donor);
                                    try
                                    {
                                        if (Donor.CheckDonorHealthProfile() && Donor.checkLastDonate())
                                        {
                                            records<donor>::addData(0, Donor);
                                            cout << "\n\t\t\tThanks for comming you have successfully donated the blood" << endl;
                                        }
                                    }
                                    catch (const exception &ex)
                                    {
                                        cout << ex.what() << endl;
                                        Beep(800, 1000);
                                    }
                                    pressKey();
                                    break;
                                }
                                case 2: // order
                                {
                                    system("cls");
                                    records<reciever>::input(Reciever);
                                    try
                                    {
                                        if (Reciever.checkLastRecieve())
                                        {
                                            int packets;
                                            packets = Reciever.bloodPackets();
                                            records<reciever>::addData(packets, Reciever);
                                            cout << "\n\t\t\tThanks for comming your order has been recorded" << endl;
                                        }
                                    }
                                    catch (const char *msg)
                                    {

                                        cout << "\t\t\t" << msg << endl;
                                        showCompatibility(Reciever.getbloodtype());
                                        Sleep(2500);
                                    }
                                    catch (const exception &ex)
                                    {
                                        cout << ex.what() << endl;
                                        Beep(800, 1000);
                                    }
                                    pressKey();
                                    break;
                                }
                                case 3: // change pass
                                {
                                    system("cls");
                                    cout << "\t\t\t---------------- CHANGE PASSWORD ---------------" << endl;
                                    try
                                    {
                                        records<citizen>::updatePassword(Citizen.get_password());
                                        cout << "\n\t\t\tPassword changed successfully" << endl;
                                    }
                                    catch (const exception &ex)
                                    {
                                        cout << ex.what() << endl;
                                        Beep(800, 1000);
                                    }
                                    pressKey();
                                    break;
                                }
                                case 4: // logout
                                {
                                    system("cls");
                                    flag2 = 0;
                                    cout << "\n\n\n\t\t\t\tLOGGING OUT...." << endl;
                                    Sleep(3000);
                                    break;
                                }
                                default:
                                {
                                    cout << "\n\t\t\t!ERROR: Invalid Option!Please Enter again" << endl;
                                    Beep(800, 1000);
                                    Sleep(2000);
                                }
                                }
                            }
                        }
                    }
                    catch (const exception &ex)
                    {
                        cout << ex.what() << endl;
                    }
                    break;
                }
                case 3: // goback
                {
                    system("cls");
                    flag = 0;
                    break;
                }
                default:
                {
                    cout << "\n\t\t\t!ERROR: Invalid Option!Please Enter again" << endl;
                    Beep(800, 1000);
                    Sleep(2000);
                }
                }
            }
            break;
        }

        case 3: // hospital
        {
            system("cls");
            cout << "\t\t\t------------------- LOGIN ------------------" << endl;
            try
            {
                if (Hospital.login())
                {
                    while (flag == 1)
                    {

                        system("cls");
                        menu::hospital_menu(Hospital.get_username(),Hospital.getEmergencyStatus());
                        cin >> op;
                        fflush(stdin);
                        switch (op)
                        {
                        case 1: // Update emergency status
                            system("cls");
                            cout << "\n\nAll your orders are made according to respective Emergency Status. By default, the status is set OFF upon login\n";
                            cout << "\n\nIf you wish to Switch it ON, enter 1. If you wish to Switch it OFF, enter 0\n";
                            cout << "(If you accidentally enter anything other than 1 and 0, your previous emergency status will be retained unless you log out)\n";
                            cout << "\n\nYour current Emergency Status is ";
                            if (Hospital.getEmergencyStatus() == 1)
                            {
                                cout << "ON";
                            }
                            else
                            {
                                cout << "OFF";
                            }
                            cout << "\nSwitch ON/OFF Emergency Status :  ";
                            cin >> temp;
                            Hospital.setEmergencyStatus(temp);
                            break;
                        case 2: // order
                        {
                            system("cls");
                            try
                            {
                                Hospital.orderBlood();
                                cout << "\n\t\t\tThanks for comming your order has been recorded" << endl;
                                transport.dispatchOrder(Hospital);
                                Sleep(5000);
                            }
                            catch (const char *msg)
                            {
                                cout << "\t\t\t" << msg << endl;
                                showCompatibility(Hospital.getrequiredBloodGroup());
                                Sleep(2500);
                            }
                            catch (const exception &ex)
                            {
                                cout << ex.what() << endl;
                                Beep(800, 1000);
                            }
                            pressKey();
                            break;
                        }
                        case 3:
                        {
                            system("cls");
                            flag = 0;
                            cout << "\n\n\n\t\t\t\tLOGGING OUT...." << endl;
                            Sleep(3000);
                            break;
                        }
                        default:
                        {
                            cout << "\n\t\t\t!ERROR: Invalid Option!Please Enter again" << endl;
                            Beep(800, 1000);
                            Sleep(2000);
                        }
                        }
                    }
                }
            }
            catch (const exception &ex)
            {
                cout << ex.what() << endl;
            }
            break;
        }
        case 4:
        {
            exitprog();
        }
        default:
        {
            cout << "\n\t\t\t!ERROR: Invalid Option!Please Enter again" << endl;
            Beep(800, 1000);
            Sleep(2000);
        }
        }
    }
}