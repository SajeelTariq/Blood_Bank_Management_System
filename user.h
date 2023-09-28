#ifndef USER_H
#define USER_H
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
class user
{
private:
    string username;
    string password;

public:
    user() : username(""), password("") {}
    user(string un, string pass) : username(un), password(pass) {}

    void set_username(string un) { username = un; }
    void set_password(string pass) { password = pass; }

    string get_username() { return username; }
    string get_password() { return password; }
};

#endif