/*
*
*  Realizacja algorytmu Schrage z podzialem
*    bez kopcow
*
*/



#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <string.h>

#include <ctime>


#include "rpq.h"
#include "schrage.h"






//---------------------------------------------------------------------------
int main()
{
   long int t;
   
   float suma=0;

   LARGE_INTEGER clockFreq;
   QueryPerformanceFrequency(&clockFreq);

   LARGE_INTEGER TimeStart;
   LARGE_INTEGER TimeEnd;
   LARGE_INTEGER diff;          //r??nica czasu


   vector<proces> tabN;
   vector<proces> tabG;

   string tablica[] = {"data.000.txt", "data.001.txt", "data.002.txt", "data.003.txt", "data.004.txt", "data.005.txt", "data.006.txt", "data.007.txt", "data.008.txt"};

   //wczytanie danych o procesach do wektora proces?w
   fstream plik;

   //zapisywanie danych
   fstream plikWyj;
   plikWyj.open("wyniki_z_podzialem.txt", fstream::out);

   for ( int i=0; i < 9; ++i )
   {
    const char *nazwa_pliku = tablica[i].c_str();


    int ile=0;
    proces proc;
    plik.open(nazwa_pliku, fstream::in);
    if(plik.is_open()) {
        plik >> ile;

        for(int i = 0; i < ile; i++)
        {
            proc.j = i+1;
            plik >> proc.r;
            plik >> proc.p;
            plik >> proc.q;
            tabN.push_back(proc);
        }
    }
    plik.close();



    QueryPerformanceCounter(&TimeStart);

    // wywo?anie alg Schrage
    t  = Schrage(tabN, tabG);

    QueryPerformanceCounter(&TimeEnd);

    diff.QuadPart = TimeEnd.QuadPart - TimeStart.QuadPart;

    // zmierzony czas
    float diffTime = ( (float)diff.QuadPart ) / clockFreq.QuadPart;

	suma += diffTime;

    cout    << nazwa_pliku << "\tCmax: " << t <<"\tczas wykonania: " << diffTime << endl;
	plikWyj << nazwa_pliku << "\tCmax: " << t <<"\tczas wykonania: " << diffTime << endl;
	
	
	
    //usuniecie
    while (!tabN.empty()) {
       tabN.pop_back();
    }

    while (!tabG.empty()) {
       tabG.pop_back();
    }
   }
   
   plikWyj << "Calkowity czas wykonania: " << suma << endl;
   plikWyj.close();
   system("pause");

   return 0;
}
//---------------------------------------------------------------------------





