#ifndef EXCEPTION_H
#define EXCEPTION_H
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

class BloodPacketException : public exception
{
public:
    const char *what() const throw()
    {
        return "!ERRORS: Invalid number of blood packets.";
        Beep(800, 1000);
    }
};

#endif