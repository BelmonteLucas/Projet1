///////////////////////////////////////////////////
// (c) SeA2019
// LINUX : Programme de test de la classe sRs232
//
// En mode TERMINAL shell : 
// Compilation : 	g++ sRs232.cpp exemple.cpp -o exemple
// Exécution : ./exemple
//////////////////////////////////////////////////

#include <iostream>
#include "sRs232.h"

using namespace std;

int main()
{
    string port = "/dev/ttyACM0";
    sRs232 *com = new sRs232(port);

    if (!com->Configurer(BPS4800, BIT8, PAS_DE_PARITE))
    {
        cout << com->getError() << endl;
        return 0;
    }

    while (1)
    {
        string lecture = com->Recevoir('$', SANS_FINAL);

        if (lecture[2] == 'G')
        {
            size_t pos1 = lecture.find(',');
            size_t pos2 = lecture.find(',', pos1 + 1);
            size_t pos3 = lecture.find(',', pos2 + 1);
            size_t pos4 = lecture.find(',', pos3 + 1);
			size_t pos5 = lecture.find(',', pos4 + 1);
			size_t pos6 = lecture.find(',', pos5 + 1);
			size_t pos7 = lecture.find(',', pos6 + 1);
			size_t pos8 = lecture.find(',', pos7 + 1);
			size_t pos9 = lecture.find(',', pos8 + 1);
			size_t pos10 = lecture.find(',', pos9 + 1);

            if (pos4 != string::npos)
            {
                string latitude = lecture.substr(pos2 + 1, pos3 - pos2 - 1);
                string longitude = lecture.substr(pos4 + 1, lecture.find(',', pos4 + 1) - pos4 - 1);
                string altitude = lecture.substr(pos9 + 1, pos10 - pos9 - 1);
                string satellites = lecture.substr(pos7 + 1, lecture.find(',', pos7 + 1) - pos7 - 1);

                cout << "Latitude: " << latitude << endl;
                cout << "Longitude: " << longitude << endl;
                cout << "Altitude: " << altitude <<  "M" << endl;
                cout << "Nombre de satellites: " << satellites << endl;
                cout << lecture << endl;
            }
        }
		        
        
        com->Envoyer("SNLED0");

        
        sleep(2);

        
        com->Envoyer("SNLED1");
		

        sleep(2);
    }

    delete com;
    return 0;
}
