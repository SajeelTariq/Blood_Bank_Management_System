#ifndef TRANSPORT_H
#define TRANSPORT_H
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
#include "hospital.h"
#define PI 3.141
#define encryptionvalue 10;

using namespace std;

class Transport
{
    string branchCity[3];
    long double latitude[3], longitude[3];

    long double getdistance(long double lat1, long double long1, long double lat2, long double long2)
    {
        lat1 = ((PI) / 180) * lat1;   // Convert the latitudes
        long1 = ((PI) / 180) * long1; // and longitudes
        lat2 = ((PI) / 180) * lat2;   // from degree to radians.
        long2 = ((PI) / 180) * long2;

        // Haversine Formula
        long double ans = pow(sin((lat2 - lat1) / 2), 2) + cos(lat1) * cos(lat2) * pow(sin((long2 - long1) / 2), 2);
        ans = 2 * asin(sqrt(ans)) * 6371; // Radius of Earth=6371 km
        return ans;
    }
    void EmergencyTransport(hospital &h)
    {
        int temp = 0;
        long double minDistance = 100000;
        for (int i = 0; i < 3; i++)
        {
            if (getdistance(latitude[i], longitude[i], h.getLat(), h.getLong()) < minDistance)
            {
                minDistance = getdistance(latitude[i], longitude[i], h.getLat(), h.getLong());
                temp = i;
            }
        }
        cout << "\n\nEmergency Detected: You will soon be receiving your order from our nearest branch in " << branchCity[temp] << ".\n";
    }

public:
    Transport()
    {
        latitude[0] = 30.3308401;
        longitude[0] = 71.247499;
        branchCity[0] = "Multan";
        latitude[1] = 24.856534339310674;
        longitude[1] = 66.99462890625001;
        branchCity[1] = "Karachi";
        latitude[2] = 31.541089879585837;
        longitude[2] = 74.31152343750001;
        branchCity[2] = "Lahore";
    }
    void dispatchOrder(hospital &h)
    {
        if (h.getEmergencyStatus() == true)
            EmergencyTransport(h);
        else
            cout << "\n\nOur Transport Service has been Notified about your order. We appreciate your patience till they contact you.\n";
    }
};

#endif